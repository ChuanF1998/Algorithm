/*
题目描述
将一个字符串转换成一个整数，要求不能使用字符串转换整数
的库函数。 数值为0或者字符串不是一个合法的数值则返回0
输入描述:
输入一个字符串,包括数字字母符号,可以为空
输出描述:
如果是合法的数值表达则返回该数字，否则返回0
示例1
输入
+2147483647
1a33

输出
2147483647
0
*/

/*
1、正负号判断  2、溢出判断（int型表示范围）  3、非法字符判断
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int StrToInt(string str) {
		//int型 -2147483648～2147483647 
		//用unsigned int 的原因是用于判断数的范围，用int型的话在加减的时候如果溢出
		//的话判断不了，比如 2147483648超过范围会被转成 -2147483648
		unsigned int num = 0; 
		int symbol = 2;       
		int i = 0;
		if (str[0] == '+') {
			symbol = 0;
			++i;
		}
		if (str[0] == '-') {
			symbol = 1;
			++i;
		}
		for (int j = i; j < str.size(); ++j) {
			if (str[j] > '0' && str[j] <= '9') {
				num = 10 * num + str[j] - '0';
				if ((symbol == 0 || symbol == 2) && (num > 0x7fffffff)) {
					return 0;
				}
				if ((symbol == 1) && (num > 0x80000000)) {
					return 0;
				}
			}
			else {
				return 0;
			}
		}

		return (symbol == 1) ? -(int)num : (int)num;
	}
};

int main()
{
	Solution s;
	string str;
	while (cin >> str) {
		cout << s.StrToInt(str) << endl;
	}
	return 0;
}