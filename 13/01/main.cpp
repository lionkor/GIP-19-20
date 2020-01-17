#include <iostream>
#define CIMGGIP_MAIN
#include "CImgGIP05.h"

#include "MyFilledRectangle.h"

int main() {
    while (gip_window_not_closed()) {
        int x1_1 = gip_random(0, gip_win_size_x - 1);
        int y1_1 = gip_random(0, gip_win_size_y - 1);
        int x2_1 = gip_random(x1_1, gip_win_size_x - 1);
        int y2_1 = gip_random(y1_1, gip_win_size_y - 1);

        MyFilledRectangle r1(x1_1, y1_1, x2_1, y2_1);

        int x1_2 = gip_random(0, gip_win_size_x - 1);
        int y1_2 = gip_random(0, gip_win_size_y - 1);
        int x2_2 = gip_random(x1_2, gip_win_size_x - 1);
        int y2_2 = gip_random(y1_2, gip_win_size_y - 1);

        MyFilledRectangle r2(x1_2, y1_2, x2_2, y2_2);

        gip_white_background();
        r1.draw();
        r2.draw();

        if (r1.does_not_collide_with(r2))
            gip_draw_text(10, 10, "Keine Kollision.");
        else
            gip_draw_text(10, 10, "Kollision!");

        gip_sleep(4);
    }
    return 0;
}
