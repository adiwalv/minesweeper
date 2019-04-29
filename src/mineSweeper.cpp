#include <iostream>
#include "../include/minesweeper.h"
#include <cstdlib>
#include <time.h>

void clearScreen(){
	system("clear & clear");
}

bool mineSweeper::marked(unsigned x, unsigned y){ 
            return grid[x][y] != '#';
}

bool mineSweeper::getMineHit() { 
            return mineHitOrNot;
}


void minesweeper::print_grid(){
	unsigned short i;
	cout << "    ";
	for(i = 0; i < row; i++) cout << ' ' << i;
	cout << "\n    ";
	for(i = 0; i < row; i++) cout << "--";
	cout << '\n';
	for(i = 0; i < row; i++){
		cout << ' ' << i << " | ";
		for(unsigned short j = 0; j < col; j++){
			cout << grid[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

