#include "Span.hpp"

int main()
{
	std::cout << "\033[33m----------Nomal test----------\033[0m" << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "\033[34mshortest span\033[0m" << std::endl;
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << "\033[34mlongest span\033[0m" << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << std::endl;

	std::cout << "\033[33m----------Out of size----------\033[0m" << std::endl;
	try {
		sp.addNumber(7);
	} catch (Span::CannotAddException &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "\033[33m----------Not enough values----------\033[0m" << std::endl;
	Span sp2 = Span(5);
	std::cout << "\033[34msize 0\033[0m" << std::endl;
	try {
		std::cout << sp2.shortestSpan() << std::endl;
	} catch (Span::NotEnoughValuesException &e) {
		std::cerr << e.what() << std::endl;
	}
	sp2.addNumber(6);
	std::cout << "\033[34msize 1\033[0m" << std::endl;
	try {
		std::cout << sp2.shortestSpan() << std::endl;
	} catch (Span::NotEnoughValuesException &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "\033[33m----------10000 values test----------\033[0m" << std::endl;
	Span sp3(10000);
	std::srand(static_cast<unsigned int>(std::time(0)));
    std::vector<int> vec(10000);
    std::vector<int>::iterator it = vec.begin();
    for (int i = 0; i < 10000; ++i, ++it) {
        *it = std::rand() % 100000 + 1; 
    }
	sp3.addNumbers(vec.begin(),vec.end());
	std::cout << "\033[34mshortest span\033[0m" << std::endl;
	std::cout << sp3.shortestSpan() << std::endl;
	std::cout << "\033[34mlongest span\033[0m" << std::endl;
	std::cout << sp3.longestSpan() << std::endl;
	return 0;
}