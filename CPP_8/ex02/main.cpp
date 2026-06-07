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

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator	it = mstack.begin();
	MutantStack<int>::iterator	ite = mstack.end();
	++it;
	--it;
	std::cout << "Nombres :" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int>	s(mstack);

	std::cout << std::endl;
	std::cout << "💥 Meme test avec std::list 💥" << std::endl;
	std::list<int>	lst;
	lst.push_back(5);
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);

	std::list<int>::iterator	lit = lst.begin();
	std::list<int>::iterator	lite = lst.end();
	std::cout << "Nombres :" << std::endl;
	while (lit != lite)
	{
		std::cout << *lit << std::endl;
		++lit;
	}

	std::cout << std::endl;
	std::cout << "💥 empty() 💥" << std::endl;
	MutantStack<int>	emptyStack;
	std::cout << "stack vide : empty = " << (emptyStack.empty() ? "true" : "false") << std::endl;
	emptyStack.push(42);
	std::cout << "apres push  : empty = " << (emptyStack.empty() ? "true" : "false") << std::endl;

	std::cout << std::endl;
	std::cout << "💥 size() 💥" << std::endl;
	MutantStack<int>	sstack;
	std::cout << "size = " << sstack.size() << std::endl;
	sstack.push(1);
	sstack.push(2);
	sstack.push(3);
	std::cout << "apres 3 push : size = " << sstack.size() << std::endl;
	sstack.pop();
	std::cout << "apres pop    : size = " << sstack.size() << std::endl;

	std::cout << std::endl;
	std::cout << "💥 top() lecture et modification 💥" << std::endl;
	MutantStack<int>	tstack;
	tstack.push(10);
	tstack.push(20);
	tstack.push(30);
	std::cout << "top = " << tstack.top() << std::endl;
	tstack.top() = 99;
	std::cout << "top apres modif = " << tstack.top() << std::endl;

	std::cout << std::endl;
	std::cout << "💥 push() et pop() a la cahine eh oui! 💥" << std::endl;
	MutantStack<int>	ppstack;
	ppstack.push(100);
	ppstack.push(200);
	ppstack.push(300);
	ppstack.push(400);
	ppstack.push(500);
	std::cout << "Ça depile :" << std::endl;
	while (!ppstack.empty())
	{
		std::cout << ppstack.top() << std::endl;
		ppstack.pop();
	}

	std::cout << std::endl;
	std::cout << "💥 const_iterator 💥" << std::endl;
	MutantStack<int>					cstack;
	cstack.push(7);
	cstack.push(14);
	cstack.push(21);
	MutantStack<int> const				constStack(cstack);
	MutantStack<int>::const_iterator	cit = constStack.begin();
	MutantStack<int>::const_iterator	cite = constStack.end();
	std::cout << "Contenu (const) :" << std::endl;
	while (cit != cite)
	{
		std::cout << *cit << std::endl;
		++cit;
	}

	return (0);
}
