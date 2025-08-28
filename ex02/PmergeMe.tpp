#include "PmergeMe.hpp"

template <typename T>
void    displayList(T &seq)
{
    for (std::T<int>::iterator it = seq.begin(); it != seq.end(); it++)
        std::cout << *it << std::endl;
}

template <typename T>
void fillList(int nb, T &seq)
{
    seq.push_back(nb);
}

template <typename T>
void    mergeSort(T &seq)
{
    size_t	size;
	size_t	mid;
	int		i;

	size = tab.size();
	if (size <= 1)
		return ;
	mid = size / 2;

	T	right;
	T	left;

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
	merge(right, left, seq);
}


template <typename T>
void	merge(T &right, T &left, T &tab)
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
