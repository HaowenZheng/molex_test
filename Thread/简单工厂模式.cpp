#include <iostream>
#include <memory>
#include <string>


//# 和 ## 用法
//#将后面的宏参数字符串化
#define WARN_IF(EXP) if(EXP)\
std::cout<<#EXP<<std::endl;\
else std::cout<<"error"<<std::endl;\

//##将带参数的宏定义参数链接起来，形成新的子串；不可以是第一个也不能是最后一个
#define _CONS(a,b) std::string str = "1";\
str = "io"##a##b##"io";\
std::cout<<str<<std::endl;\

//#define CONN(str) A##str##MyName;
#include "..\testdll\TestAdd.h"

#pragma comment(lib,"..\\Debug\\testdll.lib")

class CRegister
{
public:
	CRegister();
};


#define REGISTER_PRODUCT(product) 


//抽象产品类
class AbstractSportPorduct
{
public:
	AbstractSportPorduct(){}
	virtual ~AbstractSportPorduct() {};

	//抽象方法
	virtual void PrintName() = 0;
	virtual void Play() = 0;
};

//具体产品类
class BasketBall :public::AbstractSportPorduct
{
public:
	BasketBall() {
		PrintName();
		Play();
	}

	virtual void PrintName() override
	{
		std::cout << "this is BasketBall" << std::endl;
	}

	virtual void Play() override
	{
		std::cout << "we are playing BasketBall" << std::endl;
	}
};

class FootBall :public::AbstractSportPorduct
{
public:
	FootBall()
	{
		PrintName();
		Play();
	}

	virtual void PrintName() override
	{
		std::cout << "this is FootBall" << std::endl;
	}

	virtual void Play() override
	{
		std::cout << "we are playing FootBall" << std::endl;
	}
};

class VolleyBall :public::AbstractSportPorduct
{
public:
	VolleyBall()
	{
		PrintName();
		Play();
	}

	virtual void PrintName() override
	{
		std::cout << "this is VolleyBall" << std::endl;
	}

	virtual void Play() override
	{
		std::cout << "we are playing VolleyBall" << std::endl;
	}
};


//定义工厂类及方法
//定义虚的工厂类
class IFactory
{
public:
	virtual std::shared_ptr<AbstractSportPorduct> GetSportProduct(std::string productName) = 0;
	/*{
		std::shared_ptr<AbstractSportPorduct> pPro = nullptr;
		if (productName == "BasketBall")
		{
			pPro = std::shared_ptr<AbstractSportPorduct>(new BasketBall());
		}
		else if (productName == "FootBall")
		{
			pPro = std::shared_ptr<AbstractSportPorduct>(new FootBall());
		}
		else if (productName == "VolleyBall")
		{
			pPro = std::shared_ptr<AbstractSportPorduct>(new VolleyBall());
		}

		return pPro;
	}*/
};


//定义实际工厂类
class cFactory :public IFactory
{
public:
	virtual std::shared_ptr<AbstractSportPorduct> GetSportProduct(std::string productName)
	{
		std::shared_ptr<AbstractSportPorduct> pPro = nullptr;
		if (productName == "BasketBall")
		{
			//pPro = std::shared_ptr<AbstractSportPorduct>(new BasketBall()); //不安全 shared_ptr 分两部分， 一部分指针，一部分记录指针使用个数
			pPro = std::dynamic_pointer_cast<AbstractSportPorduct>(std::make_shared<BasketBall>());
		}
		else if (productName == "FootBall")
		{
			pPro = std::shared_ptr<AbstractSportPorduct>(new FootBall());
		}
		else if (productName == "VolleyBall")
		{
			pPro = std::shared_ptr<AbstractSportPorduct>(new VolleyBall());
		}

		return pPro;
	}
};


void main()
{
	/*int i = 100;
	WARN_IF(i == 100);

	_CONS("hi","baby");*/

	/*std::shared_ptr<IFactory> fac = std::make_shared<cFactory>();

	if (fac == nullptr)
		std::cout << "error ptr" << std::endl;

	fac->GetSportProduct("BasketBall");

	fac->GetSportProduct("FootBall");

	fac->GetSportProduct("VolleyBall");
*/


	
	try
	{
		add(2, 3);
	}
	catch (int& n)
	{
		printf("error code %d\r\n", n);




	}

	//add(2, 3);
	system("pause");
}