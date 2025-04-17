#include "Bureaucrat.hpp"

//constructor and desctructor

Bureaucrat::Bureaucrat(void)
{
    std::cout << "default constructor" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
    std::cout << "copy contructor called" << std::endl;
    if(this != &src)
        *this = src;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
    std::cout << "name and grade constructor" << std::endl;
    if (grade > MIN_BUREAUCRAT_GRADE)
        throw(GradeLowException());
     if (grade < MAX_BUREAUCRAT_GRADE)
        throw(GradeHighException());
    
    _grade = grade;
}

Bureaucrat::~Bureaucrat(void)
{
    std::cout << "destructor called" << std::endl;
}

//getters

int Bureaucrat::GetGrade() const
{
    return(_grade);
}

const std::string &Bureaucrat::GetName() const
{
    return(_name);
}

//son metodos modificadores.
void Bureaucrat::IncrementGrade() 
{
    (*this)++; 
}

void Bureaucrat::DecrementGrade() 
{
    (*this)--;
}

//overload

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &src) 
{
    if (this == &src)
        return (*this);
    _grade = src.GetGrade();
    return (*this);
}

Bureaucrat &Bureaucrat::operator++(void) 
{
    _grade--;
    if (_grade < MAX_BUREAUCRAT_GRADE)
        throw GradeHighException();
    return (*this);
}

Bureaucrat Bureaucrat::operator++(int) 
{
    Bureaucrat old = *this;
    _grade--;
    if (_grade < MAX_BUREAUCRAT_GRADE)
        throw GradeHighException();
    return (old);
}

Bureaucrat &Bureaucrat::operator--(void) 
{
    _grade++;
    if (_grade > MIN_BUREAUCRAT_GRADE)
        throw GradeLowException();
    return (*this);
}
Bureaucrat Bureaucrat::operator--(int) 
{
    Bureaucrat old = *this;
    _grade++;
    if (_grade > MIN_BUREAUCRAT_GRADE)
        throw GradeLowException();
    return (old);
}

//Permite que puedas imprimir objetos de tipo Bureaucrat directamente con std::cout

std::ostream &operator<<(std::ostream &oStream, Bureaucrat &value) {
    oStream << value.GetName() << " bureaucrat grade " << value.GetGrade() << ".";
    return (oStream);
}

//exceptions

const char *Bureaucrat::GradeLowException::what(void) const throw()
{
	return ("Grade too low");
}

const char *Bureaucrat::GradeHighException::what(void) const throw()
{
	return ("Grade too high");
}