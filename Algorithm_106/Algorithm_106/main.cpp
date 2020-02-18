/*
��Ŀ����
����ĳ��������ǰ���������������Ľ�������ؽ����ö�������
���������ǰ���������������Ľ���ж������ظ������֡�
��������ǰ���������{1,2,4,7,3,5,6,8}�������������{4,7,2,1,5,3,8,6}�����ؽ������������ء�
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