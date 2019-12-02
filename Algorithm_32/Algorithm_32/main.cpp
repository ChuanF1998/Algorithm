/*
题目描述
找出字符串中第一个只出现一次的字符

输入描述:
输入一个非空字符串

输出描述:
输出第一个只出现一次的字符，如果不存在输出-1

示例1
输入
asdfasdfo

输出
o
*/

//思路，创建一个255大小的数组，先遍历第一遍，将字符的ascll大小作为数组
//下标，遇见一个字符，该字符对应的数组下标的值加一
//再一次遍历，当遇到字符对应数组下标的值为一时输出，若没有，输出 -1

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class once_char
{
public:
	string get_once(string str)
	{
		string s;
		vector<int> arr(255, 0);
		for (size_t i = 0; i<str.size(); ++i) {
			++arr[str[i]];
		}
		for (size_t i = 0; i<str.size(); ++i) {
			if (arr[str[i]] == 1){
				s.push_back(str[i]);
				return s;
			}
		}
		return "-1";
	}
};


int main()
{
	once_char o;
	string str;
	while (cin >> str) {
		cout << o.get_once(str) << endl;
	}
	return 0;
}