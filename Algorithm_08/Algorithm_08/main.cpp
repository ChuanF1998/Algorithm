/*
����һ�������ľ��������̣������һ����Ч�㷨�жϵ�ǰ����Ƿ��ʤ��

����һ����ά����board������ǰ���̣�����Ԫ��Ϊ1�Ĵ����ǵ�ǰ��ҵ����ӣ�Ϊ0��ʾû�����ӣ�Ϊ-1�����ǶԷ���ҵ����ӡ�

����������
[[1,0,1],[1,-1,-1],[1,-1,0]]
���أ�true
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