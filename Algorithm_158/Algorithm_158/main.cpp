/*
题目描述
又到了吃午饭的时间，你和你的同伴刚刚研发出了最新的GSS-483型自动
打饭机器人，现在你们正在对机器人进行功能测试。
为了简化问题，我们假设午饭一共有N个菜，对于第i个菜，你和你的同伴
对其定义了一个好吃程度（或难吃程度，如果是负数的话……）A[i]，
由于一些技（经）术（费）限制，机器人一次只能接受一个指令：两个数L, 
R——表示机器人将会去打第L~R一共R-L+1个菜。
本着不浪费的原则，你们决定机器人打上来的菜，含着泪也要都吃完，于是
你们希望机器人打的菜的好吃程度之和最大
然而，你善变的同伴希望对机器人进行多次测试（实际上可能是为了多吃到好吃
的菜），他想知道机器人打M次菜能达到的最大的好吃程度之和
当然，打过一次的菜是不能再打的，而且你也可以对机器人输入-1, -1，表示一个菜也不打
输入描述:
第一行：N, M

第二行：A[1], A[2], ..., A[N]
输出描述:
一个数字S，表示M次打菜的最大好吃程度之和
示例1
输入
复制
7 2
1 2 3 -2 3 -10 3
输出
复制
10
说明
[1 2 3 -2 3] -10 [3]
示例2
输入
复制
7 4
1 2 3 -2 3 -10 3
输出
复制
12
说明
[1 2 3] -2 [3] -10 [3]

第四次给机器人-1, -1的指令
备注:
N <= 10^5 = 100000

|A[i]| <= 10^4 = 10000

10%数据M = 1

50%数据M <= 2

80%数据M <= 100

100%数据M <= 10^4 = 10000
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr(100001);
vector<vector<int> > sub(2, vector<int>(100000, 0));
vector<int> tmp(100000, 0);


class solution
{
public:
	int Get(int n, int m)
	{
		if (m == 0) {
			return arr[0];
		}
		int num = 0;
		int sum = 0;
		int i = 1;
		while (i <= n) {
			if (arr[i] >= 0) {
				while (i <= n && arr[i] >= 0) {
					sum += arr[i];
					i++;
				}
				sub[1][num] = sum;
				sum = 0;
				num++;
			}
			else {
				while (i <= n && arr[i] < 0) {
					sum += arr[i];
					i++;
				}
				sub[1][num] = sum;
				sum = 0;
				num++;
			}
		}
		for (int i = 0; i < num; ++i) {
			tmp[i] = sub[1][i];
		}
		int count = 0;
		if (m >= num) {
			for (int i = 0; i < num; ++i) {
				if (sub[1][i] > 0) {
					count += sub[1][i];
				}
				tmp[i] = sub[1][i];
			}
			return count;
		}
		else {
			return func(num, m, tmp);
		}
	}

	int func(int num, int m, vector<int>& tmp)
	{
		int k = 0;
		int v = 0;
		int sum = 0;
		for (int i = 0; i < m; ++i) {
			sum = 0;
			k = (i + 1) & 1;
			v = i & 1;
			sub[k][0] = tmp[0];
			for (int j = 1; j < num; ++j) {
				sum = max(sum, sub[v][j - 1]);
				sub[k][j] = max(sum, sub[k][j - 1]) + tmp[j];
			}
		}
		int count = 0;
		for (int i = 0; i < num; ++i) {
			if (sub[k][i] > count) {
				count = sub[k][i];
			}
		}
		return count;
	}
};

int main()
{
	arr[0] = 0;
	solution ss;
	int N;
	int M;
	while (cin >> N >> M) {
		for (int i = 1; i <= N; ++i) {
			cin >> arr[i];
		}
		cout << ss.Get(N, M) << endl;
	}
	return 0;
}