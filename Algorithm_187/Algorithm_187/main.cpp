/*
题目：左右最大差
题目描述
给定一个长度为N(N>1)的整型数组A，可以将A划分成左右两个部分，
左部分A[0..K]，右部分A[K+1..N-1]，K可以取值的范围是[0,N-2]。
求这么多划分方案中，左部分中的最大值减去右部分最大值的绝对值，最大是多少？

给定整数数组A和数组的大小n，请返回题目所求的答案。

测试样例：
[2,7,3,1,1],5
返回：6
*/

#include <vector>
#include <algorithm>
using namespace std;

class MaxGap {
public:
	int findMaxGap(vector<int> A, int n) {
		// write code here
		vector<int> m(n, 0);
		for (int i = n - 1; i >= 0; --i) {
			if (i == n - 1) {
				m[i] = A[i];
				continue;
			}
			m[i] = max(m[i + 1], A[i]);
		}
		int max_poor = 0;
		int max_num;
		for (int i = 0; i < n - 1; ++i) {
			if (i == 0) {
				max_num = A[0];
				max_poor = max_num - m[i + 1];
				max_poor = max_poor >= 0 ? max_poor : -max_poor;
				continue;
			}
			if (A[i] > max_num) {
				max_num = A[i];
			}
			int tmp = max_num - m[i + 1];
			tmp = tmp >= 0 ? tmp : -tmp;
			if (tmp > max_poor) {
				max_poor = tmp;
			}
		}
		return max_poor;
	}
};

int main()
{
	return 0;
}