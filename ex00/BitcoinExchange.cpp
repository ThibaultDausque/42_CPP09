#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& cpy)
{
	*this = cpy;
}

BitcoinExchange::~BitcoinExchange()
{

}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& src)
{
	if (this != &src)
		this->_btc = src._btc;
	return *this;
}

int	BitcoinExchange::dateForm(std::string& date)
{
	int		len;

	for (size_t t = 0; date[t] && date[t] != ' '; t++)
	{
		for (size_t u = t + 1; date[u] && date[u] != ' ' && date[u] != '-'; u++)
		{
			if (date[u] < '0' || date[u] > '9')
			{
				return 0;
			}
		}
		if(date[t] == '-' && date[t + 1] == '-')
		{
			return 0;
		}
		len = t;
	}
	return len;
}

int	BitcoinExchange::inputFileForm(std::string& line)
{
	int		count;
	int		found;

	if (!dateForm(line))
	{
		std::cerr << RED << DATE << std::endl;
		return 0;
	}
	count = 0;
	for (int i = dateForm(line) + 1; line[i] && line[i] != '|'; i++)
	{
		if (line[i] == ' ')
			count++;
		if (count > 1 || line[i] == '\0')
		{
			std::cout << RED << "KO";
			return 0;
		}
	}
	found = line.find("|");
	if (!found)
		std::cout << RED << "KO";
	for (int j = found + 1; line[j] && line[j] == ' '; j++)
	{
		if (line[j] == ' ')
			count++;
		if (count > 2 || line[j] == '\0')
		{
			std::cout << RED << "KO";
			return 0;
		}
	}
	count = 0;
	for (int k = line.size(); std::isdigit(line[k]) && k != 0; k--)
	{
		if (line[k] == '.')
		{
			count++;
			continue ;
		}
		if (count > 2 || k == 0)
		{
			std::cout << RED << "KO";
			return 0;
		}
	}
	std::cout << GREEN << "OK";
	return 1;
}

void	BitcoinExchange::parseInput(std::string& file)
{
	std::ifstream	input(file.c_str());
	std::string		line;
	int				idx;

	if (!input.is_open())
	{
		std::cerr << RED << OPEN << std::endl;
		return ;
	}
	idx = 0;
	while (std::getline(input, line))
	{
		if (idx == 0 && line != "date | value")
		{
			std::cerr << RED << DATEVALUE << std::endl;
			return ;
		}
		// if (dateForm(line))
		// {
		// 	std::string	date = line.substr(0, dateForm(line) + 1);
		// 	std::cout << date << std::endl;
		// }
		inputFileForm(line);
		std:: cout << " >> " << line << std::endl;
		idx++;
	}
	input.close();
	return ;
}

