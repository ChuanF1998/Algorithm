/*
给定一个非空数组，返回此数组中第三大的数。如果不存在，则返回数组中最大的数。要求算法时间复杂度必须是O(n)。

示例 1:

输入: [3, 2, 1]

输出: 1

解释: 第三大的数是 1.
示例 2:

输入: [1, 2]

输出: 2

解释: 第三大的数不存在, 所以返回最大的数 2 .
示例 3:

输入: [2, 2, 3, 1]

输出: 1

解释: 注意，要求返回第三大的数，是指第三大且唯一出现的数。
存在两个值为2的数，它们都排第二。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/third-maximum-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
思路：三个临时变量，max，medium，min。
*/

#include <vector>



class Solution {
public:
	int thirdMax(std::vector<int>& nums) {
		int max;
		int medium;
		int min;
		if (nums.size() < 3) {
			min = nums[0];
			for (int i = 1; i < (int)nums.size(); ++i){
				if (nums[i] > min) {
					min = nums[i];
				}
			}
			return min;
		}
		bool is_min = false;
		bool is_medium = false;
		int flag;
		max = nums[0];
		for (int i = 1; i < (int)nums.size(); ++i) {
			if (is_medium == false && nums[i] < max) {
				medium = nums[i];
				is_medium = true;
			}
			else if (is_medium == false && nums[i] > max) {
				medium = max;
				max = nums[i];
				is_medium = true;
			}
			else if (is_medium == true && nums[i] > max) {
				min = medium;
				medium = max;
				max = nums[i];
				is_min = true;
			}
			else if (is_medium == true && nums[i] < medium) {
				min = nums[i];
				is_min = true;
			}
			else if (is_medium == true && nums[i] < max && nums[i] > medium) {
				min = medium;
				medium = nums[i];
				is_min = true;
			}
			else {}
			if (is_medium == true && is_min == true) {
				flag = i;
				break;
			}
		}

		for (int i = flag + 1; i < (int)nums.size(); ++i) {
			if (nums[i] > max) {
				min = medium;
				medium = max;
				max = nums[i];
			}
			else if (nums[i] > medium && nums[i] < max) {
				min = medium;
				medium = nums[i];
			}
			else if (nums[i] < medium && nums[i] > min) {
				min = nums[i];
			}
			else {}
		}
		if (is_min == false || is_medium == false) {
			return max;
		}
		return min;
	}
};

int main()
{
	return 0;
}