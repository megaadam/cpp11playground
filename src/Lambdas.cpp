#include "Lambdas.h"
#include <iostream>
#include <vector>
#include <algorithm>

void Lambdas::TestAnimals()
{
	int cats = 42;
	int dogs = 13;
	int tigers = 6;
	int elephants = 1;

	auto countAnimals =
        [](auto a, auto b){ std::cout << "total: " << a + b << std::endl; };

	std::cout << "Cats and dogs ";
	countAnimals(cats, dogs);

	std::cout << "Tigers and elephants ";
	countAnimals(tigers, elephants);
}

void Lambdas::TestCountIf()
{
	std::vector<int> n = {2, 3, 5, 7, 12};

	std::cout <<
		"Even numbers: " <<
		std::count_if(n.begin(), n.end(), [](int i) {return i % 2 == 0;}) <<
		std::endl;

	std::cout <<
		"Odd numbers: " <<
		std::count_if(n.begin(), n.end(), [](int i) {return i % 2 != 0;}) <<
		std::endl;
}


void Lambdas::TestCapture()
{
	int myMoney = 1000;
	auto addSome = [&myMoney](int addition){ myMoney += addition; };
	auto multiplySome = [&myMoney](int mult){ myMoney *= mult; };
	++myMoney;
	auto printMoney = [myMoney](){ std::cout << "My Money: " << myMoney << std::endl; };
	// Can you see a bug above?

	printMoney();

	addSome(11);
	printMoney();

	multiplySome(3);
	printMoney();
}
