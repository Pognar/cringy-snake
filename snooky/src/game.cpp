#include "game.hpp"
#include "ncurses.h"
#include <vector>
#include <chrono>



game::game(int rows, int columns) : max_rows(rows), max_columns(columns)
{

}

game::~game()
{
    delete h_ptr;
    delete b_ptr;
    delete s_ptr;
    delete a_ptr;
    //delete base_ptr;

}

void game::display(base_class *dyn_ptr)
{
    dyn_ptr->draw();
}

void game::start()
{
    srand(time(NULL));
    nodelay(stdscr, true);
    keypad(stdscr, true);
    curs_set(0);
    noecho();
    h_ptr->set_up(5, 5);
    b_ptr->start_pos(4, 4);
    a_ptr->set_up(max_rows, max_columns);

}

void game::game_over()
{
    std::array<int,2> head_coor = h_ptr->get_coordinates();
    std::vector<std::array<int, 2>> body_coor = b_ptr->get_whole_body();
    
    if(head_coor[0] == 0 || head_coor[1] == 0 || head_coor[0] == max_rows-1 || head_coor[1] == max_columns-1)
    {
        this->dead = 1;
    }
    for(int i = 1; i < body_coor.size(); i++)
    {
        if(body_coor[i][0] == y_pos && body_coor[i][1] == x_pos)
        {
            this->dead = 1;
        }
    }

}

void game::loop_game(int difficulty)
{
    const Clock::duration TARGET_DELTA = std::chrono::milliseconds(difficulty);
    Clock::time_point past = Clock::now();
    Clock::duration delta = TARGET_DELTA;

    if(difficulty!=EXIT)
    {   
        start();
        display(s_ptr);
        display(h_ptr);
        display(b_ptr);
        display(a_ptr);

        while(dead!=1)
        {
            box(stdscr, 0, 0);
            display(s_ptr);
            display(h_ptr);
            display(b_ptr);
            display(a_ptr);
            p_input();
            Clock::time_point now = Clock::now();
            delta += now - past;
            past = now;
            if(delta >= TARGET_DELTA)
            {
                delta -= TARGET_DELTA;
                clear();
                snake_mover();
                display(s_ptr);
                display(h_ptr);
                display(b_ptr);
                display(a_ptr);

            }
        }
        endwin();
    }
}

void game::p_input()
{
    
    //this->mover = wgetch(base_ptr->arena);
    this->mover = wgetch(stdscr);
        switch(this->mover)
        {
        case KEY_UP:
            if(v_direction == DOWN){break;}
            this->v_direction = UP;
            break;
        case KEY_DOWN:
            if(v_direction == UP){break;}
            this->v_direction = DOWN;
            break;
        case KEY_RIGHT:
            if(v_direction == LEFT){break;}
            this->v_direction = RIGHT;
            break;
        case KEY_LEFT:
            if(v_direction == RIGHT){break;}
            this->v_direction = LEFT;
            break;
        default:
            break;
        }
}



//kollar ifall det finns ett äpple svans
void game::snake_mover()
{
    std::array<int,2> apple_pos = a_ptr->get_coordinates();

    if(this->y_pos == apple_pos[0] && this->x_pos == apple_pos[1])
    {
        s_ptr->score_increased();
        b_ptr->start_pos(this->y_pos, this->x_pos);
        b_ptr->set_up(this->y_pos, this->x_pos);
        a_ptr->set_up(max_rows-3, max_columns-3);
    }
    else
    {
        b_ptr->set_up(this->y_pos, this->x_pos);
        game_over();
    }
    switch(v_direction)
    {
        case UP:
            this->y_pos--;
            h_ptr->set_up(this->y_pos, this->x_pos);
            break;
        case DOWN:
            this->y_pos++;
            h_ptr->set_up(this->y_pos, this->x_pos);
            break;
        case RIGHT:
            this->x_pos++;
            h_ptr->set_up(this->y_pos, this->x_pos);
            break;
        case LEFT:
            this->x_pos--;
            h_ptr->set_up(this->y_pos, this->x_pos);
            break;
        default:
            break;

    }

}