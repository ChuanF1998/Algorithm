/*
题目：最大子三角形
题目描述
题目背景：

在一块六边形的三角大陆上，一切都是由三角形组成的。
为了检测星际通信讯号以完成搜寻地外文明计划，科学家们
拟定在国家的版图内选取一块区域来建设这口三角形的射电望远镜
。为了尽可能探索到更加微弱的信号，望远镜必须做的越大越好。而如何在如此广袤的大地上选取地址则显得十分重要。

现在你的任务就是挑选这个最佳的地址，使得这个可以用来建
立射电望远镜的三角形（可以顶点朝上也可以顶点朝下）的边长尽可能大。



简明题意：

给你一个边长为 a 的六边形 01 矩阵，请找到一个最大的全 1 子三角形，输出三角形的边长 b。

示例1
输入
复制
2,[0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1]
输出
复制
2
说明
如下图，可以找到一个边长为2的子三角形，但并不唯一。

备注:
对于所有的输入数据，满足 1 \leq a \leq 1001≤a≤100。

描述这个六边形 01 矩阵 maps 的数组下标，每个数字依次从左到右，再从上到下对应每一个区域。详见下图：


*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	/**
	* 计算六边形01矩阵中最大的全1子三角形的边长
	* @param a int整型 六边形01矩阵的边长
	* @param maps int整型vector 矩阵的具体数据，从上到下，从左到右顺次排列
	* @return int整型
	*/
	int largestSubTriangle(int a, vector<int>& maps) {
		// write code here
		int m_len = a * 4 - 1;
		vector<vector<int> > m(a * 2, vector<int>(m_len, 0));
		vector<vector<int> > order(a * 2, vector<int>(m_len, 0));
		vector<vector<int> > re(a * 2, vector<int>(m_len, 0));
		int pos = 0;
		for (int i = 0; i < a; ++i) {
			for (int j = a - i - 1, d = 1; j < a * 3 + i; ++j, ++d) {
				m[i][j] = maps[pos++];
				order[i][j] = d % 2;
			}
		}
		for (int i = a; i < 2 * a; ++i) {
			for (int j = i - a, d = 0; j < 5 * a - i + 1; ++j, ++d) {
				m[i][j] = maps[pos++];
				order[i][j] = d % 2;
			}
		}
		int ans = 0;
		for (int i = 0; i < a * 2; ++i) {
			for (int j = 0; j < m_len; ++j) {
				if (m[i][j] == 1 && order[i][j] == 0) {
					re[i][j] = 1;
					if (i - 1 >= 0 && j - 1 >= 0 && j + 1 < m_len && m[i - 1][j] == 1) {
						re[i][j] = min(re[i - 1][j - 1], re[i - 1][j + 1]) + 1;
					}
				}
				ans = max(ans, re[i][j]);
			}
		}
		for (int i = a * 2 - 1; i >= 0; --i) {
			for (int j = 0; j < m_len; ++j) {
				if (m[i][j] == 1 && order[i][j] == 1) {
					re[i][j] = 1;
					if (i + 1 < a * 2 && j - 1 >= 0 && j + 1 < m_len && m[i + 1][j] == 1) {
						re[i][j] = min(re[i + 1][j - 1], re[i + 1][j + 1]) + 1;
					}
				}
				ans = max(ans, re[i][j]);
			}
		}
		return ans;
	}
};

int main()
{
	return 0;
}