#include <iostream>
#define CIMGGIP_MAIN
#include "CImgGIP05.h"
using namespace std;
using namespace cimg_library;

const int grid_size = 10; // Anzahl an Kaestchen in x- und y-Richtung
const int box_size  = 30; // size der einzelnen Kaestchen (in Pixel)
const int border    = 20; // Rand links und oben bis zu den ersten Kaestchen (in Pixel)

// Prototyp der Funktionen zum Vorbelegen des Grids ...
void grid_init(bool grid[][grid_size]);

// clang-format off
unsigned count_alive_cells_around(bool grid[][grid_size], int x, int y)
{
    unsigned count = 0;
    for (int i = -1; i <= 1; ++i)
    {
        for (int k = -1; k <= 1; ++k)
        {
            if (!(i == 0 && k == 0) && 
                x + i >= 0 && 
                x + i < grid_size && 
                y + k >= 0 && 
                y + k < grid_size &&
                grid[x + i][y + k])
                ++count;
        }
    }
    return count;
}
// clang-format on

void process_cell(bool old_grid[][grid_size], bool grid[][grid_size], int x, int y)
{
    unsigned count = count_alive_cells_around(old_grid, x, y);

    if (!old_grid[x][y] && count == 3)
    {
        grid[x][y] = true;
    }
    else if (old_grid[x][y] && count != 2 && count != 3)
    {
        grid[x][y] = false;
    }
}

int main()
{
    bool grid[grid_size][grid_size]      = { 0 };
    bool next_grid[grid_size][grid_size] = { 0 };

    // Erstes Grid vorbelegen ...
    grid_init(grid);

    while (gip_window_not_closed())
    {
        // Spielfeld anzeigen ...
        gip_stop_updates(); // ... schaltet das Neuzeichnen nach jeder Bildschirmaenderung aus

        for (int x = 0; x < grid_size; ++x)
        {
            for (int y = 0; y < grid_size; ++y)
            {
                auto color = white;
                if (grid[x][y])
                    color = green;
                gip_draw_rectangle(border + x * box_size, border + y * box_size, border + x * box_size + box_size,
                                   border + y * box_size + box_size, color);
            }
        }

        gip_start_updates(); // ... alle Bildschirmaenderungen (auch die nach dem gip_stop_updates()
                             // ) wieder anzeigen

        gip_sleep(1);

        // Berechne das naechste Spielfeld ...
        // Achtung; Fuer die Zelle (x,y) darf die Position (x,y) selbst *nicht*
        // mit in die Betrachtungen einbezogen werden.
        // Ausserdem darf bei zellen am rand nicht ueber den Rand hinausgegriffen
        // werden (diese Zellen haben entsprechend weniger Nachbarn) ...

        for (int x = 0; x < grid_size; ++x)
        {
            for (int y = 0; y < grid_size; ++y)
            {
                process_cell(grid, next_grid, x, y);
            }
        }

        // Kopiere das naechste Spielfeld in das aktuelle Spielfeld ...
        for (int x = 0; x < grid_size; ++x)
        {
            for (int y = 0; y < grid_size; ++y)
            {
                grid[x][y] = next_grid[x][y];
            }
        }
    }
    return 0;
}


void grid_init(bool grid[][grid_size])
{
    int eingabe = -1;
    do
    {
        cout << "Bitte waehlen Sie die Vorbelegung des Grids aus:" << endl
             << "0 - Zufall" << endl
             << "1 - Statisch" << endl
             << "2 - Blinker" << endl
             << "3 - Oktagon" << endl
             << "4 - Gleiter" << endl
             << "5 - Segler 1 (Light-Weight Spaceship)" << endl
             << "6 - Segler 2 (Middle-Weight Spaceship)" << endl
             << "? ";

        cin >> eingabe;
        cin.clear();
    } while (eingabe < 0 || eingabe > 6);

    if (eingabe == 0)
    {
        // Erstes Grid vorbelegen (per Zufallszahlen) ...

        for (int x = 0; x < grid_size; ++x)
        {
            for (int y = 0; y < grid_size; ++y)
            {
                grid[x][y] = static_cast<bool>(gip_random(0, 1));
            }
        }
    }
    else if (eingabe == 1)
    {
        const int pattern_size                        = 3;
        char      pattern[pattern_size][pattern_size] = {
            { '.', '*', '.' },
            { '*', '.', '*' },
            { '.', '*', '.' },
        };
        for (int y = 0; y < pattern_size; y++)
            for (int x = 0; x < pattern_size; x++)
                if (pattern[y][x] == '*')
                    grid[x][y + 3] = true;
    }
    else if (eingabe == 2)
    {
        const int pattern_size                        = 3;
        char      pattern[pattern_size][pattern_size] = {
            { '.', '*', '.' },
            { '.', '*', '.' },
            { '.', '*', '.' },
        };
        for (int y = 0; y < pattern_size; y++)
            for (int x = 0; x < pattern_size; x++)
                if (pattern[y][x] == '*')
                    grid[x][y + 3] = true;
    }
    else if (eingabe == 3)
    {
        // clang-format off
        const int pattern_size                        = 8;
        char      pattern[pattern_size][pattern_size] = {
            { '.', '.', '.', '*', '*', '.', '.', '.' }, 
            { '.', '.', '*', '.', '.', '*', '.', '.' },
            { '.', '*', '.', '.', '.', '.', '*', '.' }, 
            { '*', '.', '.', '.', '.', '.', '.', '*' },
            { '*', '.', '.', '.', '.', '.', '.', '*' }, 
            { '.', '*', '.', '.', '.', '.', '*', '.' },
            { '.', '.', '*', '.', '.', '*', '.', '.' }, 
            { '.', '.', '.', '*', '*', '.', '.', '.' },
        };
        // clang-format on
        for (int y = 0; y < pattern_size; y++)
            for (int x = 0; x < pattern_size; x++)
                if (pattern[y][x] == '*')
                    grid[x][y + 1] = true;
    }
    else if (eingabe == 4)
    {
        const int pattern_size                        = 3;
        char      pattern[pattern_size][pattern_size] = {
            { '.', '*', '.' },
            { '.', '.', '*' },
            { '*', '*', '*' },
        };
        for (int y = 0; y < pattern_size; y++)
            for (int x = 0; x < pattern_size; x++)
                if (pattern[y][x] == '*')
                    grid[x][y + 3] = true;
    }
    else if (eingabe == 5)
    {
        // clang-format off
        const int pattern_size                        = 5;
        char      pattern[pattern_size][pattern_size] = {
            { '*', '.', '.', '*', '.' }, 
            { '.', '.', '.', '.', '*' }, 
            { '*', '.', '.', '.', '*' },
            { '.', '*', '*', '*', '*' }, 
            { '.', '.', '.', '.', '.' },
        };
        // clang-format on

        for (int y = 0; y < pattern_size; y++)
            for (int x = 0; x < pattern_size; x++)
                if (pattern[y][x] == '*')
                    grid[x][y + 3] = true;
    }
    else if (eingabe == 6)
    {
        // clang-format off
        const int pattern_size                        = 6;
        char      pattern[pattern_size][pattern_size] = {
            { '.', '*', '*', '*', '*', '*' }, 
            { '*', '.', '.', '.', '.', '*' }, 
            { '.', '.', '.', '.', '.', '*' },
            { '*', '.', '.', '.', '*', '.' }, 
            { '.', '.', '*', '.', '.', '.' }, 
            { '.', '.', '.', '.', '.', '.' },
        };
        // clang-format on
        for (int y = 0; y < pattern_size; y++)
            for (int x = 0; x < pattern_size; x++)
                if (pattern[y][x] == '*')
                    grid[x][y + 3] = true;
    }
}

