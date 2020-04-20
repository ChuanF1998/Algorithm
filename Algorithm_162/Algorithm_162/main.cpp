/*
题目描述
牛牛有两个长度为nn的数组a, ba,b，牛牛希望统计有多少数对(l, r)(l,r)满足：
1，0 <= l <= r <= n - 1 
​
示例1
输入
复制
[1,2,3,4],[2,1,4,5]
输出
复制
4
说明
满足条件的数对有(0, 1), (0, 2), (1, 1), (1, 2)(0,1),(0,2),(1,1),(1,2)
示例2
输入
复制
[0,0,1,1,1],[2,0,4,3,3]
输出
复制
2
备注:
a.size() == b.size()a.size()==b.size()
1 \leq a.size() \leq 10^41≤a.size()≤10
4

\left| a_i \right| \leq 1000∣a
i
​
∣≤1000
\left| b_i \right| \leq 10^8∣b
i
​
∣≤10
8

*/

#include <vector>
using namespace std;

class Solution {
public:
	/**
	* 计算有多少对符合条件的数对
	* @param a int整型vector 数组a
	* @param b int整型vector 数组b
	* @return int整型
	*/
	int countLR(vector<int>& a, vector<int>& b) {
		// write code here
		long long sum = 0;
		int count = 0;
		for (size_t i = 0; i < a.size(); ++i) {
			sum = 0;
			for (size_t j = i; j < a.size(); ++j) {
				sum += a[j];
				if (sum == b[i] + b[j]) {
					count += 1;
				}
			}
		}
		return count;
	}
};

int main(){
	return 0;
}