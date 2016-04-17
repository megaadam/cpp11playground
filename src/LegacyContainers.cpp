#include "LegacyContainers.h"
#include <iostream>

LegacyContainers::LegacyContainers() {
	m_movieCities.push_back( "Hollywood" );
	m_movieCities.push_back( "Bollywood" );
	m_movieCities.push_back( "Filmstaden" );
	m_movieCities.push_back( "Cinecitta" );
	m_movieCities.push_back( "Avala Film" );

	m_countryCodes[ 36 ] = "Hungary";
	m_countryCodes[ 91 ] = "India";
	m_countryCodes[ 46 ] = "Sweden";
	m_countryCodes[ 1 ] = "USA";
}

LegacyContainers::~LegacyContainers() {

}

void LegacyContainers::ListCities() const
{
	std::cout << "Cool movie cities in the world: " << std::endl;
	for( std::vector<std::string>::const_iterator city = m_movieCities.begin(); city != m_movieCities.end(); ++city )
	{
		std::cout << *city << std::endl;
	}
}

void LegacyContainers::ListCodes() const
{
	std::cout << std::endl << "Some country codes in the world: " << std::endl;

	for (std::map<int, std::string>::const_iterator pair = m_countryCodes.begin(); pair != m_countryCodes.end(); ++pair)
	{
		std::cout << pair->first << "\t" << pair->second << std::endl;
	}
}

