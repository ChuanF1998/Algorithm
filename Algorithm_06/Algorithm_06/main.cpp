/*
题目描述
请编写一个函数（允许增加子函数），计算n x m的棋盘格子（n为横向的格子数，m为竖向的格子数）
沿着各自边缘线从左上角走到右下角，总共有多少种走法，要求不能走回头路，即：只能往右和往下走，
不能往左和往上走。
输入描述:
输入两个正整数

输出描述:
返回结果

示例1
输入
2
2

输出
6
*/

//解法：a[i][j]=a[i-1][j]+a[i][j-1],表示该到点的路径=左边路径总数+上边路径总数

#include <iostream>
#include <vector>
using namespace std;

class way_count
{
public:
	int Get_way(int n, int m)
	{
		vector< vector<int> >arr(n + 1, vector<int>(m + 1, 1));
		for (int i = 1; i<n + 1; ++i) {
			for (int j = 1; j < m + 1; ++j) {
				arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
			}
		}
		return arr[n][m];
	}
};

int main()
{
	way_count w;
	int n, m;
	while (cin >> n >> m) {
		cout << w.Get_way(n, m) << endl;
	}
	return 0;
}