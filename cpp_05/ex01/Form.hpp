#pragma once

#include <iostream>
#include "Bureaucrat.hpp"
class Form
{
  public:
    Form (const std::string &Name, int MinimumGradeSign, int MinimumGradeExecute);
    Form (const Form &Src);
    Form ();
    ~Form ();

    Form &operator=(Form const &src);

    const std::string &GetName() const;
    bool               GetIsSigned() const;
    int                GetMinimumGradeSign() const;
    int                GetMinimumGradeExecute() const;

	  void				BeSign(const Bureaucrat &b);

  private:
    std::string _Name;
    bool        _IsSigned;
    const int   _MinimumGradeSign;
    const int   _MinimumGradeExecute;

    void _CheckGrade() const;
};

std::ostream& operator<<(std::ostream& o, const Form& a);