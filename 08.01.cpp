#include <iostream>
#include <fstream>
#include <string>
#include "person.h"

std::string br(std::string s)
{
	return s + "</br>";
}

std::string b(std::string s)
{
	return std::string("<b>") + s + "</b>";
}

#define is_nullterm(x)                                                                   \
	std::cout << #x << " : " << (x[x.size()] == 0 ? "YES" : "!! NO !!") << std::endl

std::string replace(std::string s, char c, std::string with)
{
	std::string out { "" };
	for (std::size_t i = 0; i < s.size(); ++i)
	{
		if (s.at(i) == c)
			out += with;
		else
			out += s.at(i);
	}
	return out;
}

int main(int, char**)
{
	std::ifstream tmpl("08_files/webseite.html.tmpl");
	std::ifstream infile("08_files/personendaten.txt");
	std::ofstream outfile("08_files/webseite.html");

	std::string kurz { "" };
	std::string lang { "" };

	do
	{
		std::string line;
		std::getline(infile, line);
		if (line.empty()) break;
		Person p = extrahiere_person(line);

		kurz += br(b(p.nachname) + ", " + p.vorname) + "\n";
		lang += br(b(p.vorname + " " + p.nachname) + ", " + p.geburtsdatum) + "\n";
	} while (!infile.eof());

	do
	{
		std::string out;
		tmpl >> out;
		out = replace(out, '%', kurz);
		out = replace(out, '$', lang);
		outfile << out << std::endl;
	} while (!tmpl.eof());
}
