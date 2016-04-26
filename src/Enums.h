#ifndef ENUMS_H_
#define ENUMS_H_
#ifdef _WIN32
#define __PRETTY_FUNCTION__ __FUNCSIG__
#endif

class Enums {

public:
	Enums();
	virtual ~Enums();

	enum class Car { RED, GREEN, BLUE = 42 };
	enum class Wine { WHITE, RED };

	void TestCast() const;
	void WineTesting(Wine w) const;

};

#endif /* ENUMS_H_ */
