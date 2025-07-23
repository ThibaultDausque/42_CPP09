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

void	PmergeMe::checkList(std::string& list)
{
	int		count;

	count = 0;
	for (size_t i = 0; isdigit(list[i]); i++)
	{
		if (list[i] < '0' || list[i] > '9')
		{
			std::cout << "Error: list of number KO." << std::endl;
			if (list[i] == ' ')
				continue ;
			return ;
		}
	}
	std::cout << "OK" << std::endl;
}


