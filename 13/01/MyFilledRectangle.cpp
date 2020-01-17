#include "MyFilledRectangle.h"
#include "CImgGIP05.h"
#include <iostream>

void MyFilledRectangle::draw() const {
    MyRectangle::draw();

    if (m_x2 - m_x1 <= 4 || m_y2 - m_y1 <= 4)
        return; // too small

    for (int y = m_y1 + 2; y < m_y2 - 2; ++y) {
        gip_draw_line(m_x1 + 2, y, m_x2 - 2, y, red);
    }
}
