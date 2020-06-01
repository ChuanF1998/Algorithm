/*
题目:最少素数拆分
题目描述
牛牛刚刚学习了素数的定义，现在给定一个正整数N，牛牛希望知道N最少表示成多少个素数的和。
素数是指在大于1的自然数中，除了1和它本身以外不再有其他因数的自然数。

提示
哥德巴赫猜想：任意大于2的偶数都可以拆分成两个质数之和。该猜想尚未严格证明，但暂时没有找到反例。

示例1
输入
复制
3
输出
复制
1
说明
3本身就是1个素数
示例2
输入
复制
6
输出
复制
2
说明
6可以表示为3 + 3，注意同样的素数可以使用多次
备注:
2 \leq N \leq 10^92≤N≤10
9
*/

#include <cmath>

class Solution {
public:
	/**
	* 判断给定的正整数最少能表示成多少个素数的和
	* @param N int整型 给定的正整数
	* @return int整型
	*/
	int MinPrimeSum(int N) {
		// write code here

		if (isprime(N)) {
			return 1;
		}
		if (N % 2 == 0) {
			return 2;
		}
		else {
			if (isprime(N - 2)) {
				return 2;
			}
			else {
				return 3;
			}
		}
	}

	bool isprime(int n)
	{
		if (n < 4) {
			return n > 1;
		}
		if (n % 6 != 5 && n % 6 != 1) {
			return false;
		}
		int sq = sqrt(n);
		for (int i = 5; i <= sq; i += 6) {
			if (n % i == 0 || n % (i + 2) == 0) {
				return false;
			}
		}
		return true;
	}
};

int main()
{
	return 0;
}