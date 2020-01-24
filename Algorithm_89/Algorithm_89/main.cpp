/*
给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: nums = [1,2,3]
输出:
[
[3],
[1],
[2],
[1,2,3],
[1,3],
[2,3],
[1,2],
[]
]
 来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subsets
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		int S = nums.size();
		int N = 1 << S;
		vector<vector<int> > res;
		for (int i = 0; i < N; ++i) {
			vector<int> v;
			for (int j = 0; j < S; ++j) {
				int k = i & (1 << j);
				if (i & (1 << j))
					v.push_back(nums[j]);
			}

			res.push_back(v);
		}
		return res;
	}
};

//回溯法
class Solution1 {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int> > arr;
		vector<int> s;
		func(arr, nums, s, 0);
		return arr;
	}

	void func(vector<vector<int> >& arr, vector<int>& nums, vector<int>& s, int flag)
	{
		arr.push_back(s);
		for (int i = flag; i < (int)nums.size(); ++i) {
			s.push_back(nums[i]);
			func(arr, nums, s, i + 1);
		}
		s.pop_back();
	}
};

int main()
{
	vector<int> arr{ 1, 2, 3 };
	Solution s;
	s.subsets(arr);
	return 0;
}