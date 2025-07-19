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
		if (av[0] == ' ' || (i % 2 != 0 && av[i] != ' '))
		{
			std::cerr << "Error: Bad argument." << std::endl;
			return false;
		}
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

void	RPN::calcool(std::string& av)
{
	if (parseCmd(av))
	{
		for (size_t i = 0; i < av.size(); i++)
		{
			if (av[i] > '0' && av[i] < '9')
				_nb.push_back(atoi(&av[i]));
			if (_nb.size() >= 2)
			{	
				if (av[i] == '+')
				{
					_nb[_nb.size() - 2] += _nb[_nb.size() - 1];
					_nb.pop_back();
				}
				else if (av[i] == '-')
				{
					_nb[_nb.size() - 2] -= _nb[_nb.size() - 1];
					_nb.pop_back();
				}
				else if (av[i] == '*')
				{
					_nb[_nb.size() - 2] *= _nb[_nb.size() - 1];
					_nb.pop_back();
				}
				else if (av[i] == '/')
				{
					_nb[_nb.size() - 2] = _nb[_nb.size() - 1];
					_nb.pop_back();
				}
			}
		}
	}
	std::cout << "Result: " << _nb.at(0) << std::endl;
	return ;
}
