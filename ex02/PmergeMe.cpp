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

int	tabSize(int *tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	return i;
}

void	PmergeMe::mergeSort(int *tab)
{
	int		size;
	int		l_size;
	int		r_size;
	int		j;
	int		k;

	size = tabSize(tab);
	l_size = size / 2;
	r_size = size - l_size;

	if (size <= 1)
		return ;
	int	right[r_size];
	int	left[l_size];

	j = 0;
	k = 0;
	for (int i = 0; i < size; i++)
	{
		if (i < l_size)
		{
			left[j] = tab[i];
			j++;
		}
		else
		{
			right[k] = tab[i];
			k++;
		}
	}
	mergeSort(right);
	mergeSort(left);
	merge(right, left, tab);

}

void	PmergeMe::merge(int *right, int *left, int *tab)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (right[i] && left[j])
	{
		if (left[j] < right[i])
		{
			tab[k] = left[j];
			k++;
			j++;
		}
		else
		{
			tab[k] = right[i];
			k++;
			i++;
		}
	}
}