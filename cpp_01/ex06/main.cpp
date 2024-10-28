#include "Harl.hpp"

using namespace std;

int	main(int ac, char **av) 
{
	if (ac != 2) {
		cout << "[ Probably complaining about insignificant problems ]" << endl; return 0;
	}
	
	Harl	Harl;
	
	Harl.complain(av[1]);
}