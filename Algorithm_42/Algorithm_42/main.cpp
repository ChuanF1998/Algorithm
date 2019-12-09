/*
题目描述
输入n个整数，输出出现次数大于等于数组长度一半的数。
输入描述:
每个测试输入包含 n个空格分割的n个整数，n不超过100，其中有一个整数出现次数大于等于n/2。
输出描述:
输出出现次数大于等于n/2的数。
示例1
输入
3 9 3 2 5 6 7 3 2 3 3 3

输出
3
*/


#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int get_num(vector<int> arr)
	{
		int onehalf_num = arr[0];
		int count = 1;
		for (size_t i = 1; i < arr.size(); ++i) {
			if (onehalf_num = arr[i]) {
				count++;
			}
			else {
				count--;
				if (count == 0) {
					onehalf_num = arr[i];
					count++;
				}
			}
		}
		return onehalf_num;
	}
};



int main()
{
	Solution s;
	vector<int> arr;
	int k;
	while (cin >> k) {
		arr.push_back(k);
	}
	cout << s.get_num(arr) << endl;
	return 0;
}