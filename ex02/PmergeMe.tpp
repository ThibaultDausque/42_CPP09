#include "PmergeMe.hpp"

template <typename T>
void	displayList(T &seq)
{
    for (typename T::iterator it = seq.begin(); it != seq.end(); it++)
        std::cout << *it << std::endl;
}

template <typename T>
void	fillList(int nb, T &seq)
{
    seq.push_back(nb);
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
	typename T::iterator	r_it = right.begin();
	typename T::iterator	l_it = left.begin();
	while (i < l_size && j < r_size)
	{
		if (*l_it < *r_it)
		{
			tab.insert(l_it, k);
			i++;
			k++;
		}
		else
		{
			tab.insert(r_it, k);
			j++;
			k++;
		}
		l_it++;
		r_it++;
	}
	while (i < l_size)
	{
		tab.insert(l_it, k);
		i++;
		k++;
		l_it++;
	}
	while (j < r_size)
	{
		tab.insert(r_it, k);
		j++;
		k++;
		r_it++;
	}
}

template <typename T>
void    mergeSort(T &seq)
{
    size_t	size;
	size_t	mid;

	size = seq.size();
	if (size <= 1)
		return ;
	mid = size / 2;

	T	right;
	T	left;

	typename T::iterator it = seq.begin();
	for (size_t i = 0; i < size; i++, it++)
	{
		if (i < mid)
			left.push_back(*it);
		else
			right.push_back(*it);
	}
	mergeSort(right);
	mergeSort(left);
	merge(right, left, seq);
}



