#include <array>
#include "global.h"
using namespace std;

class grid{
	protected:
		array<array<char,row>,col> grid;
		array<array<char,row>,col> mines;
	public:
		void init_grid();
		void print_grid();
	
};


class mineSweeper : public grid {
  private:
		bool mineHitOrNot;
	public:
		mineSweeper() {
             mineHitOrNot = false;
        }
		void mark(unsigned x, unsigned y);
		bool marked(unsigned x, unsigned y);
		void clear_empty(unsigned x, unsigned y);
		bool isMine(unsigned x, unsigned y);
		char howNear(unsigned x, unsigned y);
		bool getMineHit();
		bool gameWon();
};
