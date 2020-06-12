/*
题目：
题目描述
给定一个包含大写英文字母和数字的句子，找出这个句子所包含的最大的十六进制整数，
返回这个整数的值。数据保证该整数在int表示范围内

示例1
输入
复制
"012345BZ16"
输出
复制
1193051
说明
12345B对应十进制为1193051
备注:
0<字符串长度<=105
*/
#include <cmath>
#include <string>
using namespace std;

class Solution {
public:
	/**
	*
	* @param s string字符串
	* @return int整型
	*/
	int func(string& str)
	{
		int num = 0;
		int k = 0;
		int end = str.size() - 1;
		for (int i = end; i >= 0; --i) {
			if (str[i] >= '0' && str[i] <= '9') {
				num += (str[i] - '0') * (int)pow(16, k);
			}
			if (str[i] >= 'A' && str[i] <= 'F') {
				num += (str[i] - 'A' + 10) * (int)pow(16, k);
			}
			k += 1;
		}
		return num;
	}
	int solve(string s) {
		// write code here
		int cur = 0;
		int max = 0;
		int pos = 0;
		int begin = 0;
		int wei = pos - begin;
		while (pos < s.size()) {
			if ((s[pos] >= '0' && s[pos] <= '9') || (s[pos] >= 'A' && s[pos] <= 'F')) {
				begin = pos;
				while ((s[pos] >= '0' && s[pos] <= '9') || (s[pos] >= 'A' && s[pos] <= 'F')) {
					pos++;
				}
				if (pos - begin >= wei) {
					wei = pos - begin;
					string str = s.substr(begin, wei);
					cur = func(str);
					if (cur > max) {
						max = cur;
					}
				}
			}
			pos++;
		}
		return max;
	}
};

int main()
{
	return 0;
}