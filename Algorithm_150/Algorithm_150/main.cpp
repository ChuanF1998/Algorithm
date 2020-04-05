/*
题目描述
今天上课，老师教了小易怎么计算加法和乘法，乘法的优先级大于加法，但是如果一个运算加了括号，那么它的优先级是最高的。例如：
1+2*3=7
1*(2+3)=5
1*2*3=6
(1+2)*3=9
现在小易希望你帮他计算给定3个数a，b，c，在它们中间添加"+"， "*"， "("， ")"符号，能够获得的最大值。
输入描述:
一行三个数a，b，c (1 <= a, b, c <= 10)
输出描述:
能够获得的最大值
示例1
输入
1 2 3

输出
9
*/

//通用解法推广到n，动态规划
#include <limits.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class solution
{
public:
	int GetMax(vector<int>& arr)
	{
		size_t size = arr.size();
		vector<vector<int> > m(size, vector<int>(size, INT_MIN)); //把数组每一个数定义为int型最小值,
		//INT_MAX在头文件<limits.h>
		//遍历左下三角
		for (int j = 0; j < size; ++j) {
			for (int i = j; i >= 0; --i) {
				if (i == j) {
					m[i][j] = arr[j];
				}
				//每个点的取值可能性，找出最大的
				//若该点为m[1][4],那么就有
				//max(m[1][1] + m[2][4], m[1][1] * m[2][4])
				//max(m[1][2] + m[3][4], m[1][2] * m[3][4])
				//max(m[1][3] + m[4][4], m[1][3] * m[4][4])
				//可以画一个表格稍微验证一下
				//取三个函数返回值的最大值
				for (int k = j - 1; k >= i; --k) {
					int tmp = max(m[i][k] + m[k + 1][j], m[i][k] * m[k + 1][j]);
					m[i][j] = max(tmp, m[i][j]);
				}
			}
		}
		//最后m[0][size - 1]保存的最大值
		return m[0][size - 1];
	}
};

int main()
{
	int a;
	int b;
	int c;
	solution s;
	vector<int> arr(3);
	while (cin >> a >> b >> c)
	{
		arr.push_back(a);
		arr.push_back(b);
		arr.push_back(c);
		cout << s.GetMax(arr) << endl;
	}
	return 0;
}