/*
题目:牛牛恨66
题目描述
众所周知，牛牛不喜欢6这个数字（因为牛牛和66发音相近）
所以他想知道，不超过n位十进制数中有多少个数字不含有连续的6（从1开始算的）
输入只包含一个正整数n（1<=n<20）

示例1
输入
复制
1
输出
复制
"10"
说明
1，2,3,4,5,6,7,8,9,10 这十个数字中都满足条件
示例2
输入
复制
2
输出
复制
"99"
说明
因为66不可以
*/


#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	/**
	*
	* @param n int整型
	* @return string字符串
	*/
	int a[100][100];
	string calculate(int n) {
		// write code here
		if (n == 1) return "10";
		int i, j;
		a[1][1] = 0;
		a[1][2] = 1;
		a[2][1] = a[2][2] = 9;
		for (i = 3; i <= n; i++)
		for (j = 1; j <= i; j++)
		{
			a[i][j] += (a[i - 1][j] + a[i - 2][j]) * 9;
			if (a[i][j] >= 10 && a[i][j]<100)
			{
				a[i][j + 1] += a[i][j] / 10;
				a[i][j] = a[i][j] % 10;
			}
			if (a[i][j] >= 100)
			{
				a[i][j + 2] += a[i][j] / 100;
				a[i][j + 1] += a[i][j] / 10 % 10;
				a[i][j] %= 10;
			}
		}
		string str("");
		for (i = n; i>0; i--)
			str.append(to_string(a[n][i]));
		return str;
	}
};

int main()
{
	return 0;
}