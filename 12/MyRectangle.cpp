#include "MyRectangle.h"
#include "../CImgGIP05.h"

MyRectangle::MyRectangle(int x1, int y1, int x2, int y2)
    : m_x1(x1), m_y1(y1), m_x2(x2), m_y2(y2) {
}

void MyRectangle::draw() const {
    gip_draw_rectangle(m_x1, m_y1, m_x2, m_y2, blue);
}

bool MyRectangle::does_not_collide_with(const MyRectangle& other) const {
    return m_x1 > other.m_x2 || m_x2 < other.m_x1 || m_y1 > other.m_y2 || m_y2 < other.m_y1;
}
