#include <vector>
#include <map>
#include <string>

#ifndef CONTAINERS_H_
#define CONTAINERS_H_

class Containers {
public:
	Containers();
	virtual ~Containers();

	void ListCities() const;
	void ListCodes() const;

private:
	static const std::vector<std::string> m_movieCities;
	static const std::map<int, std::string> m_countryCodes;
};

#endif
