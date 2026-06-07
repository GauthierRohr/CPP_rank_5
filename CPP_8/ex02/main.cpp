#include <iostream>
#include <list>
#include "MutantStack.hpp"

int	main()
{
	std::cout << "💥 Test sujet 💥" << std::endl;
	MutantStack<int>	mstack;
	mstack.push(5);
	mstack.push(17);

	std::cout << "top = " << mstack.top() << std::endl;
	
	mstack.pop();
	
	std::cout << "size apres pop = " << mstack.size() << std::endl;
	std::cout << "top = " << mstack.top() << std::endl;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator	it = mstack.begin();
	MutantStack<int>::iterator	ite = mstack.end();
	++it;
	--it;
	std::cout << "Contenu (bas vers haut) :" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int>	s(mstack);

	std::cout << std::endl;
	std::cout << "💥 Même test avec std list pour check💥" << std::endl;
	std::list<int>	lst;
	lst.push_back(5);
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);

	std::list<int>::iterator	lit = lst.begin();
	std::list<int>::iterator	lite = lst.end();
	std::cout << "Contenu :" << std::endl;
	while (lit != lite)
	{
		std::cout << *lit << std::endl;
		++lit;
	}

	std::cout << std::endl;
	std::cout << "💥 itérateur reverse 💥" << std::endl;
	MutantStack<int>			rstack;
	rstack.push(1);
	rstack.push(2);
	rstack.push(3);
	MutantStack<int>::reverse_iterator	rit = rstack.rbegin();
	MutantStack<int>::reverse_iterator	rite = rstack.rend();
	std::cout << "Contenu (haut vers bas) :" << std::endl;
	while (rit != rite)
	{
		std::cout << *rit << std::endl;
		++rit;
	}

	return (0);
}
