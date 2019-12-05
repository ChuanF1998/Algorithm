/*
题目描述
定义一个二维数组N*M（其中2<=N<=10;2<=M<=10），如5 × 5数组下所示：

int maze[5][5] = {

0, 1, 0, 0, 0,

0, 1, 0, 1, 0,

0, 0, 0, 0, 0,

0, 1, 1, 1, 0,

0, 0, 0, 1, 0,

};

它表示一个迷宫，其中的1表示墙壁，0表示可以走的路，只能横着走或
竖着走，不能斜着走，要求编程序找出从左上角到右下角的最短路线。
入口点为[0,0],既第一空格是可以走的路。

Input

一个N × M的二维数组，表示一个迷宫。数据保证有唯一解,不考虑有多
解的情况，即迷宫只有一条通道。

Output

左上角到右下角的最短路径，格式如样例所示。

Sample Input

0 1 0 0 0

0 1 0 1 0

0 0 0 0 0

0 1 1 1 0

0 0 0 1 0

Sample Output

(0, 0)

(1, 0)

(2, 0)

(2, 1)

(2, 2)

(2, 3)

(2, 4)

(3, 4)

(4, 4)

输入描述:
输入两个整数，分别表示二位数组的行数，列数。再输入相应的数组，
其中的1表示墙壁，0表示可以走的路。数据保证有唯一解,不考虑有
多解的情况，即迷宫只有一条通道。

输出描述:
左上角到右下角的最短路径，格式如样例所示。

示例1
输入
5 5
0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0

输出
(0,0)
(1,0)
(2,0)
(2,1)
(2,2)
(2,3)
(2,4)
(3,4)
(4,4)
*/



#include <iostream>
#include <vector>
using namespace std;

class solution
{
public:
	void get_min(int i, int j, vector<vector<int> >& arr, vector<vector<int> >& arr_short, vector<vector<int> >& arr_long)
	{
		int n = arr.size();
		int m = arr[0].size();
		arr[i][j] = 1;
		arr_long.push_back({ i, j });
		if (i == n - 1 && j == m - 1) {
			if (arr_short.empty() || arr_long.size() < arr_short.size()) {
				arr_short = arr_long;
			}
		}
		//向左
		if (j - 1 >= 0 && arr[i][j - 1] == 0) {
			get_min(i, j - 1, arr, arr_short, arr_long);
		}
		//向右
		if (j + 1 < m && arr[i][j + 1] == 0) {
			get_min(i, j + 1, arr, arr_short, arr_long);
		}
		//向上
		if (i - 1 >= 0 && arr[i - 1][j] == 0) {
			get_min(i - 1, j, arr, arr_short, arr_long);
		}
		//向下
		if (i + 1 < n && arr[i + 1][j] == 0) {
			get_min(i + 1, j, arr, arr_short, arr_long);
		}
		arr[i][j] = 0;  //恢复到以前
		arr_long.pop_back(); //弹出尾部的元素
	}
};


int main()
{
	int n, m;
	solution s;
	while (cin >> n >> m) {
		vector<vector<int> > arr(n, vector<int>(m, 0));
		vector<vector<int> > arr_long;
		vector<vector<int> > arr_short;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j< m; ++j) {
				cin >> arr[i][j];
			}
		}
		s.get_min(0, 0, arr, arr_short, arr_long);
		for (size_t i = 0; i < arr_short.size(); ++i) {
			cout << '(' << arr_short[i][0] << ',' << arr_short[i][1] << ')' << endl;
		}
	}
	return 0;
}