#ifndef ENUMS_H_
#define ENUMS_H_

class Enums {

public:
	Enums();
	virtual ~Enums();

	enum class Colour { RED, GREEN, BLUE };
	enum class Wine { WHITE, RED };

	void WineTesting(Wine w) const;
};

#endif /* ENUMS_H_ */
