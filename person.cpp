#include "person.h"
#include "texte.h"

Person extrahiere_person(std::string line)
{
	Person p { "", "", "" };

	std::string rest;
	split(line, ',', p.nachname, rest);
	split(rest, ',', p.vorname, p.geburtsdatum);


	p.nachname	   = trim(p.nachname, ' ');
	p.nachname	   = trim(p.nachname, '\r');
	p.vorname	   = trim(p.vorname, ' ');
	p.vorname	   = trim(p.vorname, '\r');
	p.geburtsdatum = trim(p.geburtsdatum, ' ');
	p.geburtsdatum = trim(p.geburtsdatum, '\r');

	return p;
}
