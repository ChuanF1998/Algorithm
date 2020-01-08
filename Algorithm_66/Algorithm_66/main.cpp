/*
给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。

示例 1:

输入: [1,2,3,4,5,6,7] 和 k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右旋转 1 步: [7,1,2,3,4,5,6]
向右旋转 2 步: [6,7,1,2,3,4,5]
向右旋转 3 步: [5,6,7,1,2,3,4]
示例 2:

输入: [-1,-100,3,99] 和 k = 2
输出: [3,99,-1,-100]
解释:
向右旋转 1 步: [99,-1,-100,3]
向右旋转 2 步: [3,99,-1,-100]
说明:

尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
要求使用空间复杂度为 O(1) 的 原地 算法。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rotate-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
//设数组大小为m，右移n次
/*
方法一：一次搬移一个单位，搬移n次。O（m*n)
方法二：分为两部分（0,m-n-1),(m-n,m),先将各部分逆置，再整体逆置。O（m）
方法三：循环交换，每次可以确定前n个正确，抛弃前n个，缩小范围再次交换
*/

#include <vector>

class Solution {
public:
	void rotate(std::vector<int>& nums, int k) {
		size_t nums_length = nums.size();
		k %= nums_length;
		for (size_t i = 0; i < (nums_length - k) / 2; ++i) {
			int temp = nums[i];
			nums[i] = nums[nums_length - k - 1 - i];
			nums[nums_length - k - 1 - i] = temp;
		}
		for (size_t i = nums_length - k; i < nums_length - k / 2; ++i) {
			int temp = nums[i];
			nums[i] = nums[2 * nums_length - 1 - k - i];
			nums[2 * nums_length - 1 - k - i] = temp;
		}
		for (size_t i = 0; i < nums_length / 2; ++i) {
			int temp = nums[i];
			nums[i] = nums[nums_length - i - 1];
			nums[nums_length - i - 1] = temp;
		}
	}
};

int main()
{
	return 0;
}