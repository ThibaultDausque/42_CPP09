#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <list>
# include <deque>
# include <cstdlib>
# include <vector>

std::deque<int>	_pair;
std::list<int>	_list;

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& cpy);
		~PmergeMe();
		PmergeMe&	operator=(const PmergeMe& src);
		int		checkList(char *list);
		void	displayList(void);
		void	mergeSort(std::vector<int> &tab);
		void	merge(std::vector<int> &right, std::vector<int> &left, std::vector<int> &tab);
		void	fillList(int nb);
};

# include "PmergeMe.tpp"

#endif
