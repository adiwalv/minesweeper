#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include "../include/mineSweeper.h"
#include "../include/colors.h"


int main(int argc, char **argv){
    cout << BOLD(FBLU("| ---------- Welcome To MineSweeper ---------- |")) << endl;
    mineSweeper mS;
    mS.init_grid();
    mS.print_grid();
    return 0;
}