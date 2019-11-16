/*
对于一个给定的井字棋棋盘，请设计一个高效算法判断当前玩家是否获胜。

给定一个二维数组board，代表当前棋盘，其中元素为1的代表是当前玩家的棋子，为0表示没有棋子，为-1代表是对方玩家的棋子。

测试样例：
[[1,0,1],[1,-1,-1],[1,-1,0]]
返回：true
*/


#include <vector>
using namespace std;

class Board {
public:
	bool checkWon(vector<vector<int> > board) {
		// write code here
		size_t x = board.size();
		size_t y = board[0].size();
		for (size_t i = 1; i<x - 1; ++i){
			for (size_t j = 1; j<y - 1; ++j){
				if (board[i][j] == 1){
					if (board[i - 1][j] == 1 && board[i + 1][j] == 1){
						return true;
					}
					if (board[i - 1][j - 1] == 1 && board[i + 1][j + 1] == 1) {
						return true;
					}
					if (board[i - 1][j + 1] == 1 && board[i + 1][j - 1] == 1) {
						return true;
					}
					if (board[i][j - 1] == 1 && board[i][j + 1] == 1) {
						return true;
					}
				}
			}
		}
		return false;
	}
};

int main() {
	return 0;
}