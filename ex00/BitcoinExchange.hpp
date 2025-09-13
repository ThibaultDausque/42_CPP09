#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <stdlib.h>
# include <map>
# include <fstream>
# include <ctime>
# include <cctype>
# include <cmath>
# include "message.hpp"

class BitcoinExchange
{
	private:
		typedef struct s_data
		{
			float	value;
			std::string	time;
		}	t_data;
		std::map<std::string, float>	_btc;
		std::map<std::string, float>	_csv;
	
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& cpy);
		~BitcoinExchange();
		BitcoinExchange&	operator=(const BitcoinExchange& src);
		void	parseInput(std::string& file);
		float	inputFileForm(std::string& line, t_data &data);
		int		dateForm(std::string& date, t_data& data);
		void	parseData();
		bool	dateIsValid(std::string& date);
		bool	leapYear();
		void	nearDate(const std::string date);
		void	compare(std::string& date);
};

#endif
