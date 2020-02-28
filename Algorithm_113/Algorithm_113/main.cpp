/*
题目描述
输入一颗二叉树的根节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
(注意: 在返回值的list中，数组长度大的数组靠前)
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
		//当前节点为空直接退出
		if (root == nullptr) {
			return;
		}
		//加上当前节点，并插入
		sum += root->val;
		temp.push_back(root->val);
		//既是叶子节点，和又相等则保存此数组，推出后必须恢复以前
		if (root->left == nullptr && root->right == nullptr && sum == expectNumber) {
			arr.push_back(temp);
			sum -= root->val;
			temp.pop_back();
			return;
		}
		//判断左右子树，之后也恢复以前
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