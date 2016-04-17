#ifndef HEADERINIT_H_
#define HEADERINIT_H_
#include <random>

class HeaderInit
{
public:
	HeaderInit();
	HeaderInit(int a, int b, int c);
	HeaderInit(int a, int b);
	HeaderInit(int a);
	~HeaderInit();

	void PrintMembers();

private:
	int m_a = 1;
	int m_b = 2;
	int m_random = -(std::rand() % 100);
};
#endif

