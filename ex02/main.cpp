#include <iostream>
#include "PmergeMe.hpp"
#include <cstdlib>

int	main(int ac, char **av)
{
	PmergeMe	pm;

	if (ac == 1)
	{
		std::cerr << "Error: you need to put some numbers." << std::endl;
		return 0;
	}
	pm.execFord(av);
}
