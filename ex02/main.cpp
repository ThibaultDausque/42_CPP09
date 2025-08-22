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
	std::vector<int> tab;
	i = 1;
	j = 0;
	while (av[i])
		tab.push_back(atoi(av[i++]));
	std::cout << "Before: ";
	for (std::vector<int>::iterator it = tab.begin(); it != tab.end(); ++it)
		std::cout << *it << ", ";
	std::cout << std::endl;
	algo.mergeSort(tab);
	std::cout << "After: ";
	for (std::vector<int>::iterator it = tab.begin(); it != tab.end(); ++it)
		std::cout << *it << ", ";
	std::cout << std::endl;
	return 0;
}
