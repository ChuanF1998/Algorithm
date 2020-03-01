



#include <stack>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(nullptr), right(nullptr) {
	}
};

//方法一：用一个辅组栈
class Solution01 {
public:
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		std::stack<TreeNode*> s;
		NodePush(pRootOfTree, s);
		TreeNode* prev = nullptr;
		TreeNode* next = nullptr;
		//初始化，prev保存当前节点，next保存后一个节点
		if (!s.empty()) {
			prev = s.top();
			s.pop();
			prev->right = next;
			next = prev;
		}
		while (!s.empty()) {
			prev = s.top();
			s.pop();
			prev->right = next; //连接后面（next域）
			next->left = prev;  //连接前面（prev域）
			next = prev;
		}
		return prev;
	}

	//将所有节点按照中序入栈
	void NodePush(TreeNode* pRoot, std::stack<TreeNode*>& s)
	{
		if (pRoot == nullptr) {
			return;
		}
		NodePush(pRoot->left, s);
		s.push(pRoot);
		NodePush(pRoot->right, s);
	}
};


//递归，二叉搜索树的中序遍历是有序的
class Solution {
public:
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		TreeNode* pLastNode = nullptr;
		func(pRootOfTree, pLastNode);
		TreeNode* head = pLastNode;
		while (head != nullptr && head->left != nullptr) {
			head = head->left;
		}
		return head;
	}

	void func(TreeNode* pRoot, TreeNode*& pLastNode)
	{
		if (pRoot == nullptr) {
			return;
		}
		//保存当前节点
		TreeNode* pCur = pRoot;
		//左子树不为空进入左子树
		if (pCur->left != nullptr) {
			func(pRoot->left, pLastNode);
		}
		//
		pCur->left = pLastNode;
		
		//当前节点不为空，那么当前节点的右孩子连上它的根节点
		if (pLastNode != nullptr) {
			pLastNode->right = pCur;
		}
		//pLastNode保存的是当前节点，对于下一个节点来说他就是上一个节点
		pLastNode = pCur;
		if (pCur->right != nullptr) {
			func(pRoot->right, pLastNode);
		}

	}
};



int main()
{
	return 0;
}
