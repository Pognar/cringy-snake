#ifndef GAME_HPP
#define GAME_HPP
#include "baseclass.hpp"
#include "head.hpp"
#include "body.hpp"
#include "apple.hpp"
#include "score.hpp"
#include <ncurses.h>
#include <chrono>


class game
{
    public:
    game();
    game(int y, int x);
    ~game();
    void loop_game(int difficulty);
    void p_input();
    void snake_mover();
    void game_over();
    void start();
    void display(base_class* dyn_ptr);



    private:
    static const int EXIT = 5;

    int max_rows = 0;
    int max_columns = 0;
    int dead = 0;
    using Clock = std::chrono::high_resolution_clock;
    
    head * h_ptr = new head();
    body * b_ptr = new body();
    apple * a_ptr = new apple();
    score * s_ptr = new score();

    enum direction {UP = 0, DOWN, RIGHT, LEFT};
    direction v_direction;

    int y_pos = 10;
    int x_pos = 10;
    int mover = 0;
    
    

};


#endif