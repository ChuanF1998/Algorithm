/*
题目描述
从上往下打印出二叉树的每个节点，同层节点从左至右打印。
*/

//二叉树的层序遍历，用队列

#include <vector>
#include <queue>

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
	std::vector<int> PrintFromTopToBottom(TreeNode* root) {
		std::vector<int> arr;
		std::queue<TreeNode*> q;
		if (root == nullptr) {
			return arr;
		}
		q.push(root);
		while (!q.empty()) {
			TreeNode* temp = q.front();
			arr.push_back(temp->val);
			q.pop();
			if (temp->left != nullptr) {
				q.push(temp->left);
			}
			if (temp->right != nullptr) {
				q.push(temp->right);
			}
		}
		return arr;
	}
};

int main()
{
	return 0;
}