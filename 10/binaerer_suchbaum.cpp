#include "binaerer_suchbaum.h"
#include <cassert>
#include <iostream>

void insert(Suchbaum::BaumKnoten*& head, Suchbaum::BaumKnoten* node)
{
    Suchbaum::BaumKnoten* current = head;
    while (current)
    {
        if (node->value == current->value)
        {
            delete node;
            return;
        }

        if (node->value < current->value)
        {
            if (current->left_child)
                current = current->left_child;
            else
            {
                current->left_child = node;
                break;
            }
        }

        else if (node->value > current->value)
        {
            if (current->right_child)
                current = current->right_child;
            else
            {
                current->right_child = node;
                break;
            }
        }
    }
}

void Suchbaum::einfuegen(Suchbaum::BaumKnoten*& head, int value)
{
    BaumKnoten* node  = new BaumKnoten;
    node->value       = value;
    node->parent      = nullptr;
    node->left_child  = nullptr;
    node->right_child = nullptr;

    if (!head)
    {
        head = node;
        return;
    }

    insert(head, node);
}

void Suchbaum::ausgeben(BaumKnoten* head)
{
    knoten_ausgeben(head, 0);
}

void Suchbaum::knoten_ausgeben(BaumKnoten* node, int depth)
{
    if (!node)
    {
        std::cout << "Leerer Baum." << std::endl;
        return;
    }

    if (node->right_child)
        knoten_ausgeben(node->right_child, depth + 1);

    for (int i = 0; i < depth; ++i)
        std::cout << "++";

    std::cout << node->value << std::endl;

    if (node->left_child)
        knoten_ausgeben(node->left_child, depth + 1);
}
