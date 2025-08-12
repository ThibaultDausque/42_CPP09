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

void	PmergeMe::fillList(int nb)
{
	_list.push_back(nb);	
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
	_list.push_back(atoi(list));
	return 1;
}

void	PmergeMe::displayList(void)
{
	for (std::list<int>::iterator it = _list.begin(); it != _list.end(); it++)
	  std::cout << *it << " ";
	std::cout << std::endl;
	return ;
}

void	PmergeMe::mergeSort(int* tab, int size)
{
	int		size;
	int		middle;
	int		i;
	int		j;

	middle = size / 2;
	int		left[middle];
	int		right[middle];

	if (size <= 1)
		return ;
	j = 0;
	for (i = 0; i < size; i++)
	{
		if (i < middle)
			right[i] = tab[i];
	  	else
		{
			left[j] = tab[i];
			j++;
		}
	}
	mergeSort(right);
	mergeSort(left);
	merge(right, left, tab);
}

void	PmergeMe::merge(int *right, int *left, int *array)
{
	int		leftSize;
	int		rightSize;
	int		i;
	int		j;
	int		k;

	leftSize = left.size() / 2;
	rightSize = array.size() - leftSize();

	i = 0;
	j = 0;
	k = 0;
	while (i < leftSize && j < rightSize)
	{
		if (right[j] < left[i])
		{
			array[k] = right[j];
			k++;
			j++;
		}
		else
		{
			array[k] = left[i];
			k++;
			i++;
		}
	}
}
