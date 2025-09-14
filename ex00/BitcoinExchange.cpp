#include "BitcoinExchange.hpp"
#include "message.hpp"

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

static bool leapYear(int year)
{
	return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

static time_t toTimestamp(const std::string &date)
{
	struct tm tm;

	tm.tm_year = atoi(date.substr(0, 4).c_str()) - 1900;
	tm.tm_mon = atoi(date.substr(5, 2).c_str()) - 1;
	tm.tm_mday = atoi(date.substr(8, 2).c_str());
	tm.tm_hour = 0;
	tm.tm_min = 0;
	tm.tm_sec = 0;
	tm.tm_isdst = false;
	return (mktime(&tm));
}

void	BitcoinExchange::nearDate(const std::string txt_year)
{
	std::ifstream	data("data.csv");
	std::string		line;
	std::string		year;
	std::string		delta_year;
	double			delta;
	double			min;
	float			value;
	int				i;

	i = 0;
	while (std::getline(data, line))
	{
		year = line.substr(0, 10);
		if (i == 0)
		{
			i++;
			continue ;
		}
		else if (i == 1)
		{
			delta = fabs(difftime(toTimestamp(year), toTimestamp(txt_year)));
			min = delta;
		}
		delta = fabs(difftime(toTimestamp(year), toTimestamp(txt_year)));
		if (delta < min)
		{
			min = delta;
			delta_year = year;
		}
		i++;
	}
	value = _csv[delta_year] * _btc[txt_year];
	std::cout << WHITE << txt_year << " => "
			<< _btc[txt_year] << " = " << value << std::endl;
	data.close();
	return ;
}

static bool	validDate(std::string day, std::string month, std::string year)
{
	int		is_year = 0;
	int		is_month = 0;
	int		is_day = 0;

	is_year = atoi(year.c_str());
	is_month = atoi(month.c_str());
	is_day = atoi(day.c_str());
	if (!is_month || is_month > 12 || !is_day || is_day > 31 || (is_month == 2 && is_day > 29))
		return (false);
	else if (is_month != 1 && is_month != 3 && is_month != 5 && is_month != 7 && is_month != 8 && is_month != 10 && is_month != 12 && is_day == 31)
		return (false);
	else if (is_month == 2 && is_day == 29 && !leapYear(is_year))
		return (false);
	return (true);
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
	if (atoi(year.c_str()) <= 0 || atoi(year.c_str()) > 9999)
	{
		std::cout << RED << YEAR << std::endl;
		return 0;
	}
	month = date.substr(5, 2);
	if (atoi(month.c_str()) < 1 || atoi(month.c_str()) > 12)
	{
		std::cout << RED << MONTH << std::endl;
		return 0;
	}
	day = date.substr(8, 2);
	if (atoi(day.c_str()) < 1 || atoi(day.c_str()) > 31)
	{
		std::cout << RED << DAY << std::endl;
		return 0;
	}
	if (!validDate(day, month, year))
	{
		std::cout << RED << VALID << std::endl;
		return 0;
	}
	data.time = date.substr(0, 10);
	return len;
}

float	BitcoinExchange::inputFileForm(std::string& line, t_data &data)
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
		std::cerr << RED << FORMAT << std::endl;
		return 0;
	}
	pos_bis = pos + 2;
	count = 0;
	if (line[pos_bis] ==  '|')
	{
		if (line[++pos_bis] != ' ')
		{
			std::cerr << RED << DATEVALUE << std::endl;
			return 0;
		}
		if (isdigit(line[++pos_bis]))
		{
			value = line.substr(pos_bis, line.size() - pos_bis);
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
			if (data.value == 0)
				return -1;
		}
		else
		{
			std::cerr << RED << VALUE << std::endl;
			return 0;
		}
	}
	return data.value;
}
void	BitcoinExchange::compare(std::string& date)
{
	std::ifstream	check_data("data.csv");
	std::string		line;
	float			value;
	float			i;

	if (!check_data.is_open())
	{
		std::cerr << RED << OPEN << std::endl;
		return ;
	}
	i = 0;
	while (std::getline(check_data, line))
	{
		if (i == 0)
		{
			i++;
			continue ;
		}
		if (line.substr(0, 10) == date)
		{
			value = _csv[date] * _btc[date];
			std::cout << WHITE << date << " => "
				<< _btc[date] << " = " << value << std::endl;
			break ;
		}
		i++;
	}
	check_data.close();
	return ;
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
	if (!parseData())
		return ;
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
				std::cerr << RED << "Error: empty line." << std::endl;
				std::cout << ">> " << line << std::endl;
				continue ;
			}
			float	input = inputFileForm(line, data);
			if (input > 0)
			{
				_btc[data.time] = input;
				compare(data.time);
				if (input >= 1 && input <= 1000)
					nearDate(line.substr(0, 10));
			}
			else if (input == -1)
			{
				_btc[data.time] = 0;
				compare(data.time);
			}
			else
				std::cout << "KO >> " << line << std::endl;
		}
		idx++;
	}
	input.close();
	return ;
}

int	BitcoinExchange::parseData()
{
	std::ifstream	data("data.csv");
	std::string		line;
	std::string		date;
	std::string		value;
	int				idx;

	if (!data.is_open())
	{
		std::cerr << RED << OPEN << std::endl;
		return 0;
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
		value = line.substr(11, line.size() - 11);
		_csv[date] = atof(value.c_str());
		idx++;
	}
	data.close();
	return 1;
}

