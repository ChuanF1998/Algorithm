/*
题目：求和
题目描述
输入两个整数 n 和 m，从数列1，2，3.......n 中随意取几个数,使其和等于 m ,要求将其中所有的可能组合列出来
输入描述:
每个测试输入包含2个整数,n和m
输出描述:
按每个组合的字典序排列输出,每行输出一种组合
示例1
输入
复制
5 5
输出
复制
1 4<br/>2 3<br/>5
*/

#include <iostream>
#include <vector>
using namespace std;

void func(int begin, int n, int m, int& sum, vector<int>& arr)
{
	if (sum == m) {
		for (int i = 0; i < arr.size(); ++i) {
			if (i == 0) {
				cout << arr[i];
			}
			else {
				cout << " " << arr[i];
			}

		}
		cout << endl;
		return;
	}
	for (int i = begin; i <= n; ++i) {
		sum += i;
		arr.push_back(i);
		func(i + 1, n, m, sum, arr);
		sum -= i;
		arr.pop_back();
	}
}

int main()
{
	int n;
	int m;
	while (cin >> n >> m) {
		vector<int> arr;
		int sum = 0;
		func(1, n, m, sum, arr);
	}
	return 0;
}