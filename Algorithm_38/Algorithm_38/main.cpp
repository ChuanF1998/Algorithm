/*
题目描述
输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。
例如，输入”They are students.”和”aeiou”，则删除之后的
第一个字符串变成”Thy r stdnts.”

输入描述:
每个测试输入包含2个字符串
输出描述:
输出删除后的字符串

示例1
输入
They are students.
aeiou

输出
Thy r stdnts.
*/

/*
思路：先定义一个255大小的数组，初始化为0，将字符的ASCLL码作为数组下标
遍历str2，将字符对应下标的数组的值加1
遍历str1，将字符对应下标的数组值为0的字符输出

比如 a的ascll码对应97，那么arr[97]的值加1.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class public_string_delete
{
public:
	void delete_public(string& str1, string& str2)
	{
		size_t str1_length = str1.size();
		size_t str2_length = str2.size();
		vector<int> arr(255, 0);
		for (size_t i = 0; i < str2_length; ++i) {
			++arr[str2[i]];
		}
		for (size_t i = 0; i < str1_length; ++i) {
			if (arr[str1[i]] == 0) {
				cout << str1[i];
			}
		}
		cout << endl;
	}
};


int main()
{
	public_string_delete p;
	string str1;
	string str2;
	while (getline(cin, str1) && getline(cin, str2)) {
		p.delete_public(str1, str2);
	}
	return 0;
}