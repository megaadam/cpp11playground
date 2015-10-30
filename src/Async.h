#ifndef ASYNC_H_
#define ASYNC_H_
#ifdef _WIN32
#define __PRETTY_FUNCTION__ __FUNCSIG__
#endif

#include <string>

class Async {
public:
	Async();
	virtual ~Async();

	void GetForecasts() const;

	static int GetCityForecast( const std::string& city );
};

#endif /* ASYNC_H_ */
