/*
链接：https://www.nowcoder.com/questionTerminal/e8fb8f89f5d147ec92fd8ecfefe89b0d
来源：牛客网

一个正整数可以分解成一个或多个数组的积。例如36=2*2*3*3，
即包含2和3两个因子。NowCoder最近在研究因子个数的分布规律，现在给
出一系列正整数，他希望你开发一个程序输出每个正整数的因子个数。

输入描述:
输入包括多组数据。
每组数据仅有一个整数n (2≤n≤100000)。


输出描述:
对应每个整数，输出其因子个数，每个结果占一行。
示例1
输入
30<br/>26<br/>20
输出
3<br/>2<br/>2
*/

// write your code here cpp
#include <cmath>
#include <iostream>
using namespace std;

class solution
{
public:
	int Get(int num)
	{
		if (num > 100000 || num < 2) {
			return -1;
		}
		if (IsPrime(num)) {
			return 1;
		}
		int n = 0;
		int flag = 0;
		int sq = (int)sqrt(num);
		while (num > 1) {
			for (int i = 2; i <= sq; ++i) {
				if (num % i == 0) {
					num /= i;
					if (i > flag) {
						n += 1;
						flag = i;
					}
					break;
				}
			}
			if (IsPrime(num)) {
				if (num > flag) {
					n += 1;
				}
				break;
			}
		}
		return n;
	}

	bool IsPrime(int num)
	{
		if (num < 4) {
			return num > 1;
		}
		if (num % 6 != 1 && num % 6 != 5) {
			return false;
		}
		double sq = sqrt(num);
		for (int i = 5; i <= (int)sq; i += 6) {
			if (num % i == 0 || num % (i + 2) == 0) {
				return false;
			}
		}
		return true;
	}
};


int main()
{
	solution ss;
	int num;
	while (cin >> num) {
		cout << ss.Get(num) << endl;
	}
	return 0;
}