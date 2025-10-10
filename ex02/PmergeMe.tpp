#include "PmergeMe.hpp"
#include <algorithm>

template <typename T>
void	fillList(int nb, T &seq)
{
	seq.push_back(nb);
}

template <typename T>
bool	isItSorted(T &tab)
{
	bool sorted = true;
	for (size_t i = 0; i < tab.size() - 1; i++)
	{
    	if (tab[i] > tab[i + 1])
		{
			std::cerr << tab[i] << " < " << tab[i + 1] << std::endl;
        	sorted = false;
        	break;
    	}
	}
	return sorted;
}

template <typename T>
T	jacob(T &min, T &max)
{
	int		jacobsthal;
	int		middle = (max.size() - 1) / 2;
	int		len = min.size() - 1;
	T		final;

	for (typename T::iterator it = max.begin(); it != max.end(); it++)
		final.push_back(*it);
	for (int k = 1; k <= len; k++)
	{
		jacobsthal = round((pow(2, k + 1) + pow(-1, k)) / 3);
		if (jacobsthal > 0 && jacobsthal < len)
		{
			typename T::iterator	it = min.begin() + jacobsthal;
			typename T::iterator	max_it = max.begin() + middle;
			if (*it > *max_it)
			{
				typename T::iterator	pos = std::lower_bound(final.begin() + middle, final.end(), *it);
				final.insert(pos, *it);
				min.erase(it);
				continue ;
			}
			typename T::iterator	pos = std::lower_bound(final.begin(), final.end(), *it);
			final.insert(pos, *it);
			min.erase(it);
		}
	}
	for (typename T::iterator it = min.begin(); it != min.end(); it++)
	{
		typename T::iterator	mit = std::lower_bound(final.begin(), final.end(), *it);
		final.insert(mit, *it);
	}
	if (!isItSorted(final))
		std::cout << "Error: Ford-Johnson sort failed." << std::endl;
	return final;
}

template <typename T>
T	sortPairs(T &tab)
{
	T		pair;
	int		flag;
	size_t	i;
	int		tmp;
	size_t	len;
	T		result;		

	len = tab.size();
	i = 0;
	for (typename T::iterator it = tab.begin(); it != tab.end(); it++)
	{
		if (i % 2 == 0)
			flag = 1;
		if ((i == len - 1 && len % 2 != 0)
			|| (i == len - 1 && len % 2 == 0))
			break ;
		if (flag == 1)
		{	
			if (*it > *(it + 1))
			{
				tmp = *it;
				*it = *(it + 1);
				*(it + 1) = tmp;
				flag = 0;
			}
		}
		i++;
	}
	result = maxElem(tab);
	return result;
}

template <typename T>
T	maxElem(T &tab)
{
	T		max;
	size_t	i;
	int		flag;
	size_t	len;
	T		result;
	len = tab.size();
	i = 0;
	flag = 0;
	for (typename T::iterator it = tab.begin(); it != tab.end(); it++)
	{
		if (it == tab.end())
			max.push_back(*it);
	  	else if (i % 2 == 0)
		{
			i++;
			continue ;
		}
	  	else
			max.push_back(*it);
		i++;
	}
	for (typename T::iterator it = max.begin(); it != max.end(); it++)
	{
		typename T::iterator	mit = std::find(tab.begin(), tab.end(), *it);
		if (it != max.end())
			tab.erase(mit);
	}
	mergeSort(max);
	result = jacob(tab, max);
	return result;
}

template <typename T>
void	Pmerge(T &right, T &left, T &tab)
{
	size_t	i;
	size_t	j;
	size_t	l_size = left.size();
	size_t	r_size = right.size();

	i = 0;
	j = 0;
	tab.clear();
	typename T::iterator	r_it = right.begin();
	typename T::iterator	l_it = left.begin();
	while (i < l_size && j < r_size)
	{
		if (*l_it < *r_it)
		{
			tab.push_back(*l_it);
			i++;
			l_it++;
		}
		else
		{
			tab.push_back(*r_it);
			j++;
			r_it++;
		}
	}
	while (i < l_size)
	{
		tab.push_back(*l_it);
		i++;
		l_it++;
	}
	while (j < r_size)
	{
		tab.push_back(*r_it);
		j++;
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

	Pmerge(right, left, seq);
}
