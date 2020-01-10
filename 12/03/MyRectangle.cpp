#include "MyRectangle.h"
#include "CImgGIP05Mock.h"

MyRectangle::MyRectangle(int x1, int y1, int x2, int y2)
    : x1(x1), y1(y1), x2(x2), y2(y2) {
}

void MyRectangle::draw() const {
    gip_draw_rectangle(x1, y1, x2, y2, blue);
}

bool MyRectangle::does_not_collide_with(const MyRectangle& other) const {
    return !(x1 <= other.x2 && x2 >= other.x1 && y1 <= other.y2 && y2 >= other.y1);
}
