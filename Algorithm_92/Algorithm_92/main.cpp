/*
题目描述
牛牛以前在老师那里得到了一个正整数数对(x, y), 牛牛忘记他们具体是多少了。

但是牛牛记得老师告诉过他x和y均不大于n, 并且x除以y的余数大于等于k。
牛牛希望你能帮他计算一共有多少个可能的数对。

输入描述:
输入包括两个正整数n,k(1 <= n <= 10^5, 0 <= k <= n - 1)。
输出描述:
对于每个测试用例, 输出一个正整数表示可能的数对数量。

示例1
输入
5 2

输出
7

说明
满足条件的数对有(2,3),(2,4),(2,5),(3,4),(3,5),(4,5),(5,3)
*/

/*
思路：首先，数值小于 y 一定不成立，因为x除以y的余数一定不会大于等于y
x除以y的余数分布规则：1、2、3....0的循环，在 1 - n 的区间有 k 个循环，从 y = k + i 开始取到 n 为止（i从1开始取）
每个区间成立的个数为 i ，个数为 i * k；最后可能存在余数 m，只要余数大于等于k，还要再加上 m - k + 1;
但是 k = 0 的情况需要单独考虑，因为 0 在循环末尾
例：x <= 5， y = 2的分布规则
x取值 1、2、3、4、5
余数：1、0、1、0、1
*/

#include <iostream>
using namespace std;

class Solution
{
public:
	long long double_num(int n, int k)
	{
		long long count = 0;
		if (k >= n || n < 1 || n > 10e5) {
			return 0;
		}
		if (k == 0) {
			for (int i = 1; i <= n; ++i) {
				count += n;
			}
			return count;
		}
		for (int i = k + 1; i <= n; ++i) {
			count += (i - k) * (n / i);
			count += ((n % i) - k) >= 0 ? ((n % i) - k + 1) : 0;
		}
		return count;
	}
};


int main()
{
	Solution s;
	int n;
	int k;
	while (cin >> n >> k) {
		cout << s.double_num(n, k) << endl;
	}
	return 0;
}