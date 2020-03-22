/*
题目描述
输入一棵二叉树，判断该二叉树是否是平衡二叉树。
*/

#include <algorithm>

class TreeNode
{
public:
	TreeNode* left;
	TreeNode* right;
};

class Solution {
public:
	bool IsBalanced_Solution(TreeNode* pRoot) {
		int avl = 0;
		func(pRoot, avl);
		if (avl > 1 || avl < -1) {
			return false;
		}
		return true;
	}

	int func(TreeNode* pRoot, int& avl)
	{
		if (pRoot == nullptr) {
			return 0;
		}

		int left = func(pRoot->left, avl) + 1;
		int right = func(pRoot->right, avl) + 1;
		if (avl >= 0 && left - right > avl) {
			avl = left - right;
		}
		if (avl <= 0 && left - right < avl) {
			avl = left - right;
		}
		return (left  > right) ? left : right;
	}
};

class Solution1 {
public:
	bool IsBalanced_Solution(TreeNode* pRoot) {
		int depth;
		return func(pRoot, depth);
	}

	bool func(TreeNode* pRoot, int& depth)
	{
		if (pRoot == nullptr) {
			depth = 0;
			return true;
		}
		int left;
		int right;
		if (func(pRoot->left, left) && func(pRoot->right, right)) {
			if (abs(left - right) <= 1) {
				depth = 1 + std::max(left, right);
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
