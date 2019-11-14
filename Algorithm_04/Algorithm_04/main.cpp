/*
题目描述
正整数A和正整数B 的最小公倍数是指 能被A和B整除的最小的正整数值，设计一个算法，求输入A和B的最小公倍数。

输入描述:
输入两个正整数A和B。

输出描述:
输出A和B的最小公倍数。

示例1
输入
5 7

输出
35
*/

//思路：为了减小时间复杂度，有一个公式： 两个数的乘积 = 两个数的最大公约数 * 最小公倍数
//利用辗转相除法求最大公约数；若两个数本身存在背熟关系-》直接输出最大那个数
#include <iostream>
using namespace std;

class Least_common_multiple
{
public:
	long long Get(long long x, long long y)
	{
		if (x == 0 || y == 0){ //两个数要都不为0
			return 0;
		}
		if (x<y) {  //保证x总是为最大
			long long temp = x;
			x = y;
			y = temp;
		}
		if (x%y == 0){  //x为最小公倍数
			return x;
		}
		long long z = x*y;
		long long dividend;
		long long Greatest_common_divisor; //最大公约数
		while (x>y) {
			dividend = x%y;
			if (dividend == 0) {
				Greatest_common_divisor = y;
				break;
			}
			if (dividend == 1) {
				Greatest_common_divisor = dividend;
				break;
			}
			x = y;
			y = dividend;
		}
		return z / Greatest_common_divisor;
	}
};

int main()
{
	long long x, y;
	Least_common_multiple s;
	while (cin >> x >> y) {
		cout << s.Get(x, y) << endl;
	}
	return 0;
}