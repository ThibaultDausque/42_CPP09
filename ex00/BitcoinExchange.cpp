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
	for (size_t t = 0; t < date.size(); t++)
	{
		for (size_t u = t + 1; date[u] && date[u] != '-'; u++)
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
	}
	return 1;
}

void	BitcoinExchange::parseInput(std::string& file)
{
	std::ifstream	input(file);
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
		std::cout << line << std::endl;
		idx++;
	}
	input.close();
	return ;
}

