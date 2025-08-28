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
		int		checkList(char *list);
		int		execFord(char **av);
		// void	displayList(void);
		// void	mergeSort(std::vector<int> &tab);
		// void	merge(std::vector<int> &right, std::vector<int> &left, std::vector<int> &tab);
		// void	fillList(int nb);
};

#include "PmergeMe.tpp"

#endif
