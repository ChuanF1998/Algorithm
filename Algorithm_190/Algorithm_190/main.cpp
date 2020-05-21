//第一次错误的原因：在算的时候已经包含了顺序，如果用n的话，重复计算
/*
//题目：生产口罩
题目描述
生产口罩
时间限制 :1sec / 空间限制: 256MB

题意：
牛妹是一家口罩厂家的老板，由于现在疫情严重，
牛妹想重新分配每条生产线上的人数来使得能生产的口罩最多。
牛妹所在的公司一共有mm名员工，nn条生产线(0.....n-1)，
每条生产线有strategy[i].size种人数安排策略。例如：33个人在aa生产线上，
aa生产线每天生产88个口罩；55个人在aa生产线上，每天aa生产线能生产1515个口罩。
牛妹想知道通过合理的策略安排最多每天能生产多少口罩？（可以不用将所有员工都分配上岗，生产线可以选择闲置）

输入：
给定n,mn,m，strategystrategy数组
1 \leq n,m \leq 2*10^{3}1≤n,m≤2∗10
3

strategy[i].size \ge 1 , \sum_{i=0}^{n-1}strategy[i].size \leq 3000strategy[i].size≥1,∑
i=0
n−1
​
strategy[i].size≤3000

1 \leq strategy[i][j].x \leq 2000,1 \leq strategy[i][j].y \leq 30001≤strategy[i][j].x≤2000,1≤strategy[i][j].y≤3000
strategy[i][j].x表示人数，strategy[i][j].y表示能生产的口罩数
输出：
返回每天最大的口罩生产数量

示例1
输入
复制
3,5,[[(1,3),(2,4)],[(3,4),(4,4)],[(8,8)]]
输出
复制
8
说明
样例解释： 11号生产线采用策略22，22号生产线采用策略11，33号生产线不生产
*/

#include <vector>
#include <algorithm>
using namespace std;

struct Point {
	int x;
	int y;
};


class Solution {
public:
	/**
	*
	* @param n int整型 n
	* @param m int整型 m
	* @param strategy Point类vector<vector<>> 策略
	* @return int整型
	*/
	int producemask(int n, int m, vector<vector<Point> >& strategy) {
		// write code here
		vector<vector<int> > arr(n + 1, vector<int>(m + 1, 0));
		for (int i = 1; i <= m; ++i) {  //人数
			for (int j = 1; j <= n; ++j) {   //生产线
				arr[j][i] = arr[j - 1][i];
				for (int k = 0; k < strategy[j - 1].size(); ++k) {
					int x = strategy[j - 1][k].x;
					int y = strategy[j - 1][k].y;
					if (i >= x) {
						arr[j][i] = max(arr[j][i], y + arr[j - 1][i - x]);
						//arr[j][i] = max(arr[j][i], y + arr[n][i - x]);
					}
				}
			}
		}
		return arr[n][m];
	}
};


int main()
{
	vector<vector<Point> > strategy{ { { 1, 3 }, { 2, 4 } }, { { 3, 4 }, { 4, 4 } }, { { 8, 8 } } };
	Solution ss;
	ss.producemask(3, 5, strategy);
	return 0;
}