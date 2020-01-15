/*
给定一个按非递减顺序排序的整数数组 A，返回每个数字的平方组成的新数组，要求也按非递减顺序排序。

 

 示例 1：

 输入：[-4,-1,0,3,10]
 输出：[0,1,9,16,100]
 示例 2：

 输入：[-7,-3,2,3,11]
 输出：[4,9,9,49,121]
  

  提示：

  1 <= A.length <= 10000
  -10000 <= A[i] <= 10000
  A 已按非递减顺序排序。

  来源：力扣（LeetCode）
  链接：https://leetcode-cn.com/problems/squares-of-a-sorted-array
  著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
思路：双指针遍历，负数一个，向前走；正数一个，向后走。
*/

#include <vector>

class Solution {
public:
	std::vector<int> sortedSquares(std::vector<int>& A) {
		std::vector<int> arr;
		size_t A_size = A.size();
		int negative_pos = -1;
		int positive_pos = -1;
		for (size_t i = 0; i < A_size; ++i) {
			if (A[i] < 0) {
				negative_pos = i;
			}
			else {
				positive_pos = i;
				break;
			}
		}
		while (negative_pos >= 0 && positive_pos < (int)A_size) {
			if (-A[negative_pos] < A[positive_pos]) {
				arr.push_back(A[negative_pos] * A[negative_pos]);
				negative_pos--;
			}
			else {
				arr.push_back(A[positive_pos] * A[positive_pos]);
				positive_pos++;
			}
		}
		while (negative_pos >= 0) {
			arr.push_back(A[negative_pos] * A[negative_pos]);
			negative_pos--;
		}
		while (positive_pos < (int)A_size) {
			arr.push_back(A[positive_pos] * A[positive_pos]);
			positive_pos++;
		}
		return arr;
	}
};

int main()
{
	return 0;
}