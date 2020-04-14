/*
题目描述
小喵们很喜欢把自己装进容器里的（例如碗），但是要是碗的周长比喵的身长还短，它们就进不去了。

现在告诉你它们的身长，和碗的半径，请判断一下能否到碗里去。
输入描述:
输入有多组数据。

每组数据包含两个整数n (1≤n≤2^128) 和r (1≤r≤2^128)，分别代表喵的身长和碗的半径。

圆周率使用3.14。
输出描述:
对应每一组数据，如果喵能装进碗里就输出“Yes”；否则输出“No”。
示例1
输入
复制
6 1<br/>7 1<br/>9876543210 1234567890
输出
复制
Yes<br/>No<br/>No
*/

#include <iostream>
#include <string>
using namespace std;

class solution
{
public:
	string Get(string& s1, string& s2)
	{
		//string s3 = (s2.size(), '0');
		string s3;
		strSum(s2, s3, 628);
		if (s3.size() > s1.size() + 2) {
			return "Yes";
		}
		else if (s3.size() == s1.size() + 2) {
			return s3.compare(s1 + "00") >= 0 ? "Yes" : "No";
		}
		else {
			return "No";
		}
	}

	void strSum(string& str, string& s3, int num)
	{
		string tmp;
		int cy = 0;  //进位
		int times = 0;
		while (num > 0) {
			int k = num % 10;
			tmp = str;
			//算出每一位与标准字符串的乘积。后面会补位，十位补一个0，百位补2个0
			for (int i = (int)tmp.size() - 1; i >= 0; --i) {
				int pro = (tmp[i] - '0') * k + cy;
				tmp[i] = pro % 10 + '0';
				cy = pro / 10;
			}
			if (cy > 0) {
				tmp.insert(tmp.begin(), cy + '0');
			}
			cy = 0;
			num /= 10;
			//补位
			for (int i = 0; i < times; ++i) {
				tmp += "0";
			}
			//相加
			int end = tmp.size() - 1;
			for (int i = s3.size() - 1; i >= 0; --i) {
				int pro = tmp[end] - '0' + s3[i] - '0' + cy;
				tmp[end] = pro % 10 + '0';
				cy = pro / 10;
				end--;
			}
			for (int i = end; i >= 0; --i) {
				int pro = tmp[end] - '0' + cy;
				tmp[end] = pro % 10 + '0';
				cy = pro / 10;
				end--;
			}
			if (cy > 0) {
				tmp.insert(tmp.begin(), cy + '0');
			}
			times += 1;
			s3 = tmp;
			cy = 0;
		}
		return;
	}
};

int main()
{
	solution ss;
	string s1;
	string s2;
	while (cin >> s1 >> s2) {
		cout << ss.Get(s1, s2) << endl;
	}
	return 0;
}