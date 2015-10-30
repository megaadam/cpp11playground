#ifndef FORTYTWO_H_
#define FORTYTWO_H_
#ifdef _WIN32
#define __PRETTY_FUNCTION__ __FUNCSIG__
#endif

#include <string>

class FortyTwo {
public:
	FortyTwo();
	FortyTwo(const std::string& s);
	FortyTwo(double d);
	FortyTwo(int i);

	virtual ~FortyTwo();

	void PrintMembers() const;

	const std::string& GetStr() const;
	double GetDouble() const;
	int GetInt() const;

private:
	const std::string m_s = "Forty-Two";
	double m_d = 42.0L;
	int m_i = 42;
};

#endif /* FORTYTWO_H_ */
