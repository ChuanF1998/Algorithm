/*
题目描述
汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，
就是用字符串模拟这个指令的运算结果。对于一个给定的字符序列S，请你把
其循环左移K位后的序列输出。例如，字符序列S=”abcXYZdef”,要求输出循环
左移3位后的结果，即“XYZdefabc”。是不是很简单？OK，搞定它！
*/

#include <string>
using namespace std;


//方法一：分割字符串
class Solution1 {
public:
	string LeftRotateString(string str, int n) {
		int strSize = (int)str.size();
		if (strSize == 0) {
			return "";
		}
		n %= strSize;
		return str.substr(n, strSize) + str.substr(0, n);
	}
};

//方法二：字符串逆置
class Solution2 {
public:
	string LeftRotateString(string str, int n) {
		int strSize = (int)str.size();
		if (strSize == 0) {
			return "";
		}
		n %= strSize;
		reverse(str.begin(), str.begin() + n);
		reverse(str.begin() + n, str.end());
		reverse(str.begin(), str.end());
		return str;
	}
};

int main()
{
	return 0;
}