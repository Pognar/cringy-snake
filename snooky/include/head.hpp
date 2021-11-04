#ifndef HEAD_HPP
#define HEAD_HPP
#include "baseclass.hpp"
#include <ncurses.h>
#include <vector>
#include <array>


class head : public base_class
{
    public:
    head();
    ~head();

    void set_up(int y, int x); //sets default positions for the snake
    void draw();
    std::array<int, 2>get_coordinates();
    



    private:
    std::array<int, 2> head_coordinates;

};


#endif //HEAD_HPP