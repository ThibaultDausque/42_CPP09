# include <iostream>
# include "PmergeMe.hpp"
#include <cstdlib>

int	main(int ac, char **av)
{
	PmergeMe	algo;
	int			i;
	int			j;

	if (ac == 1)
	{
		std::cerr << "Error: you need to put some numbers." << std::endl;
		return 0;
	}
	i = 1;
	while (av[i])
	{
		algo.checkList(av[i]);
		i++;
	}
	int	tab[i];
	int	size = sizeof(tab) / sizeof(tab[0]);
	i = 1;
	j = 0;
	while (av[i])
		tab[j++] = atoi(av[i++]);
	std::cout << "Before: ";
	for (int l = 0; l < size; l++)
		std::cout << tab[l] << ", ";
	std::cout << std::endl;
	algo.mergeSort(tab);
	std::cout << "After: ";
	for (int k = 0; k < size; k++)
		std::cout << tab[k] << ", ";
	std::cout << std::endl;
	return 0;
}
