/*
题目描述
小Q得到一个神奇的数列: 1, 12, 123,...12345678910,1234567891011...。

并且小Q对于能否被3整除这个性质很感兴趣。

小Q现在希望你能帮他计算一下从数列的第l个到第r个(包含端点)有多少个数可以被3整除。

输入描述:
输入包括两个整数l和r(1 <= l <= r <= 1e9), 表示要求解的区间两端。
输出描述:
输出一个整数, 表示区间内能被3整除的数字个数。
示例1
输入
复制
2 5
输出
复制
3
说明
12, 123, 1234, 12345...
其中12, 123, 12345能被3整除。
*/

/*

1  12  123  1234  12345  123456  1234567  12345678  123456789  12345678910  1234567891011  123456789101112
0   1   1    0     1       1       0        1           1           0             1               1
每三个数中有两个能被三整除，第一个不能，第二，三个可以，区间除3再乘2得到个数
接下来讨论的是区间未被整除，可能余1，余2，再考虑起始位置，结合在一起看偏移量
*/

#include <iostream>

class Solution
{
public:
	int multiple_of_three(int l, int k)
	{
		if (l >= k || l < 1) {
			return 0;
		}
		int start = l % 3;
		int interval = k - l + 1;
		int remain = interval % 3;
		int count = (interval / 3) << 1;
		if (start == 2 && remain == 1) {
			count += 1;
		}
		if (start == 2 && remain == 2) {
			count += 2;
		}
		if (start == 1 && remain == 2) {
			count += 1;
		}
		return count;
	}
};



int main()
{
	Solution s;
	int l;
	int k;
	while (std::cin >> l >> k) {
		std::cout << s.multiple_of_three(l, k) << std::endl;
	}
	return 0;
}