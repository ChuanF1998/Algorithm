/*
题目：字符串距离计算
题目描述
给定两个长度相等的，由小写字母组成的字符串S1和S2，定义S1和S2的距离为两个字符串有多少个位置上的字母不相等。
现在牛牛可以选定两个字母X1和X2，将S1中的所有字母X1均替换成X2。（X1和X2可以相同）
牛牛希望知道执行一次替换之后，两个字符串的距离最少为多少。

示例1
输入
复制
"aaa","bbb"
输出
复制
0
说明
牛牛可以将S1中的字符'a'全部替换成字符'b'，这样S1就变成了"bbb"，那么S1和S2的距离就是0
示例2
输入
复制
"aabb","cdef"
输出
复制
3
说明
一种可行的方案是将S1中的字符'a'全部替换成字符'c'，那么S1变成了"ccbb"，和S2的距离是3
备注:
S1.size() =S2.size()S1.size()=S2.size()
1 \leq S1.size() \leq 5 * 10^41≤S1.size()≤5∗10
4

S1和S2中的字母均为小写字母
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	/**
	* 计算最少的距离
	* @param S1 string字符串 第一个字符串
	* @param S2 string字符串 第二个字符串
	* @return int整型
	*/
	int GetMinDistance(string s1, string s2) {
		// write code here
		if (s1.size() != s2.size()) {
			return 0;
		}
		//矩阵用来存字符对(i, j)，i代表s1中的字符，j代表s2中的字符
		vector<vector<int> > arr(26, vector<int>(26, 0));
		for (size_t i = 0; i < s1.size(); ++i) {
			arr[s1[i] - 97][s2[i] - 97]++;
		}
		int count = 0;
		int m = 0;
		for (int i = 0; i < 26; ++i) {
			for (int j = 0; j < 26; ++j) {
				if (i == j) {
					count += arr[i][j]; //表示初始就为相同的
				}
				else {
					//表示此时将i字母变为j字母，但是需要减去初始状态(i, i)匹配对
					int change = arr[i][j] - arr[i][i];
					m = max(m, change);
				}
			}
		}
		return s1.size() - count - m;
	}
};

int main()
{
	return 0;
}