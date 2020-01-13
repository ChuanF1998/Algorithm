/*
给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。

说明:

初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
示例:

输入:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

输出: [1,2,2,3,5,6]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


#include <vector>
#include <algorithm>

class Solution {
public:
	void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
		for (int i = 0; i < n; ++i) {
			nums1[m + i] = nums2[i];
		}
		std::sort(nums1.begin(), nums1.end());
	}
};

int main()
{
	return 0;
}


/*
法2：时间复杂度O（m+n）
class Solution {
public:
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
while(n--) {
if(m - 1 < 0) {
nums1[m] = nums2[n];
++m;
}
else if(nums2[n] >= nums1[m - 1]) {
nums1[m + n] = nums2[n];
}
else {
nums1[m + n] = nums1[m - 1];
--m;
++n;
}
}
return;
}
};
*/