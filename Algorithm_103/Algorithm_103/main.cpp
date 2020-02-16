/*
��Ŀ����
��ʵ��һ�������������ж�һ�Ŷ������ǲ��ǶԳƵġ�ע�⣬���һ��������ͬ�˶������ľ�����ͬ���ģ�������Ϊ�ԳƵġ�
*/

//��������������ǰ������кʹ�������ǰ�����������Գ�


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
	bool isSymmetrical(TreeNode* pRoot)
	{
		if (pRoot == nullptr) {
			return true;
		}
		return func(pRoot, pRoot);
	}

	bool func(TreeNode* pleft, TreeNode* pright)
	{
		if (pleft == nullptr && pright == nullptr) {
			return true;
		}
		if (pleft == nullptr && pright != nullptr) {
			return false;
		}
		if (pleft != nullptr && pright == nullptr) {
			return false;
		}
		if (pleft->val != pright->val) {
			return false;
		}
		bool is_sym = true;
		is_sym = func(pleft->left, pright->right) && func(pleft->right, pright->left);
		return is_sym;
	}
};

int main()
{
	return 0;
}