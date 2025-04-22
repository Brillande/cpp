#include "Bureaucrat.hpp"

int main(void)
{
    try 
    {
        Bureaucrat maialen("Maialen", 1);
        std::cout << maialen << std::endl;
        for (int i = 0; i < 100; i++)
            maialen.DecrementGrade();
        std::cout << maialen << std::endl;
        for (int i = 0; i < 50; i++)
            maialen.IncrementGrade();
        std::cout << maialen << std::endl;
        for (int i = 0; i < 200; i++)
            maialen.DecrementGrade();
        std::cout << maialen << std::endl;
    } 
    catch (const std::exception &e) 
    {
        std::cerr << "Maialen "<< e.what() << std::endl;
    }

    try 
    {
        Bureaucrat ellande("Ellande", 300);
        std::cout << ellande << std::endl;
    }
    catch (const Bureaucrat::GradeLowException &e)
    {
        std::cerr << "Ellande " << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeHighException &e)
    {
        std::cerr << "Ellande " << e.what() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Ellande " << e.what() << std::endl;
    }

    try 
    {
        Bureaucrat ugo("Ugo ", 0);
        std::cout << ugo << std::endl;
    }
    catch (const Bureaucrat::GradeLowException &e)
    {
        std::cerr << "Ugo " << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeHighException &e)
    {
        std::cerr << "Ugo " << e.what() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Ugo " << e.what() << std::endl;
    }

    try 
    {
        Bureaucrat luis("Luis Maria", 1);
        std::cout << luis << std::endl;
    }
    catch (const Bureaucrat::GradeLowException &e)
    {
        std::cerr << "Luis Maria "<< e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeHighException &e)
    {
        std::cerr << "Luis Maria "<< e.what() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Luis Maria "<< e.what() << std::endl;
    }    
}