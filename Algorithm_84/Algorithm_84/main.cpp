/*
给定一个按照升序排列的整数数组 nums，和一个目标值 target。
找出给定目标值在数组中的开始位置和结束位置。

你的算法时间复杂度必须是 O(log n) 级别。

如果数组中不存在目标值，返回 [-1, -1]。

示例 1:

输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]
示例 2:

输入: nums = [5,7,7,8,8,10], target = 6
输出: [-1,-1]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		if (nums.size() == 0) {
			return{ -1, -1 };
		}
		int i = 0;
		int j = nums.size() - 1;
		if (nums[i] > target || nums[j] < target) {
			return{ -1, -1 };
		}
		int left = fun1(nums, target, i, j);
		int right = fun2(nums, target, i, j);
		return{ left, right };
	}
	int fun1(vector<int>& arr, int target, int i, int j)
	{
		int left;
		int temp = (i + j) >> 1;
		if (i == j && arr[temp] == target) {
			return temp;
		}
		if (i == j && arr[temp] != target) {
			return -1;
		}
		if (i == j - 1) {
			if (arr[i] == target) {
				return i;
			}
			else if (arr[j] == target) {
				return j;
			}
			else {
				return -1;
			}
		}
		if (arr[temp] < target) {
			left = 0 + fun1(arr, target, temp + 1, j);
		}
		else if (arr[temp] >= target) {
			left = 0 + fun1(arr, target, i, temp);
		}
		return left;
	}

	int fun2(vector<int>& arr, int target, int i, int j)
	{
		int right;
		int temp = (i + j) >> 1;
		if (i == j && arr[temp] == target) {
			return temp;
		}
		if (i == j && arr[temp] != target) {
			return -1;
		}
		if (i == j - 1) {
			if (arr[j] == target) {
				return j;
			}
			else if(arr[i] == target) {
				return i;
			}
			else {
				return -1;
			}
		}
		if (arr[temp] <= target) {
			right = 0 + fun2(arr, target, temp, j);
		}
		else if (arr[temp] > target) {
			right = 0 + fun2(arr, target, i, temp - 1);
		}
		return right;
	}
};

int main()
{
	Solution s;
	vector<int> arr{ 1, 2, 2, 2, 4, 5, 6 };
	int k = s.fun1(arr, 3, 0, 7);
	int m = s.fun2(arr, 3, 0, 7);
	return 0;
}