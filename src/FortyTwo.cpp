#include "FortyTwo.h"
#include "iostream"

FortyTwo::FortyTwo() { }

FortyTwo::FortyTwo(const std::string& s): m_s( s ) { }

FortyTwo::FortyTwo( double d ):  m_d( d ) { }

FortyTwo::FortyTwo( int i ):  m_i( i ) { }

FortyTwo::~FortyTwo() { }

void FortyTwo::PrintMembers() const
{
	std::cout << __PRETTY_FUNCTION__ << " | members: " << m_s << "\t " << m_d << "\t " << m_i << std::endl;
}

const std::string& FortyTwo::GetStr() const
{
	return m_s;
}

double FortyTwo::GetDouble() const
{
	return m_d;
}

int FortyTwo::GetInt() const
{
	return m_i;
}
