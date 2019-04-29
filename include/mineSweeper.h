#include <array>

using namespace std;

const int row = 8;
const int col = 8;
const int domain = row - 1;
const int range = col - 1;

class mineSweeper {
  private:
		array<array<char,row>,col> grid;
		array<array<char,row>,col> mines;
		bool mineHitOrNot;
	public:
		mineSweeper() {
             mineHitOrNot = false;
        }
		void init_grid();
		void print_grid();
		void mark(unsigned x, unsigned y);
		bool marked(unsigned x, unsigned y){ 
            return grid[x][y] != '#';
        }
		void clear_empty(unsigned x, unsigned y);
		bool isMine(unsigned x, unsigned y);
		char howNear(unsigned x, unsigned y);
		bool getMineHit() { 
            return mineHitOrNot;
        }
		bool gameWon();
}    