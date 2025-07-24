#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <list>
# include <deque>

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
};

#endif
