#include "Containers.h"
#include <iostream>

Containers::Containers() {}

Containers::~Containers() {}

void Containers::ListCities() const
{
	std::cout << std::endl << "Cool movie cities in the world: " << std::endl;

	// Pop-quiz: What can be improved here?
	for(auto city: m_movieCities)
	{
		std::cout << city << std::endl;
	}
}

void Containers::ListCodes() const
{
	std::cout << std::endl << "Some country codes in the world: " << std::endl;

	// Pop-quiz: What can be improved here?
	for(auto pair: m_countryCodes)
	{
		std::cout << pair.first << "\t" << pair.second << std::endl;
	}
}

const std::vector<std::string> Containers::m_movieCities =
{
	"Hollywood",
	"Bollywood",
	"Filmstaden",
	"Cinecitta",
	"Avala Film"
};

const std::map<int, std::string> Containers::m_countryCodes =
{
		{ 36, "Hungary" },
		{ 91, "India" },
		{ 46, "Sweden" },
		{ 1, "USA" }
};
