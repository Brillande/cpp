#include "Base.hpp"

// Destructor virtual de Base: necesario para polimorfismo
Base::~Base()
{
	std::cout << "destructor base" << std::endl;
}

// Genera aleatoriamente una instancia de A, B o C
// Usa la instrucción de hardware _rdrand32_step para generar un número aleatorio
Base *generate(void) 
{
  unsigned int random_value;
  // Genera un número aleatorio de 32 bits usando instrucciones de hardware
  _rdrand32_step(&random_value);

  // Usa el módulo 3 para obtener un valor entre 0 y 2
  switch (random_value % 3) 
  {
	case 0:		// 33% de probabilidad
		std::cout << "create a class A" << std::endl;
		return new A;	// Retorna puntero a A como Base*
	case 1:		// 33% de probabilidad
		std::cout << "create a class B" << std::endl;
		return new B;	// Retorna puntero a B como Base*
	default:	// 33% de probabilidad (cuando random_value % 3 == 2)
		std::cout << "create a class C" << std::endl;
		return new C;	// Retorna puntero a C como Base*
  }
}


// Identifica el tipo real del objeto usando un puntero
// dynamic_cast con punteros: retorna NULL si el cast falla (no lanza excepción)
void identify(Base* p) 
{
	// Intenta hacer cast a A*: si es válido, p es de tipo A
	if (dynamic_cast<A *>(p))
		std::cout << "is A class" << std::endl;
	// Intenta hacer cast a B*: si es válido, p es de tipo B
	else if(dynamic_cast<B *>(p))
		std::cout << "is B class" << std::endl;
	// Intenta hacer cast a C*: si es válido, p es de tipo C
	else if (dynamic_cast<C *>(p))
		std::cout << "is C class" << std::endl;
	// Si ninguna coincidencia, no es A, B ni C
	else
		std::cout << "isent class A, B or C" << std::endl;
}

// Identifica el tipo real del objeto usando una referencia
// dynamic_cast con referencias: lanza std::bad_cast si el cast falla (usa try-catch)
void identify(Base& p) {
	// Intenta hacer cast a A&: si es válido, p es de tipo A
	// Si falla, lanza excepción que capturamos con catch
	try 
	{
		(void)dynamic_cast<A&>(p);	// El cast lanza excepción si p no es de tipo A
		std::cout << "is A class" << std::endl;
	} 
	catch (...)	// Captura cualquier excepción (bad_cast en este caso)
	{
		// Si no es A, continúa verificando B y C
	}

	// Intenta hacer cast a B&: si es válido, p es de tipo B
	try 
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "is B class" << std::endl;
	} 
	catch (...)
	{
		// Si no es B, continúa verificando C
	}

	// Intenta hacer cast a C&: si es válido, p es de tipo C
	try 
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "is C class" << std::endl;
	} 
	catch (...) 
	{
		// Si no es C, no es A, B ni C (aunque no se imprime mensaje en este caso)
	}
}