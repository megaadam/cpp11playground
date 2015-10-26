#include <iostream>
#include "LegacyEnums.h"

using namespace Wine;

LegacyEnums::LegacyEnums() {}

LegacyEnums::~LegacyEnums() {}

void LegacyEnums::WineTesting(int w) const
{
	if(w == RED)
	{
		std::cout << "The wine is red" << std::endl;
	}
	else
	{
		std::cout << "The wine sure aint red" << std::endl;
	}
}
