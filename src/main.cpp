#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include "../include/mineSweeper.h"
#include "../include/colors.h"
#include "../include/split.h"

int main(int argc, char **argv){
    int xPos, yPos;
    bool gameOver = false;
    vector<string> v;
    string input;

    clearScreen();
    cout << BOLD(FBLU("| ---------- Welcome To MineSweeper ---------- |")) << endl;
    cout << FCYN("       ========== The classic ========== ") << endl;
    mineSweeper mS;
    mS.init_grid();
    mS.print_grid();

    while((!gameOver)&&(input != "q")&&(input != "Q")){
		cout << "Enter a Row, Column coordinate (example: 1,2) or press q to quit: ";
		cin >> input;
		if(input.length() > 2){
			try{
				v = split(input);
				xPos = std::stoi(v[0]);
				yPos = std::stoi(v[1]);
				if((xPos >= 0 && xPos < ROW)&&(yPos >= 0 && yPos < COL)){
					ms.mark(xPos,yPos);
					clearScreen();
					std::cout << title;
					ms.print_grid();
					if(ms.getMineHit()){
						gameOver = true;
						std::cout << "You hit a mine!\n- Game Over -" << std::endl;
					} else if(ms.gameWon()){
						gameOver = true;
						std::cout << "Congratulations!\n- You beat Minesweeper! -" << std::endl;
					}
				} else {
					std::cout << "Please use integers in the range of 0 to " << domain << '\n';
				}
			}
			catch(int e){
				std::cerr << "An Exception Occurred. " << e << std::endl;;
			}
		}
		else if(input !="q" && input !="Q") {
			std::cout << "Please use 2 integers in the range of 0 to " << domain << " separated by a comma\n";
		}
	}

    return 0;
}