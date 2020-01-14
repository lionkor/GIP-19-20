#ifndef CIMGMOCK_H
#define CIMGMOCK_H

const unsigned char
    white[]
    = { 255, 255, 255 };

const unsigned char
    black[]
    = { 0, 0, 0 };

const unsigned char
    red[]
    = { 255, 0, 0 };

const unsigned char
    green[]
    = { 0, 255, 0 };

const unsigned char
    blue[]
    = { 0, 0, 255 };

const unsigned int gip_win_sizeX = 600;
const unsigned int gip_win_sizeY = 600;

// Fenstergroesse X
// Fenstergroesse Y
inline void gip_draw_rectangle(unsigned int x0, unsigned int y0,
    unsigned int x1, unsigned int y1, const unsigned char* const color = black) {}


#endif // CIMGMOCK_H
