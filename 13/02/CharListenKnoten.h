#ifndef CLK_H
#define CLK_H

class CharListenKnoten
{
private:
    CharListenKnoten* next;
    char              data;

public:
    CharListenKnoten(char c = 0)
        : data(c), next(nullptr) {}

    CharListenKnoten*       get_next() { return next; }
    const CharListenKnoten* get_next() const { return next; }
    void                    set_next(CharListenKnoten* k) { next = k; }
    char                    get_data() { return data; }
    void                    set_data(char c) { data = c; }
};

#endif // CLK_H
