#include "MutantStack.hpp"

int main()
{
MutantStack<int> mstack;
std::cout << "\033[33m----------push(5) -> push(17)----------\033[0m" << std::endl;
mstack.push(5);
mstack.push(17);
std::cout << "mstack.top() = " << mstack.top() << std::endl;
std::cout << std::endl;

std::cout << "\033[33m----------pop()----------\033[0m" << std::endl;
mstack.pop();
std::cout << "mstack.top() = " << mstack.top() << std::endl;
std::cout << "mstack.size() = " << mstack.size() << std::endl;
std::cout << std::endl;

std::cout << "\033[33m----------push(5) -> push(5) -> push(737) -> push(0)----------\033[0m" << std::endl;
std::cout << "\033[34mIterator test\033[0m" << std::endl;
mstack.push(3);
mstack.push(5);
mstack.push(737);
mstack.push(0);
MutantStack<int>::iterator it = mstack.begin();
MutantStack<int>::iterator ite = mstack.end();
++it;
--it;
while (it != ite)
{
	std::cout << "*it = "<< *it << std::endl << "it++" << std::endl;
	++it;
}
std::stack<int> s(mstack);
return 0;
}