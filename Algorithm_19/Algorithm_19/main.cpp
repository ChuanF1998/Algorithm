/*
题目描述
完全数（Perfect number），又称完美数或完备数，是一些特殊的自然数。

它所有的真因子（即除了自身以外的约数）的和（即因子函数），恰好等于它本身。

例如：28，它有约数1、2、4、7、14、28，除去它本身28外，其余5个数相加，1+2+4+7+14=28。

给定函数count(int n),用于计算n以内(含n)完全数的个数。计算范围, 0 < n <= 500000

返回n以内完全数的个数。 异常情况返回-1

输入描述:
输入一个数字

输出描述 :
输出完全数的个数

示例1
输入
1000

输出
3
*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class perfect_num
{
public:
	int get_perfect_num(int n)
	{
		int count = 0;
		if (n == 1) {
			return 0;
		}
		for (int i = 2; i <= n; ++i) {
			if (is_perfect(i)){
				++count;
			}
		}
		return count;
	}
	//判断是否是完全数
	bool is_perfect(int n)
	{
		int divisor = 1;
		vector<int> arr;
		get_divisor(n, arr);   //得到这个数（除1和本身）的因数
		for (int i = 0; i<arr.size(); ++i) {
			divisor += arr[i];    //相加
		}
		if (divisor == n) {
			return true;
		}
		else {
			return false;
		}
	}

	void get_divisor(int n, vector<int>& arr)
	{
		double n_sqrt = sqrt(n);
		for (int i = 2; i <= n_sqrt; ++i) {
			if (n%i == 0) {
				arr.push_back(i);
				if ((n / i) != i) {
					arr.push_back(n / i);
				}
			}
		}
	}
};

int main()
{
	perfect_num p;
	int n;
	while (cin >> n) {
		cout << p.get_perfect_num(n) << endl;
	}
	return 0;
}