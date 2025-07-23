#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <list>
# include <deque>

class PmergeMe
{
	private:
		std::deque	_pair;
		std::list	_list;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& cpy);
		~PmergeMe();
		PmergeMe&	operator=(const PmergeMe& src);
		void	checkList(std::string& list);

};

#endif
