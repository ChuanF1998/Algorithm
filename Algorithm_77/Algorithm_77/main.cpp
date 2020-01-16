/*
给定一个非负整数数组 A，返回一个数组，在该数组中， A 的所有偶数元素之后跟着所有奇数元素。

你可以返回满足此条件的任何数组作为答案。

 

 示例：

 输入：[3,1,2,4]
 输出：[2,4,3,1]
 输出 [4,2,3,1]，[2,4,1,3] 和 [4,2,1,3] 也会被接受。
  

  提示：

  1 <= A.length <= 5000
  0 <= A[i] <= 5000

  来源：力扣（LeetCode）
  链接：https://leetcode-cn.com/problems/sort-array-by-parity
  著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
思路：双指针遍历，定义下标 i 和 j，保证 i 下标的值为偶数，j 下标的值为奇数
四种情况：奇数-奇数
          奇数-偶数
          偶数-奇数
		  偶数-偶数
*/

#include <vector>


class Solution {
public:
	std::vector<int> sortArrayByParity(std::vector<int>& A) {
		std::vector<int> arr(A.begin(), A.end());
		int arr_length = arr.size();
		int i = 0;
		int j = arr_length - 1;
		while (i < j) {
			if (arr[i] % 2 == 1 && arr[j] % 2 == 0) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
				++i;
				--j;
			}
			else if (arr[i] % 2 == 1 && arr[j] % 2 == 1) {
				--j;
			}
			else if (arr[i] % 2 == 0 && arr[j] % 2 == 0) {
				++i;
			}
			else {
				++i;
				--j;
			}
		}
		return arr;
	}
};

int main()
{
	return 0;
}