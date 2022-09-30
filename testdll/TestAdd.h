#pragma once
#include "Header.h"
class TestAdd
{
public:
	TestAdd();
	~TestAdd();
};

#ifdef  TEST_ADD_6396
#define OUT_API_FUNC __declspec(dllexport)
#else
#define OUT_API_FUNC __declspec(dllimport)
#endif //  TEST_ADD_6396

int OUT_API_FUNC add(int a, int b);
