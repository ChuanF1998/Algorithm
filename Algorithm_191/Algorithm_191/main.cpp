/*
题目：扔骰子
题目描述
扔骰子
时间限制 :1sec / 空间限制: 256MB

题意：
牛妹在和牛牛玩扔骰子，他们的游戏规则有所不同；
每个人可以扔nn次mm面骰子，来获得nn个数
得分为任意选取nn个数中的某些数求和所不能得到的最小的正整数
得分大的人获胜
例如扔骰子33次得到了 11 22 55，那么这个人的得分是44

牛妹想知道这回合她是否能赢
牛妹的n个数存在数组a中，牛牛的n个数存在数组b中
数组下标从0开始

输入：

n,m与数组a，b
1 \leq n\leq 2*10^{5}1≤n≤2∗10
5

1 \leq m\leq 10^{9}1≤m≤10
9

1 \leq a[i] \leq m1≤a[i]≤m
1 \leq b[i] \leq m1≤b[i]≤m

输出：
如果牛妹能在这回合胜利则输出HappyHappy，否则输出SadSad

示例1
输入
复制
2,4,[1,2],[1,3]
输出
复制
"Happy"
说明
牛妹能构成 11 22 33，牛妹的得分为4
而牛牛只能构成11 33 55，牛牛的得分为2
故牛妹胜利！
*/
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	/**
	*
	* @param n int整型 n
	* @param m int整型 m
	* @param a int整型一维数组 a
	* @param aLen int a数组长度
	* @param b int整型一维数组 b
	* @param bLen int b数组长度
	* @return string字符串
	*/
	string Throwdice(int n, int m, int* a, int aLen, int* b, int bLen) {
		// write code here
		sort(a, a + aLen);
		sort(b, b + bLen);
		long sum_a = 0;
		long sum_b = 0;
		for (int i = 0; i < aLen; ++i) {
			if (a[i] > sum_a + 1) {
				break;
			}
			sum_a += a[i];
		}
		for (int i = 0; i < bLen; ++i) {
			if (b[i] > sum_b + 1) {
				break;
			}
			sum_b += b[i];
		}
		return sum_a > sum_b ? "Happy" : "Sad";
	}
};

int main()
{
	return 0;
}