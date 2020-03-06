/*
题目描述
求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？为此他特别数了一下1~13中包含1的数字
有1、10、11、12、13因此共出现6次,但是对于后面问题他就没辙了。ACMer希望你们帮帮他,并把问题更加
普遍化,可以很快的求出任意非负整数区间中1出现的次数（从1 到 n 中1出现的次数）。
*/


/*思路：有点复杂。
①比如21233，最高位大于 1， 那么在万位10000--19999都有
剩余4位每一位都取1，剩余3位都可以取 0--9，那么在10000个数之类就是 4 * 10^3

②比如12343，最高位是1， 那么在万位只有10000-12343有
剩余4位每一位都取1，剩余3位都可以取 0--9，那么在10000个数之类就是 4 * 10^3

③如果起始位置为0，跳过

④缩小范围，判断低位
*/
#include <string>
class Solution {
public:
	int NumberOf1Between1AndN_Solution(int n)
	{
		std::string str = std::to_string(n);
		return NumberOf1(str);
	}

	int NumberOf1(std::string str)
	{
		if (str.empty() || str[0] > '9' || str[0] <= '0') {
			return 0;
		}
		int numof1 = 0;
		int bitNum = str.size() - 1;
		std::string substr(str.begin() + 1, str.end());
		if (str[0] >= '2') {
			numof1 += func(bitNum) + (str[0] - '0') * bitNum * func(bitNum - 1);
		}
		else {
			int num = atoi(str.c_str());
			numof1 += num - func(bitNum) + 1 + bitNum * func(bitNum - 1);
		}
		numof1 += NumberOf1(substr);
		return numof1;
	}

	int func(int n)
	{
		int product = 1;
		for (int i = 0; i < n; ++i) {
			product *= 10;
		}
		return product;
	}
};


int main()
{
	return 0;
}