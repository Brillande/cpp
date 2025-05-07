#include "Base.hpp"

Base::~Base()
{
	std::cout << "destructor base" << std::endl;
}

Base *generate(void) 
{
  unsigned int random_value;
  _rdrand32_step(&random_value);

  switch (random_value % 3) 
  {
	case 0:
		std::cout << "create a class A" << std::endl;
		return new A;
	case 1:
		std::cout << "create a class B" << std::endl;
		return new B;
	default:
		std::cout << "create a class C" << std::endl;
		return new C;
  }
}


void identify(Base* p) 
{
	if (dynamic_cast<A *>(p))
		std::cout << "is A class" << std::endl;
	else if(dynamic_cast<B *>(p))
		std::cout << "is B class" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "is C class" << std::endl;
	else
		std::cout << "isent class A, B or C" << std::endl;
}

void identify(Base& p) {
	try 
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "is A class" << std::endl;
	} 
	catch (...) 
	{

	}

	try 
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "is B class" << std::endl;
	} 
	catch (...)
	{

	}

	try 
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "is C class" << std::endl;
	} 
	catch (...) 
	{
		
	}
}