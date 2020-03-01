



#include <stack>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(nullptr), right(nullptr) {
	}
};

//����һ����һ������ջ
class Solution01 {
public:
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		std::stack<TreeNode*> s;
		NodePush(pRootOfTree, s);
		TreeNode* prev = nullptr;
		TreeNode* next = nullptr;
		//��ʼ����prev���浱ǰ�ڵ㣬next�����һ���ڵ�
		if (!s.empty()) {
			prev = s.top();
			s.pop();
			prev->right = next;
			next = prev;
		}
		while (!s.empty()) {
			prev = s.top();
			s.pop();
			prev->right = next; //���Ӻ��棨next��
			next->left = prev;  //����ǰ�棨prev��
			next = prev;
		}
		return prev;
	}

	//�����нڵ㰴��������ջ
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


//�ݹ飬��������������������������
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
		//���浱ǰ�ڵ�
		TreeNode* pCur = pRoot;
		//��������Ϊ�ս���������
		if (pCur->left != nullptr) {
			func(pRoot->left, pLastNode);
		}
		//
		pCur->left = pLastNode;
		
		//��ǰ�ڵ㲻Ϊ�գ���ô��ǰ�ڵ���Һ����������ĸ��ڵ�
		if (pLastNode != nullptr) {
			pLastNode->right = pCur;
		}
		//pLastNode������ǵ�ǰ�ڵ㣬������һ���ڵ���˵��������һ���ڵ�
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
