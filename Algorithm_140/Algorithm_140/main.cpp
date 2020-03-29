/*
��Ŀ����
���ϵ��°����ӡ��������ͬһ����������������ÿһ�����һ�С�
*/

#include <queue>
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
	vector<vector<int> > Print(TreeNode* pRoot) {
		vector<vector<int> > arr;
		if (pRoot == nullptr) {
			return arr;
		}
		TreeNode* root = pRoot;
		queue<TreeNode*> q;
		vector<int> sub;
		q.push(root);
		while (!q.empty()) {
			int size = (int)q.size();
			while (size--) {
				TreeNode* tmp = q.front();
				sub.push_back(tmp->val);
				q.pop();
				if (tmp->left) {
					q.push(tmp->left);
				}
				if (tmp->right) {
					q.push(tmp->right);
				}
			}
			arr.push_back(sub);
			sub.clear();
		}
		return arr;
	}

};

int main()
{
	return 0;
}