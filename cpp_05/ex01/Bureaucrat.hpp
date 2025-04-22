#pragma once

#include <iostream>

#define MinBureaucratGrade 150
#define MaxBureaucratGrade 1

class Bureaucrat
{
    public:
        Bureaucrat (const std::string &Name, int Grade);
        Bureaucrat (const Bureaucrat &Src);
        Bureaucrat(void);
        ~Bureaucrat(void);

		Bureaucrat &operator=(Bureaucrat const &Src);
		Bureaucrat &operator++(void);
		Bureaucrat  operator++(int);
		Bureaucrat &operator--(void);
		Bureaucrat  operator--(int);

		void	IncrementGrade();
		void	DecrementGrade();

		int GetGrade() const;
		const std::string &GetName() const;

		

		class GradeLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
	private:
		const 	std::string _Name;
		int 	_Grade;
};
		
std::ostream &operator<<(std::ostream &oStream, Bureaucrat &value);

