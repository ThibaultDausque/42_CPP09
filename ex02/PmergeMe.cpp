#include "PmergeMe.hpp"
#include <sstream>
#include <vector>

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
		_seq1 = src._seq1;
		_seq2 = src._seq2;
	}
	return *this;
}

int	PmergeMe::checkList(char *list)
{
	std::string	av(list);
	int			nb;
	std::istringstream	iss(av);

	for (size_t i = 0; i < av.size(); i++)
	{
		if (av[i] < '0' || av[i] > '9')
		{
			std::cerr << "Error: list of number KO." << std::endl;
			return 0;
		}
	}
	if (iss >> nb)
	{
		_seq1.push_back(nb);
		_seq2.push_back(nb);
	}
	else
	{
		std::cerr << "Error: bad number." << std::endl;
		return 0;
	}
	return 1;
}

bool	PmergeMe::sortedList(char **av, int ac)
{
	int		i;
	int		j;
	int		nb1;
	int		nb2;

	i = 1;
	j = 2;
	for (; i < ac - 1 && j < ac; i++, j++)
	{
		nb1 = atoi(av[i]);
		nb2 = atoi(av[j]);
		if (nb1 > nb2)
			return false;
	}
	std::cout << "This sequence of numbers are sorted" << std::endl;
	return true;
}

int	PmergeMe::execFord(char **av, int ac)
{
	int		i;
	clock_t	vectorTime;
	clock_t	dequeTime;
	clock_t	tmp;
	std::deque<int>		result1;
	std::vector<int>	result2;

	i = 1;
	while (av[i])
	{
		if (!checkList(av[i]))
			return 0;
		i++;
	}
	if (sortedList(av, ac))
		return 0;

	std::cout << "Before: ";
	for (std::vector<int>::iterator it = _seq2.begin(); it != _seq2.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << std::endl;
	dequeTime = clock();
	result1 = sortPairs(_seq1);
	tmp = clock();
	dequeTime = tmp - dequeTime;
	vectorTime = clock();
	result2 = sortPairs(_seq2);
	tmp = clock();
	vectorTime = tmp - vectorTime;
	std::cout << "After: ";
	for (std::vector<int>::iterator it = result2.begin(); it != result2.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << std::endl;
	double	msVector = static_cast<double>(vectorTime) / CLOCKS_PER_SEC * 1000;
	double	msDeque = static_cast<double>(dequeTime) / CLOCKS_PER_SEC * 1000;
	std::cout << "Time to process a range of " << i - 1 << " elements with std::deque       :       " << msDeque << "ms" << std::endl;
	std::cout << "Time to process a range of " << i - 1 << " elements with std::vector      :       " << msVector << "ms" << std::endl;
	std::cout << std::endl;
	return 0;
}
