/*
��Ŀ����
����һ�ö��������������ҳ����еĵ�kС�Ľ�㡣���磬 ��5��3��7��2��4��6��8��    �У�
�������ֵ��С˳�����С����ֵΪ4��
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
	TreeNode* KthNode(TreeNode* pRoot, int k)
	{
		TreeNode* r = nullptr;
		int n = 0;
		func(pRoot, r, k, n);
		return r;
	}

	void func(TreeNode* pRoot, TreeNode*& num, int k, int& n)
	{
		if (pRoot == nullptr) {
			return;
		}
		func(pRoot->left, num, k, n);
		n++;
		if (n == k) {
			num = pRoot;
			return;
		}
		func(pRoot->right, num, k, n);
		return;
	}
};

int main()
{
	return 0;
}