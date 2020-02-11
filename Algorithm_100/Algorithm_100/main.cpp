/*
��Ŀ����
�������ö�����A��B���ж�B�ǲ���A���ӽṹ����ps������Լ��������������һ�������ӽṹ��
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
		//����Ϊ�ղŽ���
		if (pRoot1 != nullptr && pRoot2 != nullptr) {
			if (pRoot1->val == pRoot2->val) {
				//�����ڵ��ֵ����Ҷ���Ϊ��ʱ�����
				result = is_subtree(pRoot1, pRoot2);
			}
			//ǰ��ƥ��ʧ�ܵ����
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
		//��ʾƥ��ɹ�
		if (pRoot2 == nullptr) {
			return true;
		}
		//pRoot1����pRoot2Ϊ�գ�ƥ��ʧ��
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