/*
题目：牛妹的礼物
题目描述
众所周知，牛妹非常喜欢吃蛋糕。
第一天牛妹吃掉蛋糕总数三分之一（向下取整）多一个，
第二天又将剩下的蛋糕吃掉三分之一（向下取整）多一个，
以后每天吃掉前一天剩下的三分之一（向下取整）多一个，
到第n天准备吃的时候只剩下一个蛋糕。
牛妹想知道第一天开始吃的时候蛋糕一共有多少呢？

示例1
输入
复制
2
输出
复制
3
示例2
输入
复制
4
输出
复制
10
备注:
0<n< 30
*/
#include <vector>
using namespace std;

class Solution {
public:
	/**
	*
	* @param n int整型 只剩下一只蛋糕的时候是在第n天发生的．
	* @return int整型
	*/
	int cakeNumber(int n) {
		// write code here
		vector<int> arr(n + 1, 0);
		arr[n] = 1;
		for (int i = n - 1; i >= 1; --i) {
			arr[i] = (arr[i + 1] * 3 + 3) / 2;
		}
		return arr[1];
	}
};

int main()
{
	return 0;
}