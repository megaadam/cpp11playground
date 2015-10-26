#ifndef ASYNC_H_
#define ASYNC_H_

#include <string>

class Async {
public:
	Async();
	virtual ~Async();

	void GetForecasts() const;

	static int GetCityForecast( std::string city );
};

#endif /* ASYNC_H_ */
