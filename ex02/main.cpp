# include <iostream>
# include "PmergeMe.hpp"

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
	algo.displayList();
	return 0;
}
