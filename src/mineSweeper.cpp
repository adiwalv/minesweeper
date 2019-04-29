#include <iostream>
#include "../include/mineSweeper.h"
#include "../include/colors.h"
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


void mineSweeper::init_grid(){
	srand(time(NULL));
	for(auto &row : grid){
		row.fill('#');
	}
	
	for(auto &row : mines){
		row.fill('o');
	}
	
	for(int i = 0; i < row; i++){
		int x = rand() % row;
		int y = rand() % col;
		mines[x][y] = 'x';
	}
}



void mineSweeper::print_grid(){
	unsigned short i;
	cout << BOLD(FBLU("    ")) << endl;
	for(i = 0; i < row; i++)
		cout << BOLD(FBLU(" ")) << i;
	cout << "\n    ";
	for(i = 0; i < row; i++) 
		cout << BOLD(FGRN("--"));
	cout << '\n';
	for(i = 0; i < row; i++){
		cout << BOLD(FGRN(" ")) << i << BOLD(FGRN(" | "));
		for(unsigned short j = 0; j < col; j++){
			cout << grid[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}
