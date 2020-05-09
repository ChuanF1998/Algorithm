/*
题目：走迷宫
题目描述
NowCoder最喜欢游乐场的迷宫游戏，他和小伙伴们比赛谁先走出迷宫。
现在把迷宫的地图给你，你能帮他算出最快走出迷宫需要多少步吗？
输入描述:
输入包含多组数据。

每组数据包含一个10*10，由“#”和“.”组成的迷宫。其中“#”代表墙；“.”代表通路。

入口在第一行第二列；出口在最后一行第九列。

从任意一个“.”点都能一步走到上下左右四个方向的“.”点。
输出描述:
对应每组数据，输出从入口到出口最短需要几步。

*/

// write your code here cpp
#include <iostream>
#include <vector>
using namespace std;

vector<vector<char> > arr(10, vector<char>(10, '0'));
vector<vector<int> > tmp(10, vector<int>(10, 0));

bool input()
{
	char k;
	if (cin >> k) {
		for (int i = 0; i < 10; ++i){
			for (int j = 0; j < 10; ++j) {
				if (i == 0 && j == 0) {
					arr[i][j] = k;
				}
				else {
					cin >> arr[i][j];
				}
			}
		}
		return true;
	}
	return false;
}


void func(int x, int y)
{
	if (x + 1 <= 9 && arr[x + 1][y] == '.') {
		if (tmp[x + 1][y] == 0 || tmp[x][y] + 1 < tmp[x + 1][y]) {
			tmp[x + 1][y] = tmp[x][y] + 1;
			func(x + 1, y);
		}
	}
	if (x - 1 >= 0 && arr[x - 1][y] == '.') {
		if (tmp[x - 1][y] == 0 || tmp[x][y] + 1 < tmp[x - 1][y]) {
			tmp[x - 1][y] = tmp[x][y] + 1;
			func(x - 1, y);
		}
	}
	if (y + 1 <= 9 && arr[x][y + 1] == '.') {
		if (tmp[x][y + 1] == 0 || tmp[x][y] + 1 < tmp[x][y + 1]) {
			tmp[x][y + 1] = tmp[x][y] + 1;
			func(x, y + 1);
		}
	}
	if (y - 1 >= 0 && arr[x][y - 1] == '.') {
		if (tmp[x][y - 1] == 0 || tmp[x][y] + 1 < tmp[x][y - 1]) {
			tmp[x][y - 1] = tmp[x][y] + 1;
			func(x, y - 1);
		}
	}
	return;
}

int Least_step()
{
	func(0, 1);
	return tmp[9][8];
}

int main()
{
	while (input()) {
		cout << Least_step() << endl;
		for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < 10; ++j) {
				tmp[i][j] = 0;
			}
		}
		//tmp.resize(10, vector<int>(10, 0));
	}
	return 0;
}