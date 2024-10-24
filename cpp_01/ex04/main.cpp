#include "main.hpp"

using namespace std;

static int	open_fstreams(fstream& istream, fstream& ostream, char *fname)
{
	istream.open(fname, ios::in);
	ostream.open(strcat(fname, ".replace"), ios::out);
	
	if (!istream.is_open() || !ostream.is_open())
	{
		cout << "Error file not found" << endl;
		return (-1);
	}
	return (0);
}

static void	replace(string& line, char *s1, char *s2)
{
	size_t begin;
	size_t len;
	
	begin = line.find(s1);
	len = strlen(s1);
	while (begin != string::npos)
	{
		line.replace(begin, len, s2);
		begin = line.find(s1, begin);
	}
}

int main(int argc, char **argv)
{
	fstream	istream;
	fstream	ostream;
	string 	line;
	char			*fname;
	char			*s1;
	char			*s2;
	
	if (argc != 4 || argv[1][0] == '\0' || argv[2][0] == '\0' || argv[3][0] == '\0')
	{
		cout << "Invalid arguments" << endl;
		return (-1);
	}

	fname = argv[1];
	s1 = strdup(argv[2]);
	s2 = strdup(argv[3]);

	if (open_fstreams(istream, ostream, fname))
		return (-1);
	while (getline(istream, line))
	{
		replace(line, s1, s2);
		ostream << line << endl;
	}
	istream.close();
	ostream.close();
}