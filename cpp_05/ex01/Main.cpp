#include "Form.hpp"

int main(void)
{

    try 
    {
        Form ellande("ellande", 10, 1);
		std::cout << ellande << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "ellande" << e.what() << std::endl;
	}

    try 
    {
        Form maialen("maialen", 109, 0);
		std::cout << maialen << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "maialen " << e.what() << std::endl;
	}

    try 
    {
        Form Ugo("ugo", 5, 160);
		std::cout << Ugo << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Ugo " << e.what() << std::endl;
	}

    try 
    {
        Form Luis("Luis Maria", 5, 20);
		std::cout << Luis << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Luis Maria " << e.what() << std::endl;
	}

    try 
    {
        Form charo("charo", 300, 20);
		std::cout << charo << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "charo " << e.what() << std::endl;
	}

    try 
    {
        Form koldo("koldo", 0, 20);
		std::cout << koldo << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "koldo " << e.what() << std::endl;
	}
}