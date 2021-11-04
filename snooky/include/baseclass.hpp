#ifndef BASECLASS_HPP
#define BASECLASS_HPP
#include <iostream>
#include <array>
#include <vector>
#include <stdlib.h>
#include <ncurses.h>


class base_class
{
    public:
    base_class(){}
    ~base_class(){}

    std::array<int, 2> head_coordinates;

    virtual void start_pos(int start_y, int start_x)
    {
        std::cout << "START POSITION" << std::endl;
    }

    virtual void set_up(int y, int x) //move
    {
        std::cout << "SETUP" << std::endl;
    }
    
    virtual void draw() = 0;

    virtual std::array<int,2> get_coordinates()
    {
        std::cout << "GETTING COORDINATES" << std::endl;
        std::array<int,2> arr = {0,0};

        return arr;
    }


};


#endif //BASECLASS_HPP