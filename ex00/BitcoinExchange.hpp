#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <stdlib.h>
# include <map>
# include <fstream>
# include <ctime>
# include <cctype>
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
	
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& cpy);
		~BitcoinExchange();
		BitcoinExchange&	operator=(const BitcoinExchange& src);
		void	parseInput(std::string& file);
		int		inputFileForm(std::string& line, t_data& data);
		int		dateForm(std::string& date, t_data& data);
};

#endif