/*
��Ŀ����
��ʵ��һ����������֮���δ�ӡ������������һ�а��մ����ҵ�˳���ӡ��
�ڶ��㰴�մ��������˳���ӡ�������а��մ����ҵ�˳���ӡ���������Դ�����
*/



#include <vector>
#include <queue>
#include <stack>
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
		//���ڵ�Ϊ��
		if (pRoot == nullptr) {
			return arr;
		}
		queue<TreeNode*> q;
		vector<int> sub;
		bool is_odd = true;
		TreeNode* root = pRoot;
		q.push(root);   //������ڵ�
		while (!q.empty()) {
			int size = (int)q.size();
			//����һ��
			while (size--) {
				TreeNode* tmp = q.front();
				q.pop();
				sub.push_back(tmp->val);
				if (tmp->left) {
					q.push(tmp->left);
				}
				if (tmp->right) {
					q.push(tmp->right);
				}
			}
			//�����㲻�䣬ż��������
			if (is_odd == true) {
				arr.push_back(sub);
				is_odd = false;
			}
			else {
				reverse(sub.begin(), sub.end());
				arr.push_back(sub);
				is_odd = true;
			}
			sub.clear();
		}
		return arr;
	}

};

int main()
{
	return 0;
}