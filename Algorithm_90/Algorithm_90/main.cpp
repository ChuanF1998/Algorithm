/*
给定一个整数矩阵，找出最长递增路径的长度。
对于每个单元格，你可以往上，下，左，右四个方向移动。 
你不能在对角线方向上移动或移动到边界外（即不允许环绕）。

示例 1:

输入: nums =
[
[9,9,4],
[6,6,8],
[2,1,1]
]
输出: 4
解释: 最长递增路径为 [1, 2, 6, 9]。
示例 2:

输入: nums =
[
[3,4,5],
[3,2,6],
[2,2,1]
]
输出: 4
解释: 最长递增路径是 [3, 4, 5, 6]。注意不允许在对角线方向上移动。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-increasing-path-in-a-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
回溯法：超时。改进一下，用一个与原数组大小相等数组标记当前位置升序的个数，当前位置 > 0 ;则直接加当前位置的数
比如：示例一，arr[2][0] = 2,对应数组a[2][0] = 3，当走到下一个arr[2][1] = 1 时，对应数组a[2][1] = 3 + 1.
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int longestIncreasingPath(vector<vector<int>>& matrix) {
		if (matrix.size() == 0) {
			return 0;
		}
		int length = 1;
		int max = 0;
		vector<vector<int> > flag(matrix.size(), vector<int>(matrix[0].size(), 0));
		for (int i = 0; i < (int)matrix.size(); ++i) {
			for (int j = 0; j < (int)matrix[0].size(); ++j) {
				func(matrix, flag, i, j, length);
			}
		}
		return length;
	}

	int func(vector<vector<int> >& arr, vector<vector<int> >& flag, int i, int j, int& length)
	{
		if (flag[i][j] != 0) {
			return flag[i][j];
		}
		int up = 0;
		int down = 0;
		int left = 0;
		int right = 0;
		if (i - 1 >= 0 && arr[i - 1][j] > arr[i][j]) {
			up = func(arr, flag, i - 1, j, length);
		}
		if (i + 1 < (int)arr.size() && arr[i + 1][j] > arr[i][j]) {
			down = func(arr, flag, i + 1, j, length);
		}
		if (j - 1 >= 0 && arr[i][j - 1] > arr[i][j]) {
			left = func(arr, flag, i, j - 1, length);
		}
		if (j + 1 < (int)arr[0].size() && arr[i][j + 1] > arr[i][j]) {
			right = func(arr, flag, i, j + 1, length);
		}
		int max_ = 1 + max(up, max(down, max(left, right)));
		if (max_ > length) {
			length = max_;
		}
		flag[i][j] = max_;
		return max_;
	}
};

int main()
{
	Solution s;
	vector<vector<int> > arr{ { 9, 9, 4 }, { 6, 6, 8 }, { 2, 1, 1 } };
	int k = s.longestIncreasingPath(arr);
	return 0;
}