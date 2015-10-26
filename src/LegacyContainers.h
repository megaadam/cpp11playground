#include "vector"
#include "string"
#include <iostream>

#ifndef LEGACYCONTAINERS_H_
#define LEGACYCONTAINERS_H_

class LegacyContainers {
public:
	LegacyContainers();
	virtual ~LegacyContainers();

	void ListCities();

private:
	std::vector<std::string> m_movieCities;
};

#endif /* LEGACYCONTAINERS_H_ */
