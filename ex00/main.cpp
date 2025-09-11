#include <iostream>
#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return 0;
	}
	std::string	file(av[1]);
	BitcoinExchange	bc;
	bc.parseInput(file);
	return 0;
}