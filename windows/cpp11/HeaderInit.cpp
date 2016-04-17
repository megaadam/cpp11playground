#include "HeaderInit.h"

#include <iostream>

HeaderInit::HeaderInit()
{
}

HeaderInit::HeaderInit(int a, int b, int c): m_a(a), m_b(b), m_random(c)
{

}

HeaderInit::HeaderInit(int a, int b): m_a(a), m_b(b)
{

}

HeaderInit::HeaderInit(int a): m_a(a)
{

}


void HeaderInit::PrintMembers()
{
	std::cout << "m_a: " << m_a << ", m_b: " << m_b << ", m_random: " << m_random << std::endl << std::endl;
}

HeaderInit::~HeaderInit()
{
}
