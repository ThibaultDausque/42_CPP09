# include "RPN.hpp"

RPN::RPN()
{

}

RPN::RPN(const RPN& cpy)
{
	*this = cpy;
}

RPN::~RPN()
{

}

RPN&	RPN::operator=(const RPN& src)
{
	if (this != &src)
		this->_nb = src._nb;
	return *this;
}

bool	RPN::parseCmd(std::string&	av)
{
	for (size_t i = 0; i < av.size(); i++)
	{
		if (i % 2 == 0)
		{
			if ((av[i] < '0' || av[i] > '9') && av[i] != '+' && av[i] != '-'
				&& av[i] != '*' && av[i] != '/')
			{
				std::cerr << "Error: Bad calcool." << std::endl;
				return false;
			}
		}
	}
	return true;
}

bool	RPN::countOps(std::string& av)
{
	int		signs;
	int		nb;

	signs = 0;
	nb = 0;
	for (size_t i = 0; i < av.size(); i++)
	{
		if (av[i] >= '0' && av[i] <= '9')
			nb++;
		if (av[i] == '-' || av[i] == '+'
			|| av[i] == '*' || av[i] == '/')
			signs++;
	}
	if (nb != signs + 1)
		return false;
	return true;
}

void	RPN::calcool(std::string& av)
{
	if (!countOps(av))
	{
		std::cerr << "Error: RPN rule not respected. (n = o + 1)" << std::endl;
		return ;
	}
	if (parseCmd(av))
	{
		std::list<int>::iterator	last_it;
		std::list<int>::iterator	prev_it;
		for (size_t i = 0; i < av.size(); i++)
		{
			while (av[i] == ' ' && av[i])
				i++;
			if (av[i] == '\0')
				break ;
			if (av[i] >= '0' && av[i] <= '9')
				_nb.push_back(atoi(&av[i]));
			last_it = _nb.end();
			last_it--;
			prev_it = last_it;
			prev_it--;
			if (_nb.size() >= 2)
			{	
				if (av[i] == '+')
				{
					*prev_it += *last_it;
					_nb.pop_back();
				}
				else if (av[i] == '-')
				{
					*prev_it -= *last_it;
					_nb.pop_back();
				}
				else if (av[i] == '*')
				{
					*prev_it *= *last_it;
					_nb.pop_back();
				}
				else if (av[i] == '/')
				{
					if (*last_it == 0)
					{
						std::cerr << "Error: division by 0." << std::endl;
						return ;
					}
					*prev_it /= *last_it;
					_nb.pop_back();
				}
			}
		}
		std::cout << "Result: " << *prev_it << std::endl;
	}
	return ;
}
