/*
题目描述
牛牛准备参加学校组织的春游, 出发前牛牛准备往背包里装入一些零食, 牛牛的背包容量为w。
牛牛家里一共有n袋零食, 第i袋零食体积为v[i]。
牛牛想知道在总体积不超过背包容量的情况下,他一共有多少种零食放法(总体积为0也算一种放法)。
输入描述:
输入包括两行
第一行为两个正整数n和w(1 <= n <= 30, 1 <= w <= 2 * 10^9),表示零食的数量和背包的容量。
第二行n个正整数v[i](0 <= v[i] <= 10^9),表示每袋零食的体积。
输出描述:
输出一个正整数, 表示牛牛一共有多少种零食放法。
示例1
输入
3 10
1 2 4
输出
8
说明
三种零食总体积小于10,于是每种零食有放入和不放入两种情况，一共有2*2*2 = 8种情况。
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class solution1
{
public:
	long long Getways(vector<long long>& arr, long long w)
	{
		sort(arr.begin(), arr.end());
		return func(arr, 0, w, 0) + 1;
	}
	long long func(const vector<long long>& arr, size_t pos, const long long& w, long long val)
	{
		long long push_ways = 0;
		for (size_t i = pos; i < arr.size(); ++i) {
			val += arr[i];
			if (val <= w) {
				push_ways += func(arr, i + 1, w, val) + 1;
			}
			else {
				break;
			}
			val -= arr[i];
		}
		return push_ways;
	}
};

int main()
{
	int n;
	long long w;
	long long sum = 0;
	solution1 s;
	while (cin >> n >> w) {
		vector<long long> arr(n);
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
			sum += arr[i];
		}
		if (sum <= w) {
			long long k = (long long)pow(2, n);
			cout << k << endl;
		}
		else {
			cout << s.Getways(arr, w) << endl;
		}
	}
	return 0;
}

