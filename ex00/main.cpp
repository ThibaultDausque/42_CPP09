#include <iostream>
#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	std::string	file(av[1]);
	if (ac != 2 || file != "input.txt")
	{
		std::cout << "Error: could not open file." << std::endl;
		return 0;
	}
	BitcoinExchange	bc;
	bc.parseInput(file);
	return 0;
}