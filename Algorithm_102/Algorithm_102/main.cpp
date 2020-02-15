/*
题目描述
操作给定的二叉树，将其变换为源二叉树的镜像。
输入描述:
二叉树的镜像定义：源二叉树
   8
  /  \
 6   10
/ \  / \
5  7 9 11
镜像二叉树
  8
 /  \
10   6
/ \  / \
11 9 7  5
*/


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(nullptr), right(nullptr) {
	}
};

/*
思路一：
①用一个队列，队列里面首先保存根节点，然后出队，将根节点的左右子树交换，然后
将根的左右节点插入队列（若前插入再交换则无法确定谁是左右节点）。
②重复①
#include <queue>
class Solution {
public:
	void Mirror(TreeNode *pRoot) {
		std::queue<TreeNode*> que;
		TreeNode* root = pRoot;
		if (pRoot == nullptr) {
			return;
		}
		que.push(pRoot);
		while (!que.empty()) {
			root = que.front();
			que.pop();
			TreeNode* temp = root->left;
			root->left = root->right;
			root->right = temp;
			if (root->left != nullptr) {
				que.push(root->left);
			}
			if (root->right != nullptr) {
				que.push(root->right);
			}
		}
	}
};
*/

//递归做法，思路与上面大致相同
class Solution {
public:
	void Mirror(TreeNode *pRoot) {
		if (pRoot == nullptr) {
			return;
		}
		TreeNode* temp = pRoot->left;
		pRoot->left = pRoot->right;
		pRoot->right = temp;
		Mirror(pRoot->left);
		Mirror(pRoot->right);
	}
};

int main()
{
	return 0;
}