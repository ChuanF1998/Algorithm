/*
����һ���ǿ����飬���ش������е������������������ڣ��򷵻���������������Ҫ���㷨ʱ�临�Ӷȱ�����O(n)��

ʾ�� 1:

����: [3, 2, 1]

���: 1

����: ����������� 1.
ʾ�� 2:

����: [1, 2]

���: 2

����: ���������������, ���Է��������� 2 .
ʾ�� 3:

����: [2, 2, 3, 1]

���: 1

����: ע�⣬Ҫ�󷵻ص������������ָ��������Ψһ���ֵ�����
��������ֵΪ2���������Ƕ��ŵڶ���

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/third-maximum-number
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

/*
˼·��������ʱ������max��medium��min��
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