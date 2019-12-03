/*
题目描述
Levenshtein 距离，又称编辑距离，指的是两个字符串之间，由一个
转换成另一个所需的最少编辑操作次数。许可的编辑操作包括将一个
字符替换成另一个字符，插入一个字符，删除一个字符。编辑距离的
算法是首先由俄国科学家Levenshtein提出的，故又叫Levenshtein Distance。

Ex：

字符串A:abcdefg

字符串B: abcdef

通过增加或是删掉字符”g”的方式达到目的。这两种方案都需要
一次操作。把这个操作所需要的次数定义为两个字符串的距离。

要求：

给定任意两个字符串，写出一个算法计算它们的编辑距离。

输入描述:
输入两个字符串

输出描述 :
得到计算结果

示例1
输入
abcdefg
abcdef

输出
1

*/

/*
本题需要用动态规划解题 状态： 子状态：word1的前1，2，3，...m个字符转换成word2的前1，2，3，...n
个字符需要的编辑距离
F(i,j):word1的前i个字符于word2的前j个字符的编辑距离 状态递推： F(i,j) = min { F(i-1,j）+1, F(i,j-1) +1, F(i-
1,j-1) +(w1[i]==w2[j]?0:1) } 上式表示从删除，增加和替换操作中选择一个最小操作数 F(i-1,j): w1[1,...,i-1]于
w2[1,...,j]的编辑距离，删除w1[i]的字符--->F(i,j) F(i,j-1): w1[1,...,i]于w2[1,...,j-1]的编辑距离，增加一个字符---
>F(i,j) F(i-1,j-1): w1[1,...,i-1]于w2[1,...,j-1]的编辑距离，如果w1[i]与w2[j]相同， 不做任何操作，编辑距离不
变，如果w1[i]与w2[j]不同，替换w1[i]的字符为w2[j]--->F(i,j) 初始化： 初始化一定要是确定的值，如果这里
不加入空串，初始值无法确定 F(i,0) = i :word与空串的编辑距离，删除操作 F(0,i) = i :空串与word的编辑距
离，增加操作 返回结果：F(m,n)


*/


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	int get_editor(string& str1, string& str2)
	{
		if (str1.empty() || str2.empty()) {
			return max(str1.size(), str2.size());
		}
		int str1_length = str1.size();
		int str2_length = str2.size();
		vector< vector<int> > arr(str1_length + 1, vector<int>(str2_length + 1, 0));
		for (int i = 0; i <= str1_length; ++i) {
			arr[i][0] = i;
		}
		for (int i = 0; i <= str2_length; ++i) {
			arr[0][i] = i;
		}
		for (int i = 1; i <= str1_length; ++i) {
			for (int j = 1; j <= str2_length; ++j) {
				if (str1[i - 1] == str2[i - 1]) {
					arr[i][j] = 1 + min(arr[i][j - 1], arr[i - 1][j]);
					arr[i][j] = min(arr[i][j], arr[i - 1][j - 1]);
				}
				else {
					arr[i][j] = 1 + min(arr[i][j - 1], arr[i - 1][j]);
					arr[i][j] = min(arr[i][j], 1 + arr[i - 1][j - 1]);
				}
			}
		}
		return arr[str1_length][str2_length];
	}
};


int main()
{
	Solution s;
	string str1, str2;
	while (cin >> str1 >> str2) {
		cout << s.get_editor(str1, str2) << endl;
	}
	return 0;
}