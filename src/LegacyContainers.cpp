#include "LegacyContainers.h"

LegacyContainers::LegacyContainers() {
	m_movieCities.push_back( "Hollywood" );
	m_movieCities.push_back( "Bollywood" );
	m_movieCities.push_back( "Filmstaden" );
	m_movieCities.push_back( "Cinecitta" );
	m_movieCities.push_back( "Avala Film" );
}

LegacyContainers::~LegacyContainers() {

}

void LegacyContainers::ListCities()
{
	std::cout << "Cool movie cities in the world: " << std::endl;
	for(std::vector<std::string>::const_iterator city = m_movieCities.begin(); city != m_movieCities.end(); ++city  )
	{
		std::cout << *city << std::endl;
	}
}

