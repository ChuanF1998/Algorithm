/*
给定一个整数数组，你需要寻找一个连续的子数组，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。

你找到的子数组应是最短的，请输出它的长度。

示例 1:

输入: [2, 6, 4, 8, 10, 9, 15]
输出: 5
解释: 你只需要对 [6, 4, 8, 10, 9] 进行升序排序，那么整个表都会变为升序排序。
说明 :

输入的数组长度范围在 [1, 10,000]。
输入的数组可能包含重复元素 ，所以升序的意思是<=。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


#include <vector>
#include <algorithm>

class Solution {
public:
	int findUnsortedSubarray(std::vector<int>& nums) {
		if (nums.size() == 0 || nums.size() == 1) {
			return 0;
		}
		int interver = (int)nums.size();
		std::vector<int> arr = nums;
		sort(arr.begin(), arr.end());
		int i = 0;
		int j = interver - 1;
		while (i < j) {
			if (nums[i] == arr[i] && nums[j] == arr[j]) {
				interver -= 2;
				i++;
				j--;
			}
			else if (nums[i] == arr[i] && nums[j] != arr[j]) {
				interver -= 1;
				i++;
			}
			else if (nums[i] != arr[i] && nums[j] == arr[j]) {
				interver -= 1;
				j--;
			}
			else {
				break;
			}
		}
		if (i >= j && interver == 1) {
			interver -= 1;
		}
		return interver;
	}
};

int main()
{
	return 0;
}