/*
题目描述
小易在学校中学习了关于字符串的理论, 于是他基于此完成了一个字典的项目。

小易的这个字典很奇特, 字典内的每个单词都包含n个'a'和m个'z', 并且所有单词按照字典序排列。

小易现在希望你能帮他找出第k个单词是什么。

输入描述:
输入包括一行三个整数n, m, k(1 <= n, m <= 100, 1 <= k <= 109), 以空格分割。

输出描述:
输出第k个字典中的字符串，如果无解，输出-1。
示例1
输入
2 2 6

输出
zzaa
说明
字典中的字符串依次为aazz azaz azza zaaz zaza zzaa
*/

/*
每确定一个字符，就相当于将范围缩小一半，这个缩小一般不是数字而是区间段(只适用于两个字符)
比如属于a开头区间或属于z开头区间
*/

#include <iostream>
#include <string>
using namespace std;

class solution
{
public:
	string GetMax(int n, int m, int k)
	{
		string s;
		while (n > 0 && m > 0) {
			long long count = 1;
			for (int i = 1; i <= n - 1; ++i) {
				count *= n + m - i;
				count /= i;
				if (count >= k) {
					break;
				}
			}
			if (k <= count) {
				s += "a";
				n--;
			}
			if (k > count) {
				s += "z";
				k -= count;
				m--;
			}
		}
		if (k != 1) {
			return "-1";
		}
		while (n--) {
			s += "a";
		}
		while (m--) {
			s += "z";
		}
		return s;
	}
};

int main()
{
	solution s;
	int n;
	int m;
	int k;
	while (cin >> n >> m >> k) {
		cout << s.GetMax(n, m, k) << endl;
	}
	return 0;
}