/*
题目描述
将一句话的单词进行倒置，标点不倒置。比如 I like beijing. 
经过函数后变为：beijing. like I

输入描述:
每个测试输入包含1个测试用例： I like beijing. 输入用例
长度不超过100

输出描述:
依次输出倒置之后的字符串,以空格分割

示例1
输入
I like beijing.

输出
beijing. like I
*/

//思路：先倒置整个字符串，设置一个标置位，再遍历，遇到
//空格时就倒置标置位与当前空格之间的单词，再将标置位重新标记
//到当前空格的后一个位置，循环退出时，最后倒置标置位与end之间的单词
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class string_reverse
{
public:
	void reverse_str(string& str)
	{
		reverse(str.begin(), str.end());
		auto first = str.begin();
		auto end = str.end();
		auto it = first;
		while (first != end) {
			if (*first == ' ') {
				reverse(it, first);
				it = first + 1;
			}
			++first;
		}
		reverse(it, end);
	}
};


int main()
{
	string_reverse s;
	string str;
	while (getline(cin, str)) {
		s.reverse_str(str);
		cout << str << endl;
	}
	return 0;
}