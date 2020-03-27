/*
��Ŀ����
����һ�������������е�һ����㣬���ҳ��������˳�����һ����㲢�ҷ��ء�
ע�⣬���еĽ�㲻�����������ӽ�㣬ͬʱ����ָ�򸸽���ָ�롣
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
		//��ָ��ֱ�ӷ��ؿ�
		if (pNode == nullptr) {
			return nullptr;
		}
		//�ڵ����������
		TreeLinkNode* tmp = pNode->right;
		while (tmp && tmp->left) {
			tmp = tmp->left;
		}
		if (tmp) {
			return tmp;
		}
		//�ڵ㲻����������
		TreeLinkNode* parent = pNode->next;
		if (parent == nullptr) {
			return nullptr;
		}
		//������һ�����ڵ���������Լ��򷵻ظ��ڵ�
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