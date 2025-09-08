#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <list>
# include <deque>
# include <cstdlib>
# include <vector>
# include <cmath>

class PmergeMe
{
	private:
		std::deque<int>		_seq1;
		std::vector<int>	_seq2;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& cpy);
		~PmergeMe();
		PmergeMe&	operator=(const PmergeMe& src);
		int		checkList(char *list);
		int		execFord(char **av, int ac);
		bool	sortedList(char **av, int ac);
};

template <typename T>
void	displayList(T &seq);

template <typename T>
void	fillList(int nb, T &seq);

template <typename T>
void	sortPairs(T &tab);

template <typename T>
void	maxElem(T &tab);

template <typename T>
void	mergeSort(T &seq);

#include "PmergeMe.tpp"

#endif
