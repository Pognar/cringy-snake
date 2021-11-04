#include "baseclass.hpp"
#include "head.hpp"
#include <ncurses.h>
#include <iostream>
#include <array>


head::head()
{

}
head::~head()
{

}


void head::set_up(int y, int x)
{
    this->head_coordinates = {y, x};
}

void head::draw()
{
    mvwprintw(stdscr, head_coordinates[0], head_coordinates[1], "O");

}

std::array<int,2> head::get_coordinates()
{

    return this->head_coordinates;

}