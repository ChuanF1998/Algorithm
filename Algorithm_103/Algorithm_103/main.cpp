/*
题目描述
请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
*/

//二叉树从左往右前序的序列和从右往左前序序列相等则对称


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(nullptr), right(nullptr) {
	}
};

class Solution {
public:
	bool isSymmetrical(TreeNode* pRoot)
	{
		if (pRoot == nullptr) {
			return true;
		}
		return func(pRoot, pRoot);
	}

	bool func(TreeNode* pleft, TreeNode* pright)
	{
		if (pleft == nullptr && pright == nullptr) {
			return true;
		}
		if (pleft == nullptr && pright != nullptr) {
			return false;
		}
		if (pleft != nullptr && pright == nullptr) {
			return false;
		}
		if (pleft->val != pright->val) {
			return false;
		}
		bool is_sym = true;
		is_sym = func(pleft->left, pright->right) && func(pleft->right, pright->left);
		return is_sym;
	}
};

int main()
{
	return 0;
}