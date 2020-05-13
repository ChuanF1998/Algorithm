/*
题目：单词倒排
题目描述
对字符串中的所有单词进行倒排。

说明：

1、构成单词的字符只有26个大写或小写英文字母；

2、非构成单词的字符均视为单词间隔符；

3、要求倒排后的单词间隔符以一个空格表示；如果原字符串中相邻单词间有多个间隔符时，
倒排转换后也只允许出现一个空格间隔符；

4、每个单词最长20个字母；

输入描述:
输入一行以空格来分隔的句子

输出描述:
输出句子的逆序

示例1
输入
I am a student

输出
student a am I
*/


#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string str;
	while (getline(cin, str)) {
		int times = 0;
		int be = 0;
		int space_count = 0;
		for (int i = 0; i < str.size(); ++i) {
			if (!((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))) {
				space_count++;
			}
			else {
				if (space_count > 0 && times > 0) {
					str[be++] = ' ';
				}
				times += 1;
				space_count = 0;
				str[be++] = str[i];
			}

		}
		str = str.substr(0, be);
		reverse(str.begin(), str.end());
		be = 0;
		int end = 0;
		while (end < str.size()) {
			if (str[end] == ' ') {
				reverse(str.begin() + be, str.begin() + end);
				be = end + 1;
			}
			end++;
		}
		reverse(str.begin() + be, str.end());
		cout << str << endl;
	}
	return 0;
}