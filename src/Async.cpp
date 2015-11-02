#include "Async.h"
#include <iostream>
#include <future>
#include <chrono>
#include <ctime>
#include <thread>
#include <random>
#include <cstdlib>

int takeFive() {return 5;}

Async::Async() {}

Async::~Async() {}

void Async::GetForecasts() const
{
	 auto debrecen = std::async( GetCityForecast, std::string("Debrecen") );
	 auto lima = std::async( GetCityForecast, "Lima" );
	 auto norberg = std::async( GetCityForecast, "Norberg" );
	 auto piemonte = std::async( GetCityForecast, "Piemonte" );

	 // Perform other tasks here while temperatures get fetched

	 std::cout << "Temperature Forecasts: " << std::endl;
	 std::cout << "Debrecen: " << debrecen.get() << std::endl;
	 std::cout << "Lima: " << lima.get() << std::endl;
	 std::cout << "Norberg: " << norberg.get() << std::endl;
	 std::cout << "Piemonte: " << piemonte.get() << std::endl;
}



int Async::GetCityForecast( const std::string& city )
{
	auto seed = reinterpret_cast<const __int64_t>(&city);
	std::srand(seed);

	// Fake calulation time
	int delay = 2 + std::rand() % 8;
	std::this_thread::sleep_for(std::chrono::seconds(delay));

	int temperature = -5 + std::rand() % 40;
	return temperature;
}
