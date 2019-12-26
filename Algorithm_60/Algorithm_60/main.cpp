/*
题目描述
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。

保证base和exponent不同时为0
*/

/*
要考虑base == 0 且 exponent < 0 的情况，因为这样在求负数次方时要遇到 1/x，除数为0的情况
①笨办法：遍历，时间复杂度 O（n）
②a的n次方 = a 的 n/2 次方 * a 的 n/2 次方（n为偶数）
  a的n次方 = a 的 n/2 次方 * a 的 n/2 次方 * base (n为奇数）
  时间复杂度 O（logn）
*/

#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	double Power(double base, int exponent) {
		double power = 1.0;
		int exponent_copy = exponent;
		if (exponent <= 0) {
			exponent_copy = -exponent_copy;
		}
		if (fabs(base) <= 1.0e-9 && exponent < 0) {
			return 0.0;
		}
		power = result(base, exponent_copy);
		if (exponent > 0) {
			return power;
		}
		else {
			return 1 / power;
		}
	}

	double result(double base, int exponent)
	{
		if (exponent == 0) {
			return 1;
		}
		if (exponent == 1) {
			return base;
		}
		double n = result(base, exponent >> 1);
		n *= n;
		if ((exponent & 1) == 1) {
			n *= base;
		}
		return n;
	}
};

int main()
{
	return 0;
}