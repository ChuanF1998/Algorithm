/*
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
思路：哈希表，键值对
*/

#include <map>
#include <string>
#include <iostream>
#include <vector>

class Solution {
public:
	std::vector<int> twoSum(std::vector<int>& nums, int target) {
		if (nums.size() <= 1) {
			return{};
		}
		std::map<int, int> p;
		for (int i = 0; i < (int)nums.size(); ++i) {
			if (p.count(nums[i]) > 0) {
				return{ i, p[nums[i]] };
			}
			p[target - nums[i]] = i;
		}
		return{};
	}
};

int main()
{
	std::map<std::string, int> p;
	p["qww"] = 8;
	p["qww"] = 9;
	p["dasd"] = 7;
	p["jsaodi"] = 8;
	int k = p.count("8");
	int j = p.count("qww");

	std::cout << p["9"] << std::endl;
	std::cout << p["qww"] << std::endl;
	return 0; 
}