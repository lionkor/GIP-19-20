#ifndef MYRECTANGLE_H
#define MYRECTANGLE_H

class MyRectangle
{
public:
    MyRectangle(int, int, int, int);

    void draw() const;
    bool does_not_collide_with(const MyRectangle&) const;

private:
    int x1;
    int y1;
    int x2;
    int y2;
};

#endif // MYRECTANGLE_H
