#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <vector>

class	RPN
{
	private:
		std::vector<int>	_nb;

	public:
		RPN();
		RPN(const RPN& cpy);
		~RPN();
		RPN&	operator=(const RPN& src);
		bool	parseCmd(std::string& av);
		void	calcool(std::string& av);
};

#endif


