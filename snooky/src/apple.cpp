#include "apple.hpp"
#include <stdlib.h>
#include <array>



apple::apple()
{

}

apple::~apple()
{

}

void apple::start_pos(int y, int x)
{
    this->apple_coordinates = {y, x}; //->this apple
}

void apple::draw()
{
   mvwprintw(stdscr, this->apple_coordinates[0], this->apple_coordinates[1], "@");
}

void apple::set_up(int max_rows, int max_columns)
{
    srand(time(NULL));
    int y_apple = rand() % (max_rows-2)+1;
    int x_apple = rand() % (max_columns-2)+1;
    start_pos(y_apple, x_apple);
    
}

std::array<int,2> apple::get_coordinates()
{

    return apple_coordinates; //this->apple

}
