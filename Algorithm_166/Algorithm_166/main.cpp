/*
题目：牛妹的礼物
题目描述
众所周知，牛妹有很多很多粉丝，粉丝送了很多很多礼物给牛妹，牛妹的礼物摆满了地板。
地板是N\times MN×M的格子，每个格子有且只有一个礼物，牛妹已知每个礼物的体积。
地板的坐标是左上角(1,1)  右下角（N, M）。
牛妹只想要从屋子左上角走到右下角，每次走一步，每步只能向下走一步或者向右走一步或者向右下走一步
每次走过一个格子，拿起（并且必须拿上）这个格子上的礼物。
牛妹想知道，她能走到最后拿起的所有礼物体积最小和是多少？
示例1
输入
复制
[[1,2,3],[2,3,4]]
输出
复制
7
说明
(1,1)->(1,2)->(2,3)
备注:
0<N,M<300
每个礼物的体积小于100
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	/**
	*
	* @param presentVolumn int整型vector<vector<>> N*M的矩阵，每个元素是这个地板砖上的礼物体积
	* @return int整型
	*/
	int selectPresent(vector<vector<int> >& presentVolumn) {
		// write code here
		int n = (int)presentVolumn.size();
		int m = (int)presentVolumn[0].size();
		if (n == 0 || m == 0) {
			return 0;
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (i == 0 && j == 0) {
					presentVolumn[i][j] = presentVolumn[i][j];
				}
				else if (i == 0 && j > 0) {
					presentVolumn[i][j] += presentVolumn[i][j - 1];
				}
				else if (i > 0 && j == 0) {
					presentVolumn[i][j] += presentVolumn[i - 1][j];
				}
				else {
					int tmp = min(presentVolumn[i - 1][j], presentVolumn[i][j - 1]);
					presentVolumn[i][j] += min(presentVolumn[i - 1][j - 1], tmp);
				}
			}
		}
		return presentVolumn[n - 1][m - 1];
	}
};

int main()
{
	return 0;
}