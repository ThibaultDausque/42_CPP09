#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <list>
# include <deque>
# include <cstdlib>
# include <vector>

class PmergeMe
{
	private:
		std::deque<int>	_toto;
		std::list<int>	_tutu;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& cpy);
		~PmergeMe();
		PmergeMe&	operator=(const PmergeMe& src);
		int		checkList(char *list);
		int		execFord(char **av);
};

#include "PmergeMe.tpp"

#endif
