#include "Async.h"
#include <iostream>
#include <future>
#include <chrono>
#include <thread>
#include <random>
#include <cstdlib>

int takeFive() {return 5;}

Async::Async() {}

Async::~Async() {}

void Async::GetForecasts() const
{
	 //std::future<int> debrecen = std::async( GetCityForecast, std::string("Debrecen") );
	 std::future<int> d2 = std::async( takeFive );
//	 auto lima = std::async( GetCityForecast, "Lima" );
//	 auto norberg = std::async( GetCityForecast, "Norberg" );
//	 auto piemonte = std::async( GetCityForecast, "Piemonte" );
//
//	 // Perform other tasks here while temperatures get fetched
//


	 int i = d2.get();
	 std::cout << "Temperature Forecasts: " << std::endl;
//	 std::cout << "Debrecen: " << debrecen.get() << std::endl;
//	 std::cout << "Lima: " << lima.get() << std::endl;
//	 std::cout << "Norberg: " << norberg.get() << std::endl;
//	 std::cout << "Piemonte: " << piemonte.get() << std::endl;

}



int Async::GetCityForecast( std::string city )
{
	return 5;
//	int delay = 2 + std::rand() % 8;
//	std::this_thread::sleep_for (std::chrono::seconds(delay));
//
//	int temperature = -5 + std::rand() % 40;
//	return temperature;
}
