/*
题目：剪花布条
题目描述
一块花布条，里面有些图案，另有一块直接可用的小饰条，里面也有一些图案。
对于给定的花布条和小饰条，计算一下能从花布条中尽可能剪出几块小饰条来呢？
输入描述:
输入包含多组数据。

每组数据包含两个字符串s,t，分别是成对出现的花布条和小饰条，其布条都
是用可见ASCII字符表示的，可见的ASCII字符有多少个，布条的花纹也有多少种花样。花纹条和小饰条不会超过1000个字符长。
输出描述:
对应每组输入，输出能从花纹布中剪出的最多小饰条个数，如果一块都没有，那就输出0，每个结果占一行。
示例1
输入
复制
abcde a3<br/>aaaaaa aa
输出
复制
0<br/>3
*/
// write your code here cpp
#include <iostream>
#include <string>
using namespace std;

class solution
{
public:
	int Get(string& s, string& t)
	{
		if (s.size() == 0 && t.size() == 0) {
			return 0;
		}
		int count = 0;
		int s_size = s.size();
		int t_size = t.size();
		size_t pos = 0;
		size_t begin = 0;
		do {
			pos = s.find(t, begin);
			if (pos != string::npos) {
				count += 1;
				begin = pos + t_size;
			}
		} while (pos != string::npos);
		return count;
	}
};

int main()
{
	solution ss;
	string s;
	string t;
	while (cin >> s >> t) {
		cout << ss.Get(s, t) << endl;
	}
	return 0;
}