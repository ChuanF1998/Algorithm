/*
��Ŀ����
���������Ķ�����������任ΪԴ�������ľ���
��������:
�������ľ����壺Դ������
   8
  /  \
 6   10
/ \  / \
5  7 9 11
���������
  8
 /  \
10   6
/ \  / \
11 9 7  5
*/


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(nullptr), right(nullptr) {
	}
};

/*
˼·һ��
����һ�����У������������ȱ�����ڵ㣬Ȼ����ӣ������ڵ����������������Ȼ��
���������ҽڵ������У���ǰ�����ٽ������޷�ȷ��˭�����ҽڵ㣩��
���ظ���
#include <queue>
class Solution {
public:
	void Mirror(TreeNode *pRoot) {
		std::queue<TreeNode*> que;
		TreeNode* root = pRoot;
		if (pRoot == nullptr) {
			return;
		}
		que.push(pRoot);
		while (!que.empty()) {
			root = que.front();
			que.pop();
			TreeNode* temp = root->left;
			root->left = root->right;
			root->right = temp;
			if (root->left != nullptr) {
				que.push(root->left);
			}
			if (root->right != nullptr) {
				que.push(root->right);
			}
		}
	}
};
*/

//�ݹ�������˼·�����������ͬ
class Solution {
public:
	void Mirror(TreeNode *pRoot) {
		if (pRoot == nullptr) {
			return;
		}
		TreeNode* temp = pRoot->left;
		pRoot->left = pRoot->right;
		pRoot->right = temp;
		Mirror(pRoot->left);
		Mirror(pRoot->right);
	}
};

int main()
{
	return 0;
}