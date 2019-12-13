/*
题目描述
二货小易有一个W*H的网格盒子，网格的行编号为0~H-1，网格的列编号为0~W-1。
每个格子至多可以放一块蛋糕，任意两块蛋糕的欧几里得距离不能等于2。
对于两个格子坐标(x1,y1),(x2,y2)的欧几里得距离为:
( (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2) ) 的算术平方根
小易想知道最多可以放多少块蛋糕在网格盒子里。
输入描述:
每组数组包含网格长宽W,H，用空格分割.(1 ≤ W、H ≤ 1000)
输出描述:
输出一个最多可以放的蛋糕数

示例1
输入
3 2

输出
4
*/




#include <iostream>
#include <vector>
using namespace std;

class solution
{
public:
	int get_max_cake(int w, int h, vector<vector<int> >& arr)
	{
		int count = 0;
		//vector<vector<int> > arr(w, vector<int>(h,0));
		for (int i = 0; i < w; ++i) {
			for (int j = 0; j < h; ++j) {
				if (arr[i][j] == 0) {
					arr[i][j] = 1;
					++count;
					if (i + 2 < w) {
						arr[i + 2][j] = -1;
					}
					if (j + 2 < h) {
						arr[i][j + 2] = -1;
					}
				}
			}
		}
		return count;
	}
};


int main()
{
	solution s;
	int w, h;
	vector<vector<int> >arr;
	while (cin >> w >> h) {
		arr.resize(w);
		for (auto& e : arr)
			e.resize(h, 0);
		cout << s.get_max_cake(w, h, arr) << endl;
		arr.clear();
	}
	return 0;
}