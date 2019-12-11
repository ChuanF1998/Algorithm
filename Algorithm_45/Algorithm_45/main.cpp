/*
题目描述
“回文串”是一个正读和反读都一样的字符串，
比如“level”或者“noon”等等就是回文串。
花花非常喜欢这种拥有对称美的回文串，生日的
时候她得到两个礼物分别是字符串A和字符串B。
现在她非常好奇有没有办法将字符串B插入字符串
A使产生的字符串是一个回文串。你接受花花的请求，
帮助她寻找有多少种插入办法可以使新串是一个回文
串。如果字符串B插入的位置不同就考虑为不一样的办法。
例如：
A = “aba”，B = “b”。这里有4种把B插入A的办法：
* 在A的第一个字母之前: "baba" 不是回文
* 在第一个字母‘a’之后: "abba" 是回文
* 在字母‘b’之后: "abba" 是回文
* 在第二个字母'a'之后 "abab" 不是回文
所以满足条件的答案为2
输入描述:
每组输入数据共两行。
第一行为字符串A
第二行为字符串B
字符串长度均小于100且只包含小写字母
输出描述:
输出一个数字，表示把字符串B插入字符串A之后构成一个回文串的方法数
示例1
输入
aba
b

输出
2
*/




#include <iostream>
#include <string>
using namespace std;

class Palindrome_string
{
public:
	int get(string str1, string str2)
	{
		int count = 0;
		int flag = 1;
		string str_temp;
		size_t str1_length = str1.size();
		auto t_first = str_temp.begin();
		auto t_last = str_temp.end();
		for (size_t i = 0; i <= str1_length; ++i) {
			str_temp = str1;
			str_temp.insert(i, str2);
			t_first = str_temp.begin();
			t_last = str_temp.end() - 1;
			flag = 1;
			while (t_first < t_last) {
				if (*t_first != *t_last) {
					flag = 0;
					break;
				}
				++t_first;
				--t_last;
			}
			if (flag == 1) {
				++count;
			}
			str_temp.clear();
		}
		return count;
	}
};


int main()
{
	Palindrome_string p;
	string str1, str2;
	while (cin >> str1 >> str2) {
		cout << p.get(str1, str2) << endl;
	}
	return 0;
}