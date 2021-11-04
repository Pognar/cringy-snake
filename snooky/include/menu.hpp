#ifndef MENU_HPP
#define MENU_HPP
#include "baseclass.hpp"
#include <string>

class menu : public base_class
{

    public:
    menu();
    ~menu();

    int main_menu();
    void welcome();
    void draw();


    private:
    std::string new_game[5] = {"Boa", "Rattler", "Mamba", "Sidewinder", "Exit"};
    int highlighter = 0;
    int choice = 0;
    int return_diff = 0;

};




#endif //MENU_HPP