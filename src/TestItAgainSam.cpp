#include "TestItAgainSam.h"
#include <vector>
#include <string>

#include "LegacyContainers.h"
#include "Containers.h"

#include "LegacyFortyTwo.h"
#include "FortyTwo.h"

#include "LegacyEnums.h"
#include "Enums.h"

#include "Async.h"

#include "MemoryBlock.h"

using namespace Car;

TestItAgainSam::TestItAgainSam() {}

TestItAgainSam::~TestItAgainSam() {}

void TestItAgainSam::Run() const
{
	//TestLegacyContainers();
	//TestContainers();

	//TestLegacy42();
	//Test42();

	//TestLegacyEnums();
	//TestEnums();

	TestAsync(); 

	//TestMove();

	_sleep(50000);
}

void TestItAgainSam::TestLegacyContainers() const
{
	LegacyContainers cont;
	cont.ListCities();
	cont.ListCodes();
}

void TestItAgainSam::TestContainers() const
{
	Containers cont;
	cont.ListCities();
	cont.ListCodes();

}

void TestItAgainSam::TestLegacy42() const
{
	std::cout << std::endl;

	std::vector<LegacyFortyTwo*> lftVec;
	lftVec.push_back( new LegacyFortyTwo() );
	lftVec.push_back( new LegacyFortyTwo( "Seven    " ) );
	lftVec.push_back( new LegacyFortyTwo( 7.0 ) );
	lftVec.push_back( new LegacyFortyTwo( 7 ) );

	for(std::vector<LegacyFortyTwo*>::const_iterator lftIter = lftVec.begin(); lftIter != lftVec.end(); ++lftIter )
	{
		(*lftIter)->PrintMembers();
	}
}

void TestItAgainSam::Test42() const
{
	std::cout << std::endl;

	std::vector<FortyTwo> ftVec = {
									FortyTwo(),
	 	 	 	 	 	 	 	 	FortyTwo( "Seven    " ),
									FortyTwo( 7.0 ),
									FortyTwo( 7 )
								  };
	for( auto& ft: ftVec )
	{
		ft.PrintMembers();
	}
}

void TestItAgainSam::TestLegacyEnums() const
{
	LegacyEnums le;
	// Why does this fail ?
	le.WineTesting(RED);
}






void TestItAgainSam::TestEnums() const
{
	Enums e;
	e.WineTesting(Enums::Wine::RED);
}

void TestItAgainSam::TestAsync() const
{
	Async a;
	a.GetForecasts();
}

void TestItAgainSam::TestMove() const
{
//	MemoryBlock mb1( 100 );
//	MemoryBlock mb2( 200 );
//
//	mb2 = mb1;

	std::vector<MemoryBlock> vec;

	vec.push_back(MemoryBlock(2000));
	vec.insert(vec.begin(), MemoryBlock(1000));

	std::cout << "Exit test: " << __PRETTY_FUNCTION__ << std::endl;
}
