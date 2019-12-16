#include <iostream>

struct Node
{
    int   data;
    Node* next;
    Node* prev;
};

void hinten_anfuegen(Node*& anker, const int wert)
{
    Node* neuer_eintrag = new Node;
    neuer_eintrag->data = wert;
    neuer_eintrag->next = nullptr;
    neuer_eintrag->prev = nullptr;

    if (anker == nullptr)
        anker = neuer_eintrag;
    else
    {
        Node* ptr = anker;
        while (ptr->next != nullptr)
            ptr = ptr->next;
        neuer_eintrag->prev = ptr;
        ptr->next           = neuer_eintrag;
    }
}

std::string liste_als_string(const Node* anker)
{
    std::string resultat = "";
    if (anker == nullptr)
        return "Leere Liste.";
    else
    {
        resultat += "[ ";
        const Node* ptr = anker;
        do
        {
            resultat += std::to_string(ptr->data);
            if (ptr->next != nullptr)
                resultat += " , ";
            else
                resultat += " ";
            ptr = ptr->next;
        } while (ptr != nullptr);
        resultat += "]";
    }
    return resultat;
}

std::string liste_als_string_rueckwaerts(const Node* anker)
{
    std::string resultat = "";
    if (anker == nullptr)
        return "Leere Liste.";
    else
    {
        const Node* current = anker;
        while (current->next)
            current = current->next;
        resultat += "[ ";
        do
        {
            resultat += std::to_string(current->data);
            if (current->prev)
                resultat += " , ";
            else
                resultat += " ";
            current = current->prev;
        } while (current);
        resultat += "]";
    }
    return resultat;
}

void liste_ausgeben(Node* anker)
{
    std::cout << liste_als_string(anker) << std::endl;
}

void liste_ausgeben_rueckwaerts(Node* anker)
{
    std::cout << liste_als_string_rueckwaerts(anker) << std::endl;
}

void in_liste_einfuegen(Node*& anker, int wert_neu, int vor_wert)
{
    Node* new_node = new Node;
    new_node->data = wert_neu;
    new_node->next = nullptr;
    new_node->prev = nullptr;

    if (!anker) { anker = new_node; }
    else
    {
        Node* ptr = anker;
        while (ptr->next && ptr->data != vor_wert)
            ptr = ptr->next;

        if (ptr->data == vor_wert)
        {
            Node* prev     = ptr->prev;
            new_node->next = ptr;
            new_node->prev = prev;
            ptr->prev      = new_node;
            if (prev) prev->next = new_node;
        }
        else
        {
            ptr->next      = new_node;
            new_node->prev = ptr;
        }

        if (new_node->next == anker) anker = new_node;
    }
}

void liste_loeschen(Node*& anker)
{
    Node* current = anker;
    while (current != nullptr)
    {
        Node* to_delete = current;
        current         = current->next;
        delete to_delete;
    }
    anker = nullptr;
}

void aus_liste_loeschen(Node*& anker, int wert)
{
    Node* ptr = anker;
    while (ptr && ptr->data != wert)
        ptr = ptr->next;

    if (ptr)
    {
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        // delete ptr;
    }
}

int main(int, char**)
{
    const int laenge = 10;
    Node*     anker  = nullptr;
    liste_ausgeben(anker);
    liste_ausgeben_rueckwaerts(anker);
    liste_loeschen(anker);

    hinten_anfuegen(anker, 77);
    hinten_anfuegen(anker, 88);
    hinten_anfuegen(anker, 99);

    liste_ausgeben(anker);
    liste_ausgeben_rueckwaerts(anker);

    liste_loeschen(anker); // war: aus_liste_loeschen(anker, 99);
    liste_ausgeben(anker);
    liste_ausgeben_rueckwaerts(anker);

    for (int i = 0; i < laenge; i++)
        in_liste_einfuegen(anker, i * i, 9999);

    liste_ausgeben(anker);
    liste_ausgeben_rueckwaerts(anker);

    in_liste_einfuegen(anker, -1, 0);
    in_liste_einfuegen(anker, 24, 25);
    in_liste_einfuegen(anker, 80, 81);
    in_liste_einfuegen(anker, 99, 9999);

    in_liste_einfuegen(anker, 7, 4);

    liste_ausgeben(anker);
    liste_ausgeben_rueckwaerts(anker);

    aus_liste_loeschen(anker, 24);
    aus_liste_loeschen(anker, 80);

    liste_ausgeben(anker);
    liste_ausgeben_rueckwaerts(anker);

    liste_loeschen(anker);

    liste_ausgeben(anker);
    liste_ausgeben_rueckwaerts(anker);

    return 0;
}
