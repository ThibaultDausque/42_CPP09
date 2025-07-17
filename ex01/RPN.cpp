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

RPN&	RPN::operator=(coxnst RPN& src)
{
	if (this != &src)
	{
		this->_nb = src._nb;
		this->_sign = src._sign;
	}
	return *this;
}

bool	RPN::parseCmd(std::string&	av)
{


}
