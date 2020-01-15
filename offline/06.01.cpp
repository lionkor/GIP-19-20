#include <iostream>
#include <string>
using namespace std;

void spalte_ab_erstem(char zeichen, std::string eingabe, std::string& erster_teil, std::string& zweiter_teil);

int main() {
    string input, eteil, zteil;
    char   zeichen;

    cout << "Bitte geben Sie die einzeilige Zeichenkette ein: ? ";
    getline(cin, input);
    cout << "Bitte geben Sie das Zeichen ein: ? ";
    cin >> zeichen;
    spalte_ab_erstem(zeichen, input, eteil, zteil);

    cout << "Der erste Teil der Zeichenkette lautet: " << eteil << endl;
    cout << "Der zweite Teil der Zeichenkette lautet: " << zteil << endl;
}

void spalte_ab_erstem(char zeichen, std::string eingabe, std::string& erster_teil, std::string& zweiter_teil) {
    bool found = false;
    for (const char& c : eingabe) {
        if (c == zeichen) {
            found = true;
            continue; // skip the char
        }

        if (found)
            zweiter_teil += c;
        else
            erster_teil += c;
    }
}
