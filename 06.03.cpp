#include <iostream>
#define CIMGGIP_MAIN
#include "CImgGIP05.h"

int main()
{
    const int left_border = 100;
    const int right_border = 500;
    const int rectangle_size = 50;

    int x = 200;
    int y = 300;
    int delta = 10;

    gip_white_background();

    while (gip_window_not_closed())
    {
        gip_draw_rectangle(
                left_border,    100, 
                right_border,  500,
                blue);

        gip_draw_rectangle(
                x                 , y,
                x + rectangle_size, y + rectangle_size,
                white);

        gip_wait(100);
    }
    return 0;
}
