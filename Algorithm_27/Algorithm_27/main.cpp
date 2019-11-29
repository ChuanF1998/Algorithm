/*
题目描述
写出一个程序，接受一个字符串，然后输出该字符串反转后的字符串。例如：
输入描述:
输入N个字符

输出描述:
输出该字符串反转后的字符串

示例1
输入
abcd

输出
dcba
*/

//若用C++标准库函数reverse，几行代码
//若用C语言面向过程的思维，也不难，设立两个指针，一个
//指头，一个指尾，交换内容，头指针大于尾指针时退出循环

#if 0
//C++做法
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;



int main()
{
	string str;
	while (getline(cin, str)) {
		reverse(str.begin(), str.end());
		cout << str << endl;
	}
	return 0;
}
#endif


//C语言做法
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

void c_reverse(char* str, size_t n)
{
	char* first = str;
	char* last = str + n - 1;
	while (last>first) {
		char temp = *first; //交换
		*first = *last;
		*last = temp;
		++first;
		--last;
	}
}


int main()
{
	string str1;
	while (cin >> str1) {
		char *c_str1 = new char[str1.size() + 1]; //开辟空间
		strcpy(c_str1, str1.c_str());        //拷贝字符串
		size_t n = str1.size();
		c_reverse(c_str1, n);       
		while (*c_str1 != '\0'){
			cout << *c_str1;
			++c_str1;
		}
		cout << endl;
	}
	return 0;
}