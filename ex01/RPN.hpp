#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <vector>

class	RPN
{
	public:
		std::vector<int>	_nb;
		std::vector<char>	_sign;

	private:
		RPN::RPN();
		RPN::RPN(const RPN& cpy);
		~RPN::RPN();
		RPN&	operator=(const RPN& src);
		bool	parseCmd(std::string& av);
}

#endif


