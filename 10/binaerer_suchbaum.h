#ifndef SUCHBAUM_H
#define SUCHBAUM_H

namespace Suchbaum
{
struct BaumKnoten
{
    int         value;
    BaumKnoten* parent;
    BaumKnoten* left_child;
    BaumKnoten* right_child;
};

void einfuegen(BaumKnoten*& head, int value);
void ausgeben(BaumKnoten* head);
void knoten_ausgeben(BaumKnoten* node, int depth);

} // namespace Suchbaum

#endif // SUCHBAUM_H

