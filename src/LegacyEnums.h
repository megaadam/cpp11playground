#ifndef LEGACYENUMS_H_
#define LEGACYENUMS_H_

namespace Colour
{
	enum Colour { RED, GREEN, BLUE };
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
