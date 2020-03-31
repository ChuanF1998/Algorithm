/*
题目描述
请实现两个函数，分别用来序列化和反序列化二叉树

二叉树的序列化是指：把一棵二叉树按照某种遍历方式的结果以某种格式保存为字符串，
从而使得内存中建立起来的二叉树可以持久保存。序列化可以基于先序、中序、后序、层序
的二叉树遍历方式来进行修改，序列化的结果是一个字符串，序列化时通过 某种符号表示空
节点（#），以 ！ 表示一个结点值的结束（value!）。

二叉树的反序列化是指：根据某种遍历顺序得到的序列化字符串结果str，重构二叉树。
*/


#include <vector>
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
	char* Serialize(TreeNode *root) {
		pre(root);
		int* str = new int[s.size()];
		for (size_t i = 0; i < s.size(); ++i) {
			str[i] = s[i];
		}
		return (char*)str;
	}

	//前序递归遍历
	void pre(TreeNode* root)
	{
		if (root == nullptr) {
			s.push_back('#');
			return;
		}
		s.push_back(root->val);
		pre(root->left);
		pre(root->right);
		return;
	}

	TreeNode* Deserialize(char *str) {
		int * arr = (int*)str;
		TreeNode* root;
		preBuilt(root, arr);
		return root;
	}

	void preBuilt(TreeNode*& root, int*& str)
	{
		if (*str == '#') {
			root = nullptr;
			return;
		}
		root = new TreeNode(*str);
		str++;
		preBuilt(root->left, str);
		str++;
		preBuilt(root->right, str);
		return;
	}
public:
	vector<int> s;
};

int main()
{
	return 0;
}