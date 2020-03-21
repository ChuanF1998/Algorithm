/*
��Ŀ����
����һ�ö����������������ȡ��Ӹ���㵽Ҷ������ξ����Ľ��
��������Ҷ��㣩�γ�����һ��·�����·���ĳ���Ϊ������ȡ�
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
	int TreeDepth(TreeNode* pRoot)
	{
		if (pRoot == nullptr) {
			return 0;
		}
		else {
			return GetDepth(pRoot);
		}
	}

	int GetDepth(TreeNode* pRoot)
	{
		if (pRoot == nullptr) {
			return 0;
		}
		int left = GetDepth(pRoot->left) + 1;
		int right = GetDepth(pRoot->right) + 1;
		return left > right ? left : right;
	}
};

int main()
{
	return 0;
}