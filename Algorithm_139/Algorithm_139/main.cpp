/*
题目描述
请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，
第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推
*/



#include <vector>
#include <queue>
#include <stack>
using namespace std;
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
	vector<vector<int> > Print(TreeNode* pRoot) {
		vector<vector<int> > arr;
		//根节点为空
		if (pRoot == nullptr) {
			return arr;
		}
		queue<TreeNode*> q;
		vector<int> sub;
		bool is_odd = true;
		TreeNode* root = pRoot;
		q.push(root);   //放入根节点
		while (!q.empty()) {
			int size = (int)q.size();
			//遍历一层
			while (size--) {
				TreeNode* tmp = q.front();
				q.pop();
				sub.push_back(tmp->val);
				if (tmp->left) {
					q.push(tmp->left);
				}
				if (tmp->right) {
					q.push(tmp->right);
				}
			}
			//奇数层不变，偶数层逆置
			if (is_odd == true) {
				arr.push_back(sub);
				is_odd = false;
			}
			else {
				reverse(sub.begin(), sub.end());
				arr.push_back(sub);
				is_odd = true;
			}
			sub.clear();
		}
		return arr;
	}

};

int main()
{
	return 0;
}