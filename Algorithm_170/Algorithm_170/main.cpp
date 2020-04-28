/*
题目：红与黑
题目描述
有一间长方形的房子，地上铺了红色、黑色两种颜色的正方形瓷砖。
你站在其中一块黑色的瓷砖上，只能向相邻的（上下左右四个方向）黑色瓷砖移动。
请写一个程序，计算你总共能够到达多少块黑色的瓷砖。
输入描述:
输入包含多组数据。

每组数据第一行是两个整数 m 和 n（1≤m, n≤20）。紧接着 m 行，每行包括 n 个字符。
每个字符表示一块瓷砖的颜色，规则如下：

1. “.”：黑色的瓷砖；
2. “#”：白色的瓷砖；
3. “@”：黑色的瓷砖，并且你站在这块瓷砖上。该字符在每个数据集合中唯一出现一次。
输出描述:
对应每组数据，输出总共能够到达多少块黑色的瓷砖。
示例1
输入
复制
9 6<br/>....#.<br/>.....#<br/>......<br/>......<br/>......<br/>......<br/>......<br/>#@...#<br/>.#..#.
输出
复制
45
*/

// write your code here cpp
#include <iostream>
#include <vector>
using namespace std;

class solution
{
public:
	int Get(vector<vector<char> >& arr, int m, int n, int x, int y)
	{
		vector<vector<char> > tmp = arr;
		//func(arr, tmp, m, n, x, y);
		return func(arr, tmp, m, n, x, y) + 1;
		//return 0;
	}

	int func(vector<vector<char> >& arr, vector<vector<char> >& tmp, int m, int n, int x, int y)
	{
		if (x >= 0 && x < m && y >= 0 && y < n) {
			arr[x][y] = '#';
		}
		int count = 0;
		if (x - 1 >= 0 && arr[x - 1][y] == '.') {
			count += func(arr, tmp, m, n, x - 1, y) + 1;
		}
		if (x + 1 < m && arr[x + 1][y] == '.') {
			count += func(arr, tmp, m, n, x + 1, y) + 1;
		}
		if (y - 1 >= 0 && arr[x][y - 1] == '.') {
			count += func(arr, tmp, m, n, x, y - 1) + 1;
		}
		if (y + 1 < n && arr[x][y + 1] == '.') {
			count += func(arr, tmp, m, n, x, y + 1) + 1;
		}
		return count;
	}
};

int main()
{
	int m;
	int n;
	int x;
	int y;
	solution ss;
	while (cin >> m >> n) {
		vector<vector<char> > arr(m, vector<char>(n, '0'));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> arr[i][j];
				if (arr[i][j] == '@') {
					x = i;
					y = j;
				}
			}
		}
		cout << ss.Get(arr, m, n, x, y) << endl;
	}
	return 0;
}