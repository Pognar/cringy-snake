#include "score.hpp"
#include <ncurses.h>



score::score()
{

}
score::~score()
{

}

void score::draw()
{
    mvwprintw(stdscr, 0, 0, "Score: %d", this->points);
}
void score::score_increased()
{
    this->points +=1;
}

