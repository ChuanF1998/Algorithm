/*
题目描述
给定一个十进制数M，以及需要转换的进制数N。将十进制数M转化为N进制数
输入描述:
输入为一行，M(32位整数)、N(2 ≤ N ≤ 16)，以空格隔开。
输出描述:
为每个测试实例输出转换后的数，每个输出占一行。如果N大于9，则对
应的数字规则参考16进制（比如，10用A表示，等等）

示例1
输入
7 2

输出
111
*/



#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class conversion_of_system
{
public:
	string get_system(int n, int sys)
	{
		int k = 0;
		if (n < 0) {
			k = 1;
			n = -n;
		}
		string str;
		while (n > 0) {
			int remainder = n % sys;
			if (remainder == 10) {
				str.push_back('A');
			}
			else if (remainder == 11) {
				str.push_back('B');
			}
			else if (remainder == 12) {
				str.push_back('C');
			}
			else if (remainder == 13) {
				str.push_back('D');
			}
			else if (remainder == 14) {
				str.push_back('E');
			}
			else if (remainder == 15) {
				str.push_back('F');
			}
			else {
				str.push_back(remainder + '0');
			}
			n = (n - remainder) / sys;
		}
		if (k == 1) {
			str.push_back('-');
		}
		reverse(str.begin(), str.end());
		return str;
	}
};

int main()
{
	conversion_of_system c;
	int n, sys;
	while (cin >> n >> sys) {
		cout << c.get_system(n, sys) << endl;
	}
	return 0;
}