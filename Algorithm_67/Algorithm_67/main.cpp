/*
给定一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。

元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

示例 1:

给定 nums = [3,2,2,3], val = 3,

函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。

你不需要考虑数组中超出新长度后面的元素。
示例 2:

给定 nums = [0,1,2,2,3,0,4,2], val = 2,

函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。

注意这五个元素可为任意顺序。

你不需要考虑数组中超出新长度后面的元素。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-element
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


/*
思路：将数组中与给定的val相同的值往后移，给出i = 0，j = 数组的最后一个下标
从i开始遍历，遇到与val相等的值，将j位置的值与val再次比较，如果arr[j]相等，那么j
就向前移，不等就交换，交换完后i++，j--。i>j时退出
*/

#include <iostream>
#include <vector>

class Solution {
public:
	int removeElement(std::vector<int>& nums, int val) {
		size_t nums_length = nums.size();
		if (nums_length == 0) {
			return 0;
		}
		int i = 0;
		int j = (int)nums_length - 1;
		while (i <= j) {
			if (nums[i] != val) {
				++i;
			}
			else {
				--nums_length;
				while (i < j) {
					if (nums[j] == val) {
						--j;
						--nums_length;
					}
					else {
						break;
					}
				}
				nums[i] = nums[j];
				nums[j] = val;
				++i;
				--j;
			}
		}
		return (int)nums_length;
	}
};

int main()
{
	return 0;
}