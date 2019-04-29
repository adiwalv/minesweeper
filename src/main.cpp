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
		cout << "Enter a Row, Column co-ordinate (example: 1,2) or press q to quit: ";
		cin >> input;
		if(input.length() > 2){
			try{
				v = split(input);
				xPos = stoi(v[0]);
				yPos = stoi(v[1]);
				if((xPos >= 0 && xPos < row)&&(yPos >= 0 && yPos < col)){
					mS.mark(xPos,yPos);
					clearScreen();
                    cout << BOLD(FBLU("| ---------- Welcome To MineSweeper ---------- |")) << endl;
    cout << FCYN("       ========== The classic ========== ") << endl;
    
					mS.print_grid();
					if(mS.getMineHit()){
						gameOver = true;
						cout <<BOLD(FRED( "You hit a mine!\n- Game Over -" ))<< std::endl;
					} else if(mS.gameWon()){
						gameOver = true;
						cout <<BOLD(FGRN( "Congratulations!\n- You beat Minesweeper! -" ))<< endl;
					}
				} else {
					cout << BOLD(FRED("Please use integers in the range of 0 to " ))<< domain << '\n';
				}
			}
			catch(int e){
				cerr << "An Exception Occurred. " << e << std::endl;;
			}
		}
		else if(input !="q" && input !="Q") {
			cout << BOLD(FRED("Please use 2 integers in the range of 0 to ")) << domain << BOLD(FRED(" separated by a comma\n"));
		}
	}

    return 0;
}