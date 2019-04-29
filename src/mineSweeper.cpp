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
	cout<<endl;
	cout << "    ";
	for(i = 0; i < row; i++)
	 cout << ' ' << i;
	cout << "\n    ";
	for(i = 0; i < row; i++)
	 cout << BOLD(FGRN("--"));
	cout << endl;
	for(i = 0; i < row; i++){
		cout << ' ' << i << BOLD(FGRN(" | "));
		for(unsigned short j = 0; j < col; j++){
			cout << grid[i][j] << ' ';
		}
		cout <<endl;
	}
	cout <<endl;
}




void mineSweeper::mark(unsigned x, unsigned y){
	if(x < row && y < row){
		if(grid[x][y] == '#'){
			if(isMine(x,y)){
				grid[x][y] = 'X';
				mineHitOrNot = true; 
			}
			else {
				grid[x][y] = howNear(x,y);
				if(grid[x][y] == '0'){
					clear_empty(x,y);
				}
			}
		}
		else std::cout << "Try again.\n";
	}
}

void mineSweeper::clear_empty(unsigned x, unsigned y){
	
	if(x > 0){
		if(!marked(x-1,y)){
			grid[x-1][y] = howNear(x-1,y);
			if(grid[x-1][y] == '0'){
				clear_empty(x-1,y);
			}
		}
	}
	if(y > 0){
		if(!marked(x,y-1)){
			grid[x][y-1] = howNear(x,y-1);
			if(grid[x][y-1] == '0'){
				clear_empty(x,y-1);
			}
		}
	}
	if(x > 0 && y > 0){
		if(!marked(x-1,y-1)){
			grid[x-1][y-1] = howNear(x-1,y-1);
			if(grid[x-1][y-1] == '0'){
				clear_empty(x-1,y-1);
			}
		}
	}
	if(x < domain){
		if(!marked(x+1,y)){
			grid[x+1][y] = howNear(x+1,y);
			if(grid[x+1][y] == '0'){
				clear_empty(x+1,y);
			}
		}
	}
	if(y < range){
		if(!marked(x,y+1)){
			grid[x][y+1] = howNear(x,y+1);
			if(grid[x][y+1] == '0'){
				clear_empty(x,y+1);
			}
		}
	}
	if(x < domain && y < range){
		if(!marked(x+1,y+1)){
			grid[x+1][y+1] = howNear(x+1,y+1);
			if(grid[x+1][y+1] == '0'){
				clear_empty(x+1,y+1);
			}
		}
	}
	if(x > 0 && y < range){
		if(!marked(x-1,y+1)){
			grid[x-1][y+1] = howNear(x-1,y+1);
			if(grid[x-1][y+1] == '0'){
				clear_empty(x-1,y+1);
			}
		}
	}
	if(x < domain && y > 0){
		if(!marked(x+1,y-1)){
			grid[x+1][y-1] = howNear(x+1,y-1);
			if(grid[x+1][y-1] == '0'){
				clear_empty(x+1,y-1);
			}
		}
	}
	return;
}

bool mineSweeper::isMine(unsigned x, unsigned y){
	return (mines[x][y] == 'x'); 
}

char mineSweeper::howNear(unsigned x, unsigned y){
	
	unsigned short count = 0;
	if(x > 0)
		if(isMine(x-1,y)) count++;
	if(x > 0 && y > 0)
		if(isMine(x-1,y-1)) count++;
	if(x > 0 && y < range)
		if(isMine(x-1,y+1)) count++;
	if(y > 0)
		if(isMine(x,y-1)) count++;
	if(y < range)
		if(isMine(x,y+1)) count++;
	if(x < domain && y > 0)
		if(isMine(x+1,y-1)) count++;
	if(x < domain)
		if(isMine(x+1,y)) count++;
	if(x < domain && y < range)
		if(isMine(x+1,y+1)) count++;
	
	return '0'+count;
}


bool mineSweeper::gameWon(){
	unsigned count = 0;
	for(auto &row : grid){
		for(auto &tile : row){
			if(tile == '#') count++;
			if(count > :: row){
				return false;
			}
		}
	}
	return true;
}
