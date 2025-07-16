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

int	BitcoinExchange::dateForm(std::string& date, t_data& data)
{
	int		len;
	std::string	year;
	std::string	month;
	std::string	day;

	for (size_t t = 0; date[t] && date[t] != ' '; t++)
		len = t;
	if (len != 9 || (date[4] != '-' && date[7] != '-'))
	{
		std::cout << RED << DATE << std::endl;
		return 0;
	}
	year = date.substr(0, 4);
	if (atoi(year.c_str()) < 2009 || atoi(year.c_str()) > 2022)
	{
		std::cout << RED << YEAR << std::endl;
		return 0;
	}
	month = date.substr(5, 6);
	if (atoi(month.c_str()) < 1 || atoi(month.c_str()) > 12)
	{
		std::cout << RED << MONTH << std::endl;
		return 0;
	}
	day = date.substr(8, 9);
	if (atoi(day.c_str()) < 1 || atoi(day.c_str()) > 31)
	{
		std::cout << RED << MONTH << std::endl;
		return 0;
	}
	data.time = date.substr(0, 10);
	return len;
}

int	BitcoinExchange::inputFileForm(std::string& line, t_data& data)
{
	int		pos;
	int		pos_bis;
	int		count;
	std::string	value;

	pos = dateForm(line, data);
	if (!pos)
		return 0;
	if (line[pos + 1] != ' ' || line[pos + 2] != '|' || line[pos + 1] == '\0')
	{
		std::cout << RED << FORMAT << std::endl;
		return 0;
	}
	pos_bis = pos + 2;
	count = 0;
	if (line[pos_bis] ==  '|')
	{
		if (line[++pos_bis] != ' ')
		{
			std::cout << RED << DATEVALUE << std::endl;
			return 0;
		}
		if (isdigit(line[++pos_bis]))
		{
			value = line.substr(pos_bis, line.size());
			for (size_t i = 0; i < value.size(); i++)
			{
				if (value[i] == '.')
				{
					count++;
					continue ;
				}
				if (value[i] < '0' || value[i] > '9' || count > 1)
				{
					std::cout << RED << VALUE << std::endl;
					return 0;
				}
			}
			if (atof(value.c_str()) < 0 || atof(value.c_str()) > 1000)
			{
				std::cout << RED << VALUE << std::endl;
				return 0;
			}
			data.value = atof(value.c_str());
		}
		else
		{
			std::cout << RED << VALUE << std::endl;
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
	t_data			data;

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
			if (inputFileForm(line, data))
			{
				_btc[data.time] = data.value;
				std::cout << " >> " << data.time << " | " << _btc[data.time] << std::endl;
			}
			else
				std::cout << "KO >> " << line << std::endl;
		}
		idx++;
	}
	input.close();
	return ;
}

void	BitcoinExchange::parseData(std::string &file)
{
	std::ifstream	data(file.c_str());
	std::string		line;
	std::string		date;
	std::string		value;
	int				idx;

	if (!data.is_open())
	{
		std::cerr << RED << OPEN << std::endl;
		return ;
	}
	idx = 0;
	while (std::getline(data, line))
	{
		if (idx == 0)
		{
			idx++;
			continue ;
		}
		date = line.substr(0, 10);
		value = line.substr(12, line.size());
		_csv[date] = atof(value.c_str());
		std::cout << date << " >> " << _csv[date] << std::endl;
		idx++;
	}
	return ;
}

