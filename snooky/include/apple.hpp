#ifndef APPLE_HPP
#define APPLE_HPP
#include "baseclass.hpp"
#include <array>


class apple : public base_class
{

    public:
    apple(int y, int x);
    apple();
    ~apple();

    void set_up(int y, int x);
    void start_pos(int y_newapple, int x_newapple);
    std::array<int, 2>get_coordinates();

    void draw();


    private:
    std::array<int, 2> apple_coordinates;
    

};



#endif //APPLE_HPP