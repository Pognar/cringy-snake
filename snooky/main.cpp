#include "baseclass.hpp"
#include "head.hpp"
#include "game.hpp"
#include "menu.hpp"
#include <ncurses.h>
#include <iostream>
/*
This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/


int main()
{
    initscr();
    menu * menu_ptr = new menu();
    int rows = 0;
    int columns = 0;
    int difficulty;
    int * exit = &difficulty;
    getmaxyx(stdscr, rows, columns);
    while(difficulty != 5) 
    {
        difficulty = menu_ptr->main_menu();
        game m_loop(rows, columns);
        m_loop.loop_game(difficulty);
    }
    endwin();
    delete menu_ptr;
    return 0;
}
