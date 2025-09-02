#include "PmergeMe.hpp"

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
		_toto = src._toto;
		_tutu = src._tutu;
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
	_tutu.push_back(atoi(list));
	return 1;
}

int	PmergeMe::execFord(char **av)
{
	int		i;

	i = 1;
	while (av[i])
	{
		if (!checkList(av[i]))
			return 0;
		i++;
	}

	std::cout << "Before: ";
	for (std::vector<int>::iterator it = _tutu.begin(); it != _tutu.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	sortPairs(_tutu);
	std::cout << std::endl;
	std::cout << "After (max tab): ";
	for (std::vector<int>::iterator it = _tutu.begin(); it != _tutu.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Time to process a range of " << i << " elements with std::<container>       :       " << "<time>" << std::endl;
	std::cout << "Time to process a range of " << i << " elements with std::<container>       :       " << "<time>" << std::endl;
	std::cout << std::endl;
	return 0;
}
