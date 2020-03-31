/*
��Ŀ����
��ʵ�������������ֱ��������л��ͷ����л�������

�����������л���ָ����һ�ö���������ĳ�ֱ�����ʽ�Ľ����ĳ�ָ�ʽ����Ϊ�ַ�����
�Ӷ�ʹ���ڴ��н��������Ķ��������Գ־ñ��档���л����Ի����������򡢺��򡢲���
�Ķ�����������ʽ�������޸ģ����л��Ľ����һ���ַ��������л�ʱͨ�� ĳ�ַ��ű�ʾ��
�ڵ㣨#������ �� ��ʾһ�����ֵ�Ľ�����value!����

�������ķ����л���ָ������ĳ�ֱ���˳��õ������л��ַ������str���ع���������
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

	//ǰ��ݹ����
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