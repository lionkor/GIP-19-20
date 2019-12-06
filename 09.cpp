#include <iostream>

struct Node
{
	int	  data;
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
		ptr->next			= neuer_eintrag;
	}
}

std::string liste_als_string(Node* anker)
{
	std::string resultat = "";
	if (anker == nullptr)
		return "Leere Liste.";
	else
	{
		resultat += "[ ";
		Node* ptr = anker;
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

std::string liste_als_string_rueckwaerts(Node* anker)
{
	std::string resultat = "";
	if (anker == nullptr)
		return "Leere Liste.";
	else
	{
		Node* current = anker;
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

	if (!anker)
	{
		anker = new Node { wert_neu, nullptr, nullptr };
	}
	else
	{
		Node* ptr = anker;
		while (ptr->next)
		{
			if (ptr->data == vor_wert)
				break;
			ptr = ptr->next;
		}
		if (ptr->data == vor_wert)
		{
			Node* prev	   = ptr->prev;
			new_node->next = ptr;
			new_node->prev = prev;
			ptr->prev	   = new_node;
			if (prev)
				prev->next = new_node;
		}
		else
		{
			ptr->next	   = new_node;
			new_node->prev = ptr;
		}
		if (new_node->next == anker)
			anker = new_node;
		/*
		std::cout << std::hex << new_node << ": \n\tdata: " << new_node->data
				  << ": \n\tnext: " << std::hex << new_node->next
				  << "\n\tprev: " << std::hex << new_node->prev << std::endl;*/
	}
}


int main(int, char**)
{
	const int laenge = 10;
	Node*	  anker	 = nullptr;

	for (int i = 0; i < laenge; i++)
		in_liste_einfuegen(anker, i * i, 9999);

	liste_ausgeben(anker);
	liste_ausgeben_rueckwaerts(anker);

	int wert_neu = 0, vor_wert = 0;
	std::cout << "Einzufuegender Wert: ";
	std::cin >> wert_neu;
	std::cout << "Vor welchem Wert? ";
	std::cin >> vor_wert;
	in_liste_einfuegen(anker, wert_neu, vor_wert);

	liste_ausgeben(anker);
	liste_ausgeben_rueckwaerts(anker);

	return 0;
}
