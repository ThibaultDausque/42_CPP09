#include "PmergeMe.hpp"
#include <cctype>

PmergeMe::PmergeMe()
{

}

PmergeMe::PmergeMe(const PmergeMe& cpy)
{
	*this = cpy;
}

PmergeMe::~PmergeMe()
{

}

PmergeMe&	PmergeMe::operator=(const PmergeMe& src)
{
	if (this != &src)
	{
		this->_pair = src._pair;
		this->_list = src._list;
	}
	return *this;
}

int	PmergeMe::checkList(char *list)
{
	std::string	av(list);
	for (size_t i = 0; i < av.size(); i++)
	{
		if (av[i] < '0' || av[i] > '9')
		{
			std::cout << "Error: list of number KO." << std::endl;
			return 0;
		}
	}
	_list.push_back(atoi(list);
	return 1;
}

void	PmergeMe::displayList(void)
{
	for (int i = _list.begin(); it != _list.end(); i++)
	  std::cout << i << " ";
	std::cout << std::endl;
	return ;
}
