#include "Enums.h"

#include <iostream>

Enums::Enums() {}

Enums::~Enums() {}

void Enums::TestCast() const
{
	const Car enumCar = Car::BLUE;
	const int intCar = static_cast<int>(enumCar);

	std::cout << "intCar == " << intCar << ", expected 42" << std::endl;

	const Car enumCar2 = static_cast<Car>(42);
	std::cout << "static_cast<Car>(42) SUCCESS, expected." << std::endl;

	const Wine enumWine = static_cast<Wine>(41); // does not throw
	std::cout << "static_cast<Wine>(41) SUCCESS, NOT EXPECTED!!" << std::endl;
	std::cout << "enumWine == " << (int)enumWine << std::endl;
}


void Enums::WineTesting(Wine w) const
{
	if(w == Wine::RED)
	{
		std::cout << "The wine is red" << std::endl;
	}
	else
	{
		std::cout << "The wine sure aint red" << std::endl;
	}
}
