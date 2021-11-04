#include "body.hpp"
#include "baseclass.hpp"


body::body()
{

}

body::~body()
{

}

void body::start_pos(int y, int x)
{
    std::array<int,2>body_start = {y, x};
    body_coordinates.push_back(body_start);
}

void body::set_up(int y, int x) //move
{
    for(int i = body_coordinates.size()-1; i > 0; i--)
    {
        body_coordinates[i][0] = body_coordinates[i-1][0];
        body_coordinates[i][1] = body_coordinates[i-1][1];
    }
    body_coordinates[0][0] = y;
    body_coordinates[0][1] = x;
}

void body::draw()
{
    for(int i = 0; i < body_coordinates.size(); i++)
    {
        mvwprintw(stdscr, body_coordinates[i][0], body_coordinates[i][1], "o");
        wrefresh(stdscr);
    }
}

std::vector<std::array<int, 2>>body::get_whole_body()
{
    return body_coordinates;
}
