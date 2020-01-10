/*
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。
如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

你可以假设数组中无重复元素。

示例 1:

输入: [1,3,5,6], 5
输出: 2
示例 2:

输入: [1,3,5,6], 2
输出: 1
示例 3:

输入: [1,3,5,6], 7
输出: 4
示例 4:

输入: [1,3,5,6], 0
输出: 0

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/search-insert-position
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
思路：二分法查找
*/

#include <vector>

class Solution {
public:
	int searchInsert(std::vector<int>& nums, int target) {
		size_t nums_length = nums.size();
		if (nums_length == 0) {
			nums.push_back(target);
			return 0;
		}
		if (nums[0] > target) {
			nums.insert(nums.begin(), target);
			return 0;
		}
		int flag = 0;
		bool is_exist = false;
		int i = 0;
		int j = (int)nums_length - 1;
		while (i <= j) {
			flag = (i + j) >> 1;
			if (nums[flag] == target) {
				is_exist = true;
				break;
			}
			else if (target > nums[flag]) {
				i = flag + 1;
				if (i > j) {
					flag = i;
				}
			}
			else {
				j = flag - 1;
				if (i > j) {
					flag = i;
				}
			}
		}
		if (is_exist == false) {
			nums.insert(nums.begin() + flag, target);
		}
		return flag;
	}
};


int main()
{
	return 0;
}