#include "MyString2.h"

MyString2::MyString2()
    : m_anker(nullptr) {}

MyString2::MyString2(const std::string& str)
    : m_anker(nullptr) {
    if (str.empty()) {
        m_anker = new CharListenKnoten(0);
        return;
    }

    CharListenKnoten* ptr = new CharListenKnoten(str.at(0));
    m_anker               = ptr;
    for (std::size_t i = 1; i < str.size(); ++i) {
        ptr->set_next(new CharListenKnoten(str.at(i)));
        ptr = ptr->get_next();
    }
}

MyString2::MyString2(const MyString2& str)
    : m_anker(str.deep_copy()) {
}

MyString2& MyString2::operator=(const MyString2& str) {
    delete_all();
    m_anker = str.deep_copy();
    return *this;
}


void MyString2::append(char c) {
    if (!m_anker)
        m_anker = new CharListenKnoten(c);
    else {
        CharListenKnoten* ptr = m_anker;
        while (ptr->get_next()) {
            ptr = ptr->get_next();
        }

        ptr->set_next(new CharListenKnoten(c));
    }
}

void delete_recursively(CharListenKnoten* k) {
    if (!k)
        return;
    delete_recursively(k->get_next());
    delete k;
}

void MyString2::delete_all() {
    delete_recursively(m_anker);
    m_anker = nullptr;
}

MyString2::~MyString2() {
    delete_all();
}

CharListenKnoten* MyString2::deep_copy() const {
    if (!m_anker)
        return nullptr;
    CharListenKnoten* new_ptr   = new CharListenKnoten(m_anker->get_data());
    CharListenKnoten* new_anker = new_ptr;
    CharListenKnoten* ptr       = m_anker;
    while (ptr->get_next()) {
        ptr = ptr->get_next();
        new_ptr->set_next(new CharListenKnoten(ptr->get_data()));
        new_ptr = new_ptr->get_next();
    }
    return new_anker;
}

unsigned int MyString2::length() const {
    if (!m_anker)
        return 0;
    unsigned int count = 0;
    for (CharListenKnoten* ptr = m_anker; ptr; ptr = ptr->get_next()) {
        count++;
    }
    return count;
}

char MyString2::at(unsigned int pos) const {
    unsigned int      count = 0;
    CharListenKnoten* ptr   = m_anker;
    while (ptr) {
        if (count == pos)
            return ptr->get_data();
        ptr = ptr->get_next();
        ++count;
    }
    return '\0';
}

MyString2 MyString2::operator+(char c) const {
    MyString2 s(*this);
    s.append(c);
    return s;
}

std::string MyString2::to_string() const {
    std::string s;
    if (!m_anker)
        return s;
    CharListenKnoten* ptr = m_anker;
    while (ptr) {
        s += ptr->get_data();
        ptr = ptr->get_next();
    }
    return s;
}
