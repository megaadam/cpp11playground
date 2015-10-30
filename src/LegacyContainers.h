#ifndef LEGACYCONTAINERS_H_
#define LEGACYCONTAINERS_H_
#ifdef _WIN32
#define __PRETTY_FUNCTION__ __FUNCSIG__
#pragma warning(disable : 4996)
#endif

#include "vector"
#include "string"
#include <iostream>


class LegacyContainers {
public:
	LegacyContainers();
	virtual ~LegacyContainers();

	void ListCities();

private:
	std::vector<std::string> m_movieCities;
};

#endif /* LEGACYCONTAINERS_H_ */
