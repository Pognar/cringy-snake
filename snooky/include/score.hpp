#ifndef SCORE_HPP
#define SCORE_HPP
#include "baseclass.hpp"
#include <ncurses.h>

class score : public base_class
{
    public:
    score();
    ~score();
    void draw();
    void score_increased();

    private:
    int points = 0;
};

#endif //SCORE_HPP