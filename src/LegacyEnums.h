#ifndef LEGACYENUMS_H_
#define LEGACYENUMS_H_
#ifdef _WIN32
#define __PRETTY_FUNCTION__ __FUNCSIG__
#endif

namespace Car
{
	enum Car { RED, GREEN, BLUE };
}

namespace Wine
{
	enum Wine { WHITE, RED };
}

class LegacyEnums {

public:
	LegacyEnums();
	virtual ~LegacyEnums();

	void WineTesting(int  w) const;

};

#endif /* ENUMS_H_ */
