/*
题目描述
一个数组有 N 个元素，求连续子数组的最大和。 例如：[-1,2,1]，和最
大的连续子数组为[2,1]，其和为 3
输入描述:
输入为两行。 第一行一个整数n(1 <= n <= 100000)，表示一共有n个元素 
第二行为n个数，即每个元素,每个整数都在32位int范围内。以空格分隔。

输出描述:
所有连续子数组中和最大的值。
示例1
输入
3 -1 2 1

输出
3
*/



#include <iostream>
#include <vector>
using namespace std;

class continue_arr
{
public:
	int get_max(vector<int>& arr)
	{
		int min_count = 0;
		int max_count = arr[0];
		size_t arr_size = arr.size();
		for (size_t i = 0; i < arr_size; ++i) {
			if (arr[i] >= 0) {
				min_count += arr[i];
				if (min_count > max_count) {
					max_count = min_count;
				}
			}
			else {
				min_count += arr[i];
				if (min_count < 0) {
					if (min_count > max_count) {
						max_count = min_count;
					}
					min_count = 0;
				}
			}
		}
		return max_count;
	}
};

int main()
{
	continue_arr c;
	int n;
	while (cin >> n) {
		vector<int> arr(n);
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}
		cout << c.get_max(arr) << endl;
	}
	return 0;
}