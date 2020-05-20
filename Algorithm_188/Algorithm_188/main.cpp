/*
题目：牛妹做衣服
题目描述
众所周知，牛妹需要很多衣服，有直播的时候穿的、有舞剑的时候穿的、有跳舞的时候穿的、有弹琴的时候穿的，等等
这些衣服都是由固定大小的矩形布料裁剪而成，心灵手巧的牛妹也知道每件衣服所需要的具体矩形布料的长和宽
然而，她只有一块大的布料可供她裁剪。裁剪的时候可以随便剪
那么问题来了，美腻的牛妹能最多可以做出多少件衣服呢？


示例1
输入
3,5,[[3 ,1],[4,1],[2,2],[2,2]]
输出
5
备注:
1.布料使用时无方向要求，但是 不可以把边角料拼成大布料
2.每种衣服牛妹可以不止要一件

数据保证 ：

0 < 衣服件数 <=10

0 < 大布料的长&宽，每件衣服长&宽  <= 1000  均为整数

*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	/**
	*
	* @param L int整型 给定布料的长
	* @param W int整型 给定布料的宽
	* @param clothSize int整型vector<vector<>> 依次列举每件衣服所需的长和宽
	* @return int整型
	*/
	int clothNumber(int L, int W, vector<vector<int> >& clothSize) {
		// write code here
		vector<vector<int> > arr(L + 1, vector<int>(W + 1, 0));
		int ma = 0;
		for (int i = 1; i <= L; ++i) {
			for (int j = 1; j <= W; ++j) {
				for (int k = 0; k < clothSize.size(); ++k) {
					int m = clothSize[k][0];
					int n = clothSize[k][1];
					if (i - m >= 0 && j - n >= 0) {
						arr[i][j] = max(arr[i][j], arr[i - m][j] + arr[m][j - n] + 1);
						arr[i][j] = max(arr[i][j], arr[i][j - n] + arr[i - m][n] + 1);
					}
					if (i - n >= 0 && j - m >= 0) {
						arr[i][j] = max(arr[i][j], arr[i - n][j] + arr[n][j - m] + 1);
						arr[i][j] = max(arr[i][j], arr[i][j - m] + arr[i - n][m] + 1);
					}
				}
				ma = max(ma, arr[i][j]);
			}
		}
		return ma;
	}
};

int main()
{
	Solution ss;
	vector<vector<int> > arr{ { 2, 2 }, { 2, 3 }, { 3, 2 }, { 2, 2 }, { 6, 1 }, { 7, 1 }, { 4, 4 }, { 5, 1 }, { 5, 2 }, { 5, 3 } };
	ss.clothNumber(7, 7, arr);
	return 0;
}
