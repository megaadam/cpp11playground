#ifndef LEGACYCONTAINERS_H_
#define LEGACYCONTAINERS_H_
#ifdef _WIN32
#define __PRETTY_FUNCTION__ __FUNCSIG__
#pragma warning(disable : 4996)
#endif

#include <vector>
#include <string>
#include <map>


class LegacyContainers {
public:
	LegacyContainers();
	virtual ~LegacyContainers();

	void ListCities() const;
	void ListCodes() const;

private:
	std::vector<std::string> m_movieCities;
	std::map<int, std::string> m_countryCodes;
};

#endif /* LEGACYCONTAINERS_H_ */
