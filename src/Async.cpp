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
	 auto debrecen = std::async( std::launch::async, GetCityForecast, std::string("Debrecen") );
	 auto lima     = std::async( std::launch::async, GetCityForecast, "Lima" );
	 auto norberg  = std::async( std::launch::async, GetCityForecast, "Norberg" );
	 auto piemonte = std::async( std::launch::async, GetCityForecast, "Piemonte" );

	 // Perform other tasks here while temperatures get fetched
	 std::this_thread::sleep_for(std::chrono::seconds(8));

	 std::cout << "Temperature Forecasts: " << std::endl;
	 std::cout << "Debrecen: " << debrecen.get() << std::endl;
	 std::cout << "Lima: "     << lima.get() << std::endl;
	 std::cout << "Norberg: "  << norberg.get() << std::endl;
	 std::cout << "Piemonte: " << piemonte.get() << std::endl;
}



int Async::GetCityForecast( const std::string& city )
{
	// Fake calulation time
	int delay = 2 + std::rand() % 6;
	std::this_thread::sleep_for(std::chrono::seconds(delay));
	std::cout << "Calculated: " << city << std::endl;
	int temperature = -5 + std::rand() % 40;
	return temperature;
}
