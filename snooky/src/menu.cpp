#include "menu.hpp"
#include <ncurses.h>
#include <string>

menu::menu(){

}
menu::~menu(){

}

int menu::main_menu()
{
    clear();
    draw();
    WINDOW * wi_menu = newwin(7, 20, 9, 0);
    box(wi_menu, 0, 0);
    wprintw(wi_menu, "Select Difficulty");
    refresh();
    wrefresh(wi_menu);
    keypad(wi_menu, true);
    while(1)
    {
        for(int i = 0; i < 5; i++)
        {
            if(i == this->highlighter)
            {
                wattron(wi_menu, A_REVERSE);
            }
            mvwprintw(wi_menu, i+1, 1, new_game[i].c_str());
            wattroff(wi_menu, A_REVERSE);
        }
        this->choice = wgetch(wi_menu);
        switch(this->choice)
        {
            case KEY_UP:
                if(this->highlighter != 0){this->highlighter--;}
                break;
            case KEY_DOWN:
                if(this->highlighter != 4){this->highlighter++;}
                break;
            default:
                break;
        }
        if(this->choice==10)
        {
            break;
        }
    }
    if(highlighter == 0)
    {
        return_diff = 200;//boa
    }
    else if(highlighter == 1)
    {
        return_diff = 100;//Rattler
    }
    else if(highlighter == 2)
    {
        return_diff = 50;//Mamba
    }
    else if(highlighter == 3)
    {
        return_diff = 25;//Sidewinder
    }    
    else 
    {
        return_diff = 5;//Exit
    }
    wclear(wi_menu);
    endwin();
    return return_diff;

}


void menu::draw()
{
    printw(
        R"(
	      ._.___
 	     (\ (\\0\
	       \   \.)
	       /~  /\|    
	      /___/ \)		     Welcome to 
	        (\___\)    Snake using ncurses by pognar          
		  \___\)              o 
		   \___\)             O   
		    \___\)           ()      
                     \___\)          //  
		      \___\)        // 
                       \___\)      //       
                        \___\)     \\
               __________\___\_____/_\_______.
              (/X/X/X/X/X/\___\/X/X/X/X/X/X/X \
	      (____________\___\_______________))");

}
