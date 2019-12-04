/*
题目描述
小东所在公司要发年终奖，而小东恰好获得了最高福利，他要在公司年会上参与一个
抽奖游戏，游戏在一个6*6的棋盘上进行，上面放着36个价值不等的礼物，每个小的
棋盘上面放置着一个礼物，他需要从左上角开始游戏，每次只能向下或者向右移动一
步，到达右下角停止，一路上的格子里的礼物小东都能拿到，请设计一个算法使小东
拿到价值最高的礼物。

给定一个6*6的矩阵board，其中每个元素为对应格子的礼物价值,左上角为[0,0],请
返回能获得的最大价值，保证每个礼物价值大于100小于1000。
*/

/*
本题需要使用动态规划求解。
定义f(i,j)表示从左上角走到坐标(i，j)处能获得的最大奖励。
搜索所有从左上角走到右下角的路径，找到最优路径。
f(i,j)分三种情况：
第一列：f(i, 0) = f(i-1, 0) + board(i, 0)
第一行：f(0,j) = f(0, j - 1) + b(0, j)
其它位置：f(i, j) = max{f(i-1, j), f(i, j - 1)} + board(i, j)
*/

#include <algorithm>
#include <vector>
using namespace std;

class Bonus {
public:
	int getMost(vector<vector<int> > board) {
		// write code here
		int x = board.size();
		int y = board[0].size();
		for (int i = 1; i<x; ++i) {
			board[i][0] = board[i - 1][0] + board[i][0];
		}
		for (int i = 0; i<y; ++i) {
			board[0][i] = board[0][i] + board[0][i - 1];
		}
		for (int i = 1; i<x; ++i) {
			for (int j = 1; j<y; ++j) {
				board[i][j] = board[i][j] + max(board[i - 1][j], board[i][j - 1]);
			}
		}
		return board[x - 1][y - 1];
	}
};

int main()
{
	return 0;
}