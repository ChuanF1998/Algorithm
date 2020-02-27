/*
题目描述
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
*/

//二叉搜索树的后续遍历的最后一个值是二叉搜索树的根节点，注意边界，在判断左右z
//子树时注意范围（不能带入原根节点），这样无限递归

#include <vector>


class Solution {
public:
	bool VerifySquenceOfBST(std::vector<int> sequence) {
		if (sequence.size() == 0) {
			return false;
		}
		return func(sequence, sequence[sequence.size() - 1], 0, sequence.size() - 1);
	}

	bool func(std::vector<int>& arr, int root, int begin, int end)
	{
		if (begin >= end) {
			return true;
		}
		int i = begin;
		//判断左子树是否成立
		for (; i < end; i++) { //分开左右子树
			if (arr[i] > root) {
				break;
			}
		}
		//判断右子树是否成立
		for (int j = i; j < end; j++) {
			if (arr[j] < root) {
				return false;
			}
		}
		return func(arr, arr[i - 1], begin, i - 1) && func(arr, arr[end - 1], i, end - 1);
	}
};

int main()
{
	return 0;
}

