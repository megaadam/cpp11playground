#ifndef LEGACYFORTYTWO_H_
#define LEGACYFORTYTWO_H_
#ifdef _WIN32
#define __PRETTY_FUNCTION__ __FUNCSIG__
#endif

#include <string>

class LegacyFortyTwo {
public:
	LegacyFortyTwo();
	LegacyFortyTwo(const std::string& s);
	LegacyFortyTwo(double d);
	LegacyFortyTwo(int i);

	virtual ~LegacyFortyTwo();

	void PrintMembers() const;

	const std::string& GetStr() const;
	double GetDouble() const;
	int GetInt() const;

private:
	std::string m_s;
	double m_d;
	int m_i;
};

#endif /* LEGACYFORTYTWO_H_ */
