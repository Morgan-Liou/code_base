#include <stdio.h>

void test_cycle();
void test_struct();
void test_typecast();
//static unsigned char Braking_Holding_Counter[2] = { 0, 0 };

void main()
{
	//test_cycle();
	//test_struct();
	//test_typecast();

	int i;
	i = 0;
}

void test_typecast()
{
	unsigned char a, b;
	a = (unsigned char)266.6f;
	b = 1;
}
void test_cycle()
{
	for (int i = 0; i < 5; i++)
	{

	}

	int none = 0;
}
void test_struct()
{
	typedef struct LLL
	{
		unsigned char abc : 2;
	}LLL_T;

	LLL_T A;


	A.abc = 1;
	A.abc = 2;
	A.abc = 3;
	A.abc = 4;
}