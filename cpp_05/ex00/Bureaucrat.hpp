#pragma once

#include <iostream>

class Bureaucrat
{
    public:
        Bureaucrat (const std::string &name, int grade);
        Bureaucrat (const Bureaucrat &src);
        Bureaucrat(void);
        ~Bureaucrat(void);

		Bureaucrat &operator=(Bureaucrat const &src);
		Bureaucrat &operator++(void);
		Bureaucrat  operator++(int);
		Bureaucrat &operator--(void);
		Bureaucrat  operator--(int);

		void	IncrementGrade();
		void	DecrementGrade();

		int GetGrade() const;
		const std::string &GetName() const;

		static const int MIN_BUREAUCRAT_GRADE = 150;
		static const int MAX_BUREAUCRAT_GRADE = 1;

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
		const 	std::string _name;
		int 	_grade;
};
		
std::ostream &operator<<(std::ostream &oStream, Bureaucrat &value);

