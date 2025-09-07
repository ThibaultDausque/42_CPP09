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
void	rmMinNbers(T &tab, T &max)
{
	for (typename T::iterator it = tab.begin(); it != tab.end(); )
	{
		bool erased = false;
		for (typename T::iterator mit = max.begin(); mit != max.end(); mit++)
		{
			if (*it == *mit)
			{
				tab.erase(it);
				erased = true;
				break ;
			}
		}
		if (!erased)
			it++;
	}
}

template <typename T>
void	jacobsthal(T &min, T &max)
{
	int		jacobsthal;
	int		len = min.size();
	(void)	max;

	for (int k = 1; k <= len; k++)
	{
		jacobsthal = round((pow(2, k + 1) + pow(-1, k))/3);
		std::cout << jacobsthal << ", ";
	}
	std::cout << std::endl;
	// J(n)=J(n−1)+2J(n−2)
}

template <typename T>
void	sortPairs(T &tab)
{
	T		pair;
	int		flag;
	size_t	i;
	int		tmp;
	size_t	len;

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
	std::cout << std::endl;
	std::cout << "sort pairs: ";
	for (typename T::iterator it = tab.begin(); it != tab.end(); it++)
		std::cout << *it << " ";
	maxElem(tab);
}

template <typename T>
void	maxElem(T &tab)
{
	T		max;
	size_t	i;
	int		flag;
	size_t	len;

	len = tab.size();
	i = 0;
	flag = 0;
	for (typename T::iterator it = tab.begin(); it != tab.end(); it++)
	{
		if (i % 2 != 0)
			flag = 1;
		if (i == len - 1 && len % 2 != 0)
		{
			max.push_back(*it);
			break ;
		}
		if (flag == 1)
		{
			max.push_back(*it);
			flag = 0;
		}
		if (i == len - 1)
			break ;
		i++;
	}
	rmMinNbers(tab, max);
	std::cout << std::endl;
	std::cout << "min: ";
	for (typename T::iterator it = tab.begin(); it != tab.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "max: ";
	for (typename T::iterator it = max.begin(); it != max.end(); it++)
		std::cout << *it << " ";
	mergeSort(max);
	std::cout << std::endl;
	std::cout << "After (max tab): ";
	for (typename T::iterator it = max.begin(); it != max.end(); it++)
		std::cout << *it << " ";
	mergeSort(tab);
	std::cout << std::endl;
	std::cout << "After (min tab): ";
	for (typename T::iterator it = tab.begin(); it != tab.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "Jacobsthal insertion: " << std::endl;
	jacobsthal(tab, max);
}

template <typename T>
void	Pmerge(T &right, T &left, T &tab)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	len = tab.size();
	size_t	l_size = left.size();
	size_t	r_size = right.size();

	i = 0;
	j = 0;
	k = 0;
	while (i < len)
	{
		tab.pop_back();
		i++;
	}
	i = 0;
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
		k++;
	}
	while (i < l_size)
	{
		tab.push_back(*l_it);
		i++;
		l_it++;
		k++;
	}
	while (j < r_size)
	{
		tab.push_back(*r_it);
		j++;
		r_it++;
		k++;
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
