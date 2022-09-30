#include "TestAdd.h"



TestAdd::TestAdd()
{
}


TestAdd::~TestAdd()
{
}

int OUT_API_FUNC add(int a, int b)
{
	throw 2;
	return a+b;
}
