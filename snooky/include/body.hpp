#ifndef BODY_HPP
#define BODY_HPP
#include "baseclass.hpp"
#include <vector>
#include <array>

class body : public base_class
{
    public:
    body();
    ~body();
    void set_up(int y, int x);
    void draw();
    void start_pos(int start_y, int start_x);
    std::vector<std::array<int, 2>>get_whole_body();


    private:
    std::vector<std::array<int, 2>> body_coordinates = {};



};



#endif //BODY_HPP