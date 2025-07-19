#include "RPN.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: ac must be equal 2." << std::endl;
		return 0;
	}
	RPN	calcool;
	std::string	arg(av[1]);

	calcool.calcool(arg);
	return 0;
}
