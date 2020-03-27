/*
题目描述
给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
*/


struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(nullptr), right(nullptr), next(nullptr) {

	}
};

class Solution {
public:
	TreeLinkNode* GetNext(TreeLinkNode* pNode)
	{ 
		//空指针直接返回空
		if (pNode == nullptr) {
			return nullptr;
		}
		//节点存在右子树
		TreeLinkNode* tmp = pNode->right;
		while (tmp && tmp->left) {
			tmp = tmp->left;
		}
		if (tmp) {
			return tmp;
		}
		//节点不存在右子树
		TreeLinkNode* parent = pNode->next;
		if (parent == nullptr) {
			return nullptr;
		}
		//遇到第一个父节点的左孩子是自己则返回父节点
		while (parent && parent->right == pNode) {
			pNode = parent;
			parent = parent->next;
		}
		return parent;
	}
};

int main()
{
	return 0;
}