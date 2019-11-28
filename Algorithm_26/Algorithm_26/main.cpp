/*
题目描述
查找两个字符串a,b中的最长公共子串。若有多个，输出在较短串中最先出现的那个。
输入描述:
输入两个字符串
输出描述:
返回重复出现的字符

示例1
输入
abcdefghijklmnop
abcsafjklmnopqrstuvw

输出
jklmnop
*/


#include <iostream>
#include <string>
using namespace std;

class max_substr
{
public:
	string get_max_substr(string str1, string str2)
	{
		size_t str1_length = str1.size();
		size_t str2_length = str2.size();
		if (str2_length<str1_length){   //为了让str2的长度永远大于str1
			string temp = str1;
			str1 = str2;
			str2 = temp;
		}
		str1_length = str1.size(); //重新赋值
		str2_length = str2.size();
		string min_str;
		string max_str;
		for (size_t i = 0; i<str1_length; ++i) {
			for (size_t j = 1; j<str1_length - i; ++j) {
				min_str = str1.substr(i, j);  //用min_str构造子串
				size_t pos = str2.find(min_str); //在str2中查找
				if (pos != string::npos) {        //若找到，进入；未找到，继续下一次循环
					if (min_str.size() > max_str.size()){ //min_str的长度大于max_str，r
						max_str = min_str;                //把min_str的内容赋给max_st
					}
				}
			}
		}
		return max_str;
	}
};

int main()
{
	max_substr m;
	string str1, str2;
	while (getline(cin, str1) && getline(cin, str2)) {
		cout << m.get_max_substr(str1, str2) << endl;
	}
	return 0;
}