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
		len = t;
	if (len != 9 || (date[4] != '-' && date[7] != '-'))
	{
		std::cout << RED << DATE << std::endl;
		return 0;
	}
	for (int i = 0; i < 3; i++)
	{
		if (!isdigit(date[i]))
		{
			std::cout << RED << DATE << std::endl;
			return 0;
		}
	}
	if (!isdigit(date[5]) && !isdigit(date[6]))
	{
		std::cout << RED << DATE << std::endl;
		return 0;
	}
	if (!isdigit(date[8]) && !isdigit(date[9]))
	{
		std::cout << RED << DATE << std::endl;
		return 0;
	}
	return len;
}

int	BitcoinExchange::inputFileForm(std::string& line)
{
	int		pos;
	int		pos_bis;
	int		count;

	pos = dateForm(line);
	if (!pos)
	{
		std::cout << RED << "KO";
		return 0;
	}
	if (line[pos + 1] != ' ' || line[pos + 2] != '|' || line[pos + 1] == '\0')
	{
		std::cout << RED << FORMAT << std::endl;
		std::cout << RED << "KO";
		return 0;
	}
	pos_bis = pos + 2;
	count = 0;
	if (line[pos_bis] ==  '|')
	{
		while (!isdigit(line[pos_bis]))
		{
			if (line[pos_bis] == ' ')
				count++;
			
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
		else if (idx == 0)
			std::cout << line << std::endl;
		if (idx > 0)
		{
			if (line.empty())
			{
				std::cout << line << std::endl;
				continue ;
			}
			inputFileForm(line);
			std:: cout << " >> " << line << std::endl;
		}
		idx++;
	}
	input.close();
	return ;
}

