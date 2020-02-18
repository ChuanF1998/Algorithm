/*
题目描述
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
*/


#include <vector>
using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

};

class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (pre.size() == 0 || vin.size() == 0) {
			return nullptr;
		}
		int p_end = (int)pre.size() - 1;
		int v_end = (int)vin.size() - 1;
		return rebuilt(pre, vin, 0, p_end, 0, v_end);
	}

	TreeNode* rebuilt(vector<int>& pre, vector<int>& vin, int p_begin, int p_end, int v_begin, int v_end)
	{
		if (v_begin > v_end) {
			return nullptr;
		}
		TreeNode* t = new TreeNode(pre[p_begin]);
		for (int i = v_begin; i <= v_end; ++i) {
			if (vin[i] == pre[p_begin]) {
				t->left = rebuilt(pre, vin, p_begin + 1, p_begin + i - v_begin, v_begin, i - 1);
				t->right = rebuilt(pre, vin, p_begin + i - v_begin + 1, p_end, i + 1, v_end);
			}
		}
		return t;
	}
};

int main()
{
	return 0;
}