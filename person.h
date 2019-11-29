#ifndef PERSON_H
#define PERSON_H

#include <string>

struct Person
{
    std::string vorname;
    std::string nachname;
    std::string geburtsdatum;
};

Person extrahiere_person(std::string eingabezeile);

#endif//PERSON_H
