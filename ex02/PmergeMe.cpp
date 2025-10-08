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
		_seq1 = src._seq1;
		_seq2 = src._seq2;
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
	_seq1.push_back(atoi(list));
	_seq2.push_back(atoi(list));
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

bool	PmergeMe::duplicate(char **av, int ac)
{
	int		nb1;
	int		nb2;

	for (int i = 1; i < ac - 1; i++)
	{
		for (int j = 2; j < ac; j++)
		{
			nb1 = atoi(av[i]);
			nb2 = atoi(av[j]);
			if (i == j)
				continue ;
			else if (nb1 == nb2)
			{
				std::cout << "There are some duplicates numbers" << std::endl;
				return true;
			}
		}
	}
	return false;
}

int	PmergeMe::execFord(char **av, int ac)
{
	int		i;
	clock_t	vectorTime;
	clock_t	dequeTime;
	clock_t	tmp;

	i = 1;
	while (av[i])
	{
		if (!checkList(av[i]))
			return 0;
		i++;
	}
	if (duplicate(av, ac))
		return 0;
	else if (sortedList(av, ac))
		return 0;

	std::cout << "Before: ";
	for (std::vector<int>::iterator it = _seq2.begin(); it != _seq2.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << std::endl;
	dequeTime = clock();
	sortPairs(_seq1);
	tmp = clock();
	dequeTime = tmp - dequeTime;
	vectorTime = clock();
	sortPairs(_seq2);
	tmp = clock();
	vectorTime = tmp - vectorTime;
	std::cout << "After: ";
	for (std::vector<int>::iterator it = _seq2.begin(); it != _seq2.end(); it++)
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
