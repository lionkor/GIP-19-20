#ifndef MYRECTANGLE_H
#define MYRECTANGLE_H

class MyRectangle
{
public:
    MyRectangle(int x1 = 0, int y1 = 0, int x2 = 20, int y2 = 20);

    virtual void draw() const;
    bool         does_not_collide_with(const MyRectangle&) const;

    int x1() const { return m_x1; }
    int y1() const { return m_y1; }
    int x2() const { return m_x2; }
    int y2() const { return m_y2; }

    void set_x1(int x1) { m_x1 = x1; }
    void set_y1(int y1) { m_y1 = y1; }
    void set_x2(int x2) { m_x2 = x2; }
    void set_y2(int y2) { m_y2 = y2; }

    void set(int x1, int x2, int y1, int y2) {
        m_x1 = x1;
        m_y1 = y1;
        m_x2 = x2;
        m_y2 = y2;
    }

protected:
    int m_x1;
    int m_y1;
    int m_x2;
    int m_y2;
};

#endif // MYRECTANGLE_H
