#include <iostream>
#include <memory>
#include <string>


//# �� ## �÷�
//#������ĺ�����ַ�����
#define WARN_IF(EXP) if(EXP)\
std::cout<<#EXP<<std::endl;\
else std::cout<<"error"<<std::endl;\

//##���������ĺ궨����������������γ��µ��Ӵ����������ǵ�һ��Ҳ���������һ��
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


//�����Ʒ��
class AbstractSportPorduct
{
public:
	AbstractSportPorduct(){}
	virtual ~AbstractSportPorduct() {};

	//���󷽷�
	virtual void PrintName() = 0;
	virtual void Play() = 0;
};

//�����Ʒ��
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


//���幤���༰����
//������Ĺ�����
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


//����ʵ�ʹ�����
class cFactory :public IFactory
{
public:
	virtual std::shared_ptr<AbstractSportPorduct> GetSportProduct(std::string productName)
	{
		std::shared_ptr<AbstractSportPorduct> pPro = nullptr;
		if (productName == "BasketBall")
		{
			//pPro = std::shared_ptr<AbstractSportPorduct>(new BasketBall()); //����ȫ shared_ptr �������֣� һ����ָ�룬һ���ּ�¼ָ��ʹ�ø���
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