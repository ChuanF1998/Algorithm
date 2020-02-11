/*
题目描述
输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
*/


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
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		bool result = false;
		//都不为空才进入
		if (pRoot1 != nullptr && pRoot2 != nullptr) {
			if (pRoot1->val == pRoot2->val) {
				//两个节点的值相等且都不为空时则进入
				result = is_subtree(pRoot1, pRoot2);
			}
			//前面匹配失败的情况
			if (!result) {
				result = HasSubtree(pRoot1->left, pRoot2);
			}
			if (!result) {
				result = HasSubtree(pRoot1->right, pRoot2);
			}
		}
		return result;
	}

	bool is_subtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		//表示匹配成功
		if (pRoot2 == nullptr) {
			return true;
		}
		//pRoot1先于pRoot2为空，匹配失败
		if (pRoot1 == nullptr) {
			return false;
		}
		if (pRoot1->val != pRoot2->val) {
			return false;
		}
		return is_subtree(pRoot1->left, pRoot2->left) && is_subtree(pRoot1->right, pRoot2->right);
	}
};

int main()
{
	return 0;
}