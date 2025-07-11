#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <fstream>
# include <ctime>
# include <cctype>
# include "message.hpp"

class BitcoinExchange
{
	private:
		typedef struct t_data
		{
			float	value;
			std::string	time;
		}	s_data;
		std::map<std::string, float>	_btc;
	
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& cpy);
		~BitcoinExchange();
		BitcoinExchange&	operator=(const BitcoinExchange& src);
		void	parseInput(std::string& file);
		int		inputFileForm(std::string& line);
		int		dateForm(std::string& date);
};

#endif