#include "Bureaucrat.hpp"

int main(void)
{
    try 
    {
        Bureaucrat Maialen("Maialen", 1);
        std::cout << Maialen << std::endl;
        for (int i = 0; i < 100; i++)
            Maialen.DecrementGrade();
        std::cout << Maialen << std::endl;
        for (int i = 0; i < 50; i++)
            Maialen.IncrementGrade();
        std::cout << Maialen << std::endl;
        for (int i = 0; i < 200; i++)
            Maialen.DecrementGrade();
        std::cout << Maialen << std::endl;
    } 
    catch (const std::exception &e) 
    {
        std::cerr << "Maialen "<< e.what() << std::endl;
    }

    try 
    {
        Bureaucrat Ellande("Ellande", 300);
        std::cout << Ellande << std::endl;
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
        Bureaucrat Ugo("Ugo ", 0);
        std::cout << Ugo << std::endl;
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
        Bureaucrat Luis("Luis Maria", 1);
        std::cout << Luis << std::endl;
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