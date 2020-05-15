/*
题目：合唱团
题目描述
有 n 个学生站成一排，每个学生有一个能力值，牛牛想从这 n 个学生中按照顺序选取 k 名学生，
要求相邻两个学生的位置编号的差不超过 d，使得这 k 个学生的能力值的乘积最大，你能返回最大的乘积吗？
输入描述:
每个输入包含 1 个测试用例。每个测试数据的第一行包含一个整数 n (1 <= n <= 50)，
表示学生的个数，接下来的一行，包含 n 个整数，按顺序表示每个学生的能力值 ai（-50 <= ai <= 50）。
接下来的一行包含两个整数，k 和 d (1 <= k <= 10, 1 <= d <= 50)。
输出描述:
输出一行表示最大的乘积。
示例1
输入
复制
3
7 4 7
2 50
输出
复制
49
*/


/*
dfs:牛客网超时

#include <iostream>
#include <vector>
using namespace std;

vector<int> re;

void func(vector<int>& arr, long& max, long& pro, int& k, int count, int& d, int start, int& n)
{
	if (count == k) {
		if (pro > max) {
			max = pro;
		}
		return;
	}
	for (int i = start; i < n; ++i) {
		if (start + d <= i) {
			break;
		}
		if (arr[i] != 0) {
			pro *= arr[i];
			count += 1;
			func(arr, max, pro, k, count, d, i + 1, n);
			count -= 1;
			pro /= arr[i];
		}
	}
	return;
}

int main()
{
	int n;
	while (cin >> n) {
		vector<int> arr(n);
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}
		vector<int> a;

		int k;
		int d;
		cin >> k >> d;
		long max = -50;
		long pro = 1;
		for (int i = 0; i < n; i++) {
			if (arr[i] != 0) {
				pro *= arr[i];
				func(arr, max, pro, k, 1, d, i + 1, n);
				pro /= arr[i];
			}
		}
		cout << max << endl;
	}
	return 0;
}
*/


#include <limits.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	int n;
	while (cin >> n) {
		vector<int> arr(n + 1);
		for (int i = 1; i <= n; ++i) {
			cin >> arr[i];
		}
		int k;
		int d;
		cin >> k >> d;
		vector<vector<long> > positive(k + 1, vector<long>(n + 1, 0));
		vector<vector<long> > negative(k + 1, vector<long>(n + 1, 0));
		long re = LONG_MIN;
		for (int i = 1; i <= n; ++i) {
			positive[1][i] = arr[i];
			negative[1][i] = arr[i];
			for (int j = 2; j <= k; ++j) {
				for (int k = i - 1; k >= 1 && i - k <= d; --k) {
					positive[j][i] = max(positive[j][i], max(positive[j - 1][k] * arr[i], negative[j - 1][k] * arr[i]));
					negative[j][i] = min(negative[j][i], min(positive[j - 1][k] * arr[i], negative[j - 1][k] * arr[i]));
				}
			}
			re = max(re, positive[k][i]);
		}
		cout << re << endl;
	}
	return 0;
}