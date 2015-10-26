#include <iostream>
#include "Enums.h"

Enums::Enums() {}

Enums::~Enums() {}

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
