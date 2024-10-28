
#include "Harl.hpp"

using namespace std;

Harl::Harl() 
{

}

Harl::~Harl() 
{

}

void	Harl::debug() const 
{
	cout << "[DEBUG] - I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << endl;
}

void	Harl::info() const 
{
	cout << "[INFO] - I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << endl;
}

void	Harl::warning() const 
{
	cout << "[WARNING] - I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << endl;
}

void	Harl::error() const 
{
	cout << "[ERROR] - This is unacceptable ! I want to speak to the manager now.";
}

void	Harl::complain(str level) 
{
	void	(Harl::*ptr)(void) const = NULL;
	void	(Harl::*array[4])(void) const = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	str		arrayLevel[4] = {"debug", "info", "warning", "error"};
	int		i = -1;

	while (i < 4) 
    {
		if (arrayLevel[i] == level)
			ptr = array[i];
        i++;
	}
	if (!ptr) 
    {
		cout << "Invalid Harl!" << endl; return;
	}
	(this->*ptr)();
}