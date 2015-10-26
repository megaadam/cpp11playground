#include "LegacyFortyTwo.h"
#include <iostream>

LegacyFortyTwo::LegacyFortyTwo(): m_s( "Forty-Two" ), m_d( 42.0L ), m_i( 42 ) { }

LegacyFortyTwo::LegacyFortyTwo(const std::string& s): m_s( s ), m_d( 42.0L ), m_i( 42 ) { }

LegacyFortyTwo::LegacyFortyTwo( double d ): m_s( "Forty-Two" ), m_d( d ), m_i( 42 ) { }

LegacyFortyTwo::LegacyFortyTwo( int i ): m_s( "Forty-Two" ), m_d( 42.0L ), m_i( i ) { }

void LegacyFortyTwo::PrintMembers() const
{
	std::cout << __PRETTY_FUNCTION__ << " | members: " << m_s << "\t " << m_d << "\t " << m_i << std::endl;
}

LegacyFortyTwo::~LegacyFortyTwo()
{

}


const std::string& LegacyFortyTwo::GetStr() const
{
	return m_s;
}

double LegacyFortyTwo::GetDouble() const
{
	return m_d;
}

int LegacyFortyTwo::GetInt() const
{
	return m_i;
}
