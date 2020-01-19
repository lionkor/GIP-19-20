#ifndef MY_STRING_2_H
#define MY_STRING_2_H

#include "CharListenKnoten.h"
#include <string>

class MyString2
{
private:
    CharListenKnoten* m_anker;

public:
    MyString2();
    MyString2(const std::string&);
    MyString2(const MyString2&);
    MyString2& operator=(const MyString2&);
    ~MyString2();

    CharListenKnoten*       get_anker() { return m_anker; }
    const CharListenKnoten* get_anker() const { return m_anker; }
    void                    set_anker(CharListenKnoten* k) { m_anker = k; }

    void              append(char);
    void              delete_all();
    CharListenKnoten* deep_copy() const;
    unsigned int      length() const;
};

#endif // MY_STRING_2_H
