/*
题目：字符串计数
题目描述
求字典序在s1和s2之间的，长度在len1到len2的字符串的个数，结果mod 1000007。

输入描述:
每组数据包涵s1（长度小于100），s2（长度小于100），len1（小于100000），len2（大于len1，小于100000）
输出描述:
输出答案。
示例1
输入
复制
ab ce 1 2
输出
复制
56
*/

#include <iostream>
#include <string>
#include <cmath>
using namespace  std;


int main()
{
	string s1;
	string s2;
	int len1;
	int len2;
	while (cin >> s1 >> s2 >> len1 >> len2) {
		if (s1.compare(s2) >= 0) {
			cout << 0 << endl;
		}
		else {
			if ((int)s1.size() <= len2) {
				string tmp(len2 - s1.size() + 1, 96);
				s1 += tmp;
			}
			if ((int)s2.size() <= len2) {
				string tmp(len2 - s2.size() + 1, 96);
				s2 += tmp;
			}
			long long count = 0;
			for (int i = len1; i <= len2; ++i) {
				for (int j = 0; j < i; ++j) {
					long long k = s2[i - j - 1] - s1[i - j - 1];
					if (s2[i - j] == 96) {
						k -= 1;
					}
					count += k * (int)pow(26, j);
					//if (count)
				}
			}
			cout << count % 1000007 << endl;
		}
	}
	return 0;
}