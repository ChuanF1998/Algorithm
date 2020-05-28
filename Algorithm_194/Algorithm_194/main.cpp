/*
题目描述
有n个只包含小写字母的串s_1,s_2,..，每次给你一个只包含小写字母的串t。
如果串S存在前缀S'，它的奇数位的字符与t的奇数位字符完全相同，称S为t的单匹配串，
如果串S的偶数位字符与t的偶数位的字符全都相同，称S为t的双匹配串。
牛牛喜欢单数，并且觉得"双"非常的可恨。现在给你m个字符串，对于每个字符串t_it 
i
​	
 ，求s_1,s_2,...s_ns 
1
​	
 ,s 
2
​	
 ,...s 
n
​	
 中有多少个串是t的单匹配串但不是t的双匹配串。


示例1
输入
复制
3,["abc", "bbc", "cbd"],3,["abc","cad","bac"]
输出
复制
[0,1,1]
说明
对于字符串"abc"。没有满足条件的单匹配串
字符串“cad"有满足条件的串: "cbd" ,第一个位置都是c，第三个位置都是d，是单匹配串，但是第二个位置不同，不是双匹配串
字符串"bac"有满足条件的串: "bbc" ,第一个位置都是b，第三个位置都是c，是单匹配串，但是第二个位置不同，不是双匹配串
备注:
\sum_{i=1}^n|s_i|+\sum_{i=1}^m|t_i| \le1e6,1\le n,m\le 1e5∑ 
i=1
n
​	
 ∣s 
i
​	
 ∣+∑ 
i=1
m
​	
 ∣t 
i
​	
 ∣≤1e6,1≤n,m≤1e5
*/
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	/**
	* 单双难全
	* @param n int整型 字符串s的个数
	* @param s string字符串vector n个字符串s
	* @param m int整型 字符串t的个数
	* @param t string字符串vector m个字符串t
	* @return int整型vector
	*/
	vector<int> solve(int n, vector<string>& s, int m, vector<string>& t) {
		// write code here
		vector<int> re(t.size(), 0);
		vector<vector<int> > tree(500001, vector<int>(26, 0));
		vector<int> arr(500001, 0);
		int num = 0;
		int r1 = ++num;
		int r2 = ++num;
		for (int i = 0; i < s.size(); ++i) {
			int p = r1;
			for (int j = 0; j < s[i].size(); j += 2) {
				int ch = s[i][j] - 'a';
				if (!tree[p][ch]) {
					tree[p][ch] = ++num;
				}
				arr[p] += 1;
				p = tree[p][ch];
			}
			arr[p] += 1;
			p = r2;
			for (int j = 0; j < s[i].size(); ++j) {
				int ch = s[i][j] - 'a';
				if (!tree[p][ch]) {
					tree[p][ch] = ++num;
				}
				arr[p] += 1;
				p = tree[p][ch];
			}
			arr[p] += 1;
		}
		for (int i = 0; i < t.size(); ++i) {
			int p = r1;
			for (int j = 0; j < t[i].size(); j += 2) {
				int ch = t[i][j] - 'a';
				if (!tree[p][ch]) {
					p = -1;
					break;
				}
				p = tree[p][ch];
			}
			if (p == -1) {
				re[i] = 0;
				continue;
			}
			if (t[i].size() == 1) {
				re[i] = arr[p];
				continue;
			}
			int tmp = arr[p];
			p = r2;
			for (int j = 0; j < t[i].size(); ++j) {
				int ch = t[i][j] - 'a';
				if (!tree[p][ch]) {
					p = -1;
					break;
				}
				p = tree[p][ch];
			}
			if (p == -1) {
				re[i] = tmp;
				continue;
			}
			re[i] = tmp - arr[p];
		}
		return re;
	}
};

int main()
{
	int c = 0;
	int m = ++c, n = ++c;
	return 0;
}