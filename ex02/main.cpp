#include <iostream>
#include "PmergeMe.hpp"
#include <cstdlib>

int	main(int ac, char **av)
{
	PmergeMe	algo;
	int			i;

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
	std::list<int> tab;
	i = 1;
	while (av[i])
		tab.push_back(atoi(av[i++]));
	std::cout << "Before: ";
	for (std::list<int>::iterator it = tab.begin(); it != tab.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	mergeSort(tab);
	std::cout << std::endl;
	std::cout << "After: ";
	for (std::list<int>::iterator it = tab.begin(); it != tab.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Time to process a range of " << i << " elements with std::<container>       :       " << "<time>" << std::endl;
	std::cout << "Time to process a range of " << i << " elements with std::<container>       :       " << "<time>" << std::endl;
	std::cout << std::endl;
	return 0;
}
