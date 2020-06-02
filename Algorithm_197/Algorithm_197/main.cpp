/*
题目：牛牛爱花
题目描述
牛牛有一个3*n的土地。这个土地有3行，n列。牛牛想在土地上种至少一朵花。

为了花儿能够茁壮成长，每一朵花的上下左右四个方向不能有其他的花。问有多少种种花的方案。

为防止答案过大，答案对1e9+7取模。

示例1
输入
复制
1
输出
复制
4
说明
只有1列，用1代表花，0代表空地。这一列的种法可能是[1,0,0],[0,1,0],[0,0,1],[1,0,1]四种
备注:
1\le n\le 1e51≤n≤1e5
*/
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	/**
	* 牛牛爱花
	* @param n int整型 列数
	* @return int整型
	*/
	int solve(int n) {
		// write code here
		int fg = 1000000007;
		vector<vector<int> > arr(2, vector<int>(8, 0));
		int cur = 0;
		int pre = 1;
		arr[0][0] = 1;
		for (int i = 0; i < n; ++i) {
			swap(cur, pre);
			for (int j = 0; j < 8; ++j) {
				arr[cur][j] = 0;
			}
			for (int mask = 0; mask < 8; ++mask) {
				if (mask == 3 || mask == 6 || mask == 7) {
					continue;
				}
				for (int index = 0; index < 8; ++index) {
					if (index == 3 || index == 6 || index == 7) {
						continue;
					}
					if ((index & mask) != 0) {
						continue;
					}
					arr[cur][mask] += arr[pre][index];
					arr[cur][mask] %= fg;
				}
			}
		}
		int result = 0;
		for (int i = 0; i < 8; ++i) {
			result = (result + arr[cur][i]) % fg;
		}
		return (result + fg - 1) % fg;
	}
};

int main()
{
	return 0;
}