/*
Fibonacci数列是这样定义的：
F[0] = 0
F[1] = 1
for each i ≥ 2: F[i] = F[i-1] + F[i-2]
因此，Fibonacci数列就形如：0, 1, 1, 2, 3, 5, 8, 13, ...，
在Fibonacci数列中的数我们称为Fibonacci数。给你一个N，你想
让其变为一个Fibonacci数，每一步你可以把当前数字X变为X-1
或者X+1，现在给你一个数N求最少需要多少步可以变为Fibonacci数

输入描述:
输入为一个正整数N(1 ≤ N ≤ 1,000,000)

输出描述:
输出一个最小的步数变为Fibonacci数"
*/



#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int Get_min_step(vector <int> arr, int num)
	{
		int step = 0;
		int k = 0;
		size_t n = arr.size();
		for (size_t i = 0; i<n; ++i) {
			if (arr[i] >= num){   //一旦遇到数组中某个数大于这个数时
				k = i;         //退出，并保存数组下标
				break;
			}
		}
		int temp = num;
		if (temp == arr[k]) {  //相等直接返回0
			return 0;
		}
		while (temp > arr[k - 1]) { //遍历，同时记录步数
			--temp;
			step++;
		}
		int miror = arr[k] - arr[k - 1];
		if (step < miror / 2) {  //判断，小于1/2时退出
			return step;
		}
		else{
			return miror - step;
		}
	}
};

int main()
{
	//构造一个Fibonacci数列
	vector<int> arr;
	arr.push_back(0);
	arr.push_back(1);
	int i = 1;
	while (arr[i] < 1000000) {
		int value1 = arr[i];
		int value2 = arr[i - 1];
		arr.push_back(value1 + value2);
		++i;
	}
	int n;
	Solution s;
	while (cin >> n) {
		cout << s.Get_min_step(arr, n) << endl;
	}
	return 0;
}