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
		std::vector<int>	_tutu;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& cpy);
		~PmergeMe();
		PmergeMe&	operator=(const PmergeMe& src);
		int		checkList(char *list);
		int		execFord(char **av);
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
