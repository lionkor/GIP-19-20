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
    for (const char& c : str) {
        ptr->set_next(new CharListenKnoten(c));
        ptr = ptr->get_next();
    }
}

MyString2::MyString2(const MyString2& str)
    : m_anker(str.deep_copy()) {
}

MyString2& MyString2::operator=(const MyString2& str) {
    delete_all();
    m_anker = str.deep_copy();
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
    // TODO
}
