#include "easyfind.hpp"
#include <set>

int main() {
	std::set<int> mySet;
	mySet.insert(1);
	mySet.insert(2);
	mySet.insert(3);
	mySet.insert(4);
	mySet.insert(5);
	std::cout << "myset = ";
	for (std::set<int>::iterator it = mySet.begin(); it != mySet.end(); ++it) {
		std::cout << *it << " ";
	}
    std::cout << std::endl;
    std::cout << std::endl;
	std::cout << "\033[34m*easyfind(mySet,3)\033[0m" << std::endl;
	try {
		std::cout << *easyfind(mySet,3) << std::endl;

	} catch (NotFindInteger &e) {
		std::cerr << e.what() << std::endl;
	}
    std::cout << std::endl;
	std::cout << "\033[34m*easyfind(mySet,7)\033[0m" << std::endl;
	try {
		std::cout  << *easyfind(mySet,7) << std::endl;

	} catch (NotFindInteger &e) {
		std::cerr << e.what() << std::endl;
	}
    std::cout << std::endl;
}