#include <iostream>
#define CIMGGIP_MAIN
#include "CImgGIP05.h"

struct Box
{
	int x;
	int y;
	int delta_y;
};

const int box_max = 10, box_size = 40;

void draw_boxes(Box boxes[])
{
	gip_white_background();

	for (std::size_t i = 0; i < box_max; ++i)
	{
		gip_draw_rectangle(boxes[i].x, boxes[i].y, boxes[i].x + box_size,
						   boxes[i].y + box_size, blue);
	}
}

bool update_boxes(Box boxes[])
{
	for (std::size_t i = 0; i < box_max; ++i)
	{
		boxes[i].y += boxes[i].delta_y;
		if (boxes[i].y + box_size > gip_win_size_y) { return false; }
	}
	return true;
}

bool check_collision_AABB(int m_x, int m_y, const Box& box)
{
	return m_x >= box.x && m_x <= box.x + box_size && m_y >= box.y &&
		   m_y <= box.y + box_size;
}

void handle_mouse_click(Box boxes[])
{
	int mouse_x = gip_mouse_x();
	int mouse_y = gip_mouse_y();

	for (std::size_t i = 0; i < box_max; ++i)
	{
		if (check_collision_AABB(mouse_x, mouse_y, boxes[i]))
		{
			boxes[i].delta_y += 10;
			boxes[i].y = 0 - box_size;
		}
	}
}


int main()
{
	Box	 boxes[box_max] { 0 };
	bool keep_going = true;

	for (int i = 0; i < box_max; i++)
	{
		boxes[i].x		 = i * (box_size + 20) + 10;
		boxes[i].y		 = 0;
		boxes[i].delta_y = gip_random(10, 30);
	}

	while (keep_going && gip_window_not_closed())
	{
		draw_boxes(boxes);

		for (int loop_count = 0; loop_count < 200; loop_count++)
		{
			gip_wait(5); // warte 5 Milli-Sekunden
			if (gip_mouse_button1_pressed()) { handle_mouse_click(boxes); }
		}

		keep_going = update_boxes(boxes);
	}

	return 0;
}
