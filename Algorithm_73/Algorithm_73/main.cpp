/*
给定一个整数数组，判断是否存在重复元素。

如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。

示例 1:

输入: [1,2,3,1]
输出: true
示例 2:

输入: [1,2,3,4]
输出: false
示例 3:

输入: [1,1,1,3,3,4,3,2,4,2]
输出: true

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/contains-duplicate
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
方法一：暴力破解，时间复杂度O(n^2)
方法二：排序，然后遍历。时间复杂度O（n*logn）。但是排序会改变元数组，看需求是否拷贝一份。
方法三：哈希
*/

#include <vector>
#include <algorithm>

class Solution {
public:
	bool containsDuplicate(std::vector<int>& nums) {
		if (nums.size() == 0 || nums.size() == 1) {
			return false;
		}
		std::vector<int> arr(nums.begin(), nums.end());
		sort(arr.begin(), arr.end());
		for (size_t i = 1; i < arr.size(); ++i) {
			if (arr[i - 1] == arr[i]) {
				return true;
			}
		}
		return false;
	}
};

int main()
{
	return 0;
}