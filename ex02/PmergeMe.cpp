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

void	PmergeMe::mergeSort(std::vector<int> &tab)
{
	size_t	size;
	size_t	mid;
	int		i;

	size = tab.size();
	if (size <= 1)
		return ;
	mid = size / 2;

	std::vector<int>	right;
	std::vector<int>	left;

	i = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (i < mid)
			left.push_back(tab[i]);
		else
			right.push_back(tab[i]);
	}
	mergeSort(right);
	mergeSort(left);
	merge(right, left, tab);
}

void	PmergeMe::merge(std::vector<int> &right, std::vector<int> &left, std::vector<int> &tab)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	l_size = left.size();
	size_t	r_size = right.size();

	i = 0;
	j = 0;
	k = 0;
	while (i < l_size && j < r_size)
	{
		if (left[i] < right[j])
		{
			tab[k] = left[i];
			i++;
			k++;
		}
		else
		{
			tab[k] = right[j];
			k++;
			j++;
		}
	}
	while (i < l_size)
	{
		tab[k] = left[i];
		k++;
		i++;
	}
	while (j < r_size)
	{
		tab[k] = right[j];
		k++;
		j++;
	}
}