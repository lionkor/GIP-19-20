#include <iostream>
#include <string>

bool expect(char c, std::string &input, int pos);
void match(char c, std::string& input, int& pos);
void parse_number(std::string& input, int& pos);
void parse_operand(std::string& input, int& pos);
void parse_term(std::string& input, int& pos);
void parse_ausdruck(std::string& input, int& pos);
void parse_gesamtausdruck(std::string& input, int& pos);

int main(int, char**)
{
    int pos = 0;
    std::string input = "";
    std::cout << "Bitte geben Sie die Zeichenkette ein: ";
    getline(std::cin, input);
    parse_gesamtausdruck(input, pos);
    if (pos != input.length())
    std::cout << "Error! Noch Input-Zeichen uebrig." << std::endl;
    return 0;    
}

bool expect(char c, std::string &input, int pos)
{
    std::cout << "Teste auf das Zeichen " << c << std::endl;
    if (unsigned(pos) >= input.length())
    {
        std::cout << "Aber schon am Ende der "
            << "Eingabe-Zeichenkette angelangt.\n";
        return false;
    }
    if (input.at(pos) == c)
    {
        std::cout << "Zeichen " << c << " gefunden." << std::endl;
        return true;
    }
    else
    {
        std::cout << "Test auf " << c << " nicht erfolgreich. "
            << "Stattdessen " << input.at(pos)
            << " gesehen.\n";
        return false;
    }
}

void match(char c, std::string& input, int& pos)
{
    std::cout << "Betrete match() fuer das Zeichen " << c << std::endl;
    if (unsigned(pos) >= input.length())
    {
        std::cout << "Input-Zeichenkette zu kurz. "
        << "Erwarte noch das Zeichen " << c << std::endl;
        std::cout << "Verlasse match(): " << std::endl;
    return;
    }
    if (input.at(pos) != c)
    {
        std::cout << "Fehler: an Position "
        << pos << " erwarte "
        << c << " und sehe " << input.at(pos) << std::endl;
        std::cout << "Verlasse match(): " << std::endl;
        return;
    }
    pos++;
    std::cout << "Zeichen " << c << " konsumiert.\n";
    std::cout << "Verlasse match() fuer das Zeichen "
        << c << std::endl;
    

void parse_gesamtausdruck(std::string& input, int& pos)
{
    std::cout << "Betrete parse_gesamtausdruck()" << std::endl;
    parse_ausdruck(input, pos);
    match('.', input, pos);
    std::cout << "Verlasse parse_gesamtausdruck()" << std::endl;
}

void parse_ausdruck(std::string& input, int& pos)
{
    std::cout << "Betrete parse_ausdruck()" << std::endl;
    parse_term(input, pos);
    while (expect('U', input, pos)
           || expect('O', input, pos))
    {
        if (expect('U', input, pos))
        {
            std::cout << "Betrete parse_ausdruck(): U Fall" << std::endl;
            match('U', input, pos);
        }
        else
        {
            std::cout << "Betrete parse_ausdruck(): O Fall" << std::endl;
            match('O', input, pos);
        }
        parse_term(input, pos);
    }
    std::cout << "Verlasse parse_ausdruck()" << std::endl;
}

void parse_term(std::string& input, int& pos)
{
    std::cout << "Betrete parse_term()" << std::endl;
    parse_operand(input, pos);
    while (expect('<', input, pos)
           || expect('>', input, pos))
    {
        if (expect('>', input, pos))
        {
            std::cout << "Betrete parse_term(): > Fall" << std::endl;
            match('>', input, pos);
        }
        else
        {
            std::cout << "Betrete parse_term(): < Fall" << std::endl;
            match('<', input, pos);
        }
        parse_operand(input, pos);
    }
    std::cout << "Verlasse parse_term()" << std::endl;
}

void parse_operand(std::string& input, int& pos)
{
    std::cout << "Betrete parse_operand()" << std::endl;
    // expect number
    if (expect('(', input, pos))
    {
        std::cout << "Betrete parse_operand(): () Fall" << std::endl;
        match('(', input, pos);
        parse_ausdruck(input, pos);
        match(')', input, pos);
    }
    else
    {
        parse_number(input, pos);
    }
    std::cout << "Verlasse parse_operand()" << std::endl;
}

void parse_number(std::string& input, int& pos)
{
    std::cout << "Betrete parse_number()" << std::endl;
    if (expect('0', input, pos))
        match('0', input, pos);
    else if (expect('1', input, pos))
        match('1', input, pos);
    else if (expect('2', input, pos))
        match('2', input, pos);
    else if (expect('3', input, pos))
        match('3', input, pos);
    else if (expect('4', input, pos))
        match('4', input, pos);
    else if (expect('5', input, pos))
        match('5', input, pos);
    else if (expect('6', input, pos))
        match('6', input, pos);
    else if (expect('7', input, pos))
        match('7', input, pos);
    else if (expect('8', input, pos))
        match('8', input, pos);
    else
        match('9', input, pos);
    std::cout << "Verlasse parse_number()" << std::endl;
}
