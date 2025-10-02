#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <list>
# include <cstdlib>

class	RPN
{
	private:
		std::list<int>	_nb;

	public:
		RPN();
		RPN(const RPN& cpy);
		~RPN();
		RPN&	operator=(const RPN& src);
		bool	parseCmd(std::string& av);
		bool	countOps(std::string& av);
		void	calcool(std::string& av);
};

#endif


