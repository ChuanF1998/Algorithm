/*
��Ŀ����
����һ�Ŷ������ĸ��ڵ��һ����������ӡ���������н��ֵ�ĺ�Ϊ��������������·����
·������Ϊ�����ĸ���㿪ʼ����һֱ��Ҷ����������Ľ���γ�һ��·����
(ע��: �ڷ���ֵ��list�У����鳤�ȴ�����鿿ǰ)
*/

#include <vector>
#include <algorithm>


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
	std::vector<std::vector<int> > FindPath(TreeNode* root, int expectNumber) {
		std::vector<std::vector<int> > arr;
		std::vector<int> temp;
		int sum = 0;
		func(root, temp, arr, sum, expectNumber);
		sort(arr.begin(), arr.end());
		return arr;
	}

	void func(TreeNode* root, std::vector<int>& temp, std::vector<std::vector<int> >& arr, int& sum, int& expectNumber)
	{
		//��ǰ�ڵ�Ϊ��ֱ���˳�
		if (root == nullptr) {
			return;
		}
		//���ϵ�ǰ�ڵ㣬������
		sum += root->val;
		temp.push_back(root->val);
		//����Ҷ�ӽڵ㣬��������򱣴�����飬�Ƴ������ָ���ǰ
		if (root->left == nullptr && root->right == nullptr && sum == expectNumber) {
			arr.push_back(temp);
			sum -= root->val;
			temp.pop_back();
			return;
		}
		//�ж�����������֮��Ҳ�ָ���ǰ
		func(root->left, temp, arr, sum, expectNumber);
		func(root->right, temp, arr, sum, expectNumber);
		sum -= root->val;
		temp.pop_back();
		return;
	}
};

int main()
{
	return 0;
}