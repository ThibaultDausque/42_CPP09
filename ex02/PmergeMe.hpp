#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <list>
# include <deque>
# include <cstdlib>

class PmergeMe
{
	private:
		std::deque<int>	_pair;
		std::list<int>	_list;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& cpy);
		~PmergeMe();
		PmergeMe&	operator=(const PmergeMe& src);
		int		checkList(char *list);
		void	displayList(void);
		void	mergeSort(int* tab);
		void	merge(int *right, int *left, int *tab);
		void	fillList(int nb);
};

#endif
