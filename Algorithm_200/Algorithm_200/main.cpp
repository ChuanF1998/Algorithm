/*
题目：魔力转圈圈
题目描述
牛牛很喜欢玩二叉树。这天牛能送给了他一个以1为根结点的{n}n个结点的二叉树，
他想对这个二叉树进行一些加工。

牛牛刚刚学会转圈圈，所以很喜欢旋转。现在他想对这颗二叉树进行m次旋转。

每次旋转牛牛会指定一个结点，并让以这个结点为根的子树中的所有结点的左右儿子互换。

多次操作之后，牛牛希望以中序遍历的方式输出操作完之后的二叉树。
示例1
输入
复制
5,3,[4,3,0,0,0],[2,0,0,5,0],[3,1,5]
输出
复制
[2,3,1,5,4]
说明
最开始1的左儿子为4，右儿子为2
2的左儿子为3.
4的右儿子为5.
第一次操作结点3，结点3没有儿子，所以没有发生变化
第二次操作结点1，结点1的左儿子变为2，右儿子变为4.
结点4的左儿子变为5，右儿子变为不存在。结点
结点2的左儿子变为不存在，右儿子变成3
第三次操作结点5，结点5没有儿子，不发生变化。
最开始1的左儿子为2，右儿子为4
2的右儿子为3.
4的左儿子为5.
中序遍历结果为[2,3,1,5,4]
*/
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;


//该方法超时
class Solution {
public:
	/**
	* 魔力转圈圈
	* @param n int整型
	* @param m int整型
	* @param l int整型vector
	* @param r int整型vector
	* @param k int整型vector
	* @return int整型vector
	*/
	vector<int> solve(int n, int m, vector<int>& l, vector<int>& r, vector<int>& k) {
		// write code here
		queue<int> q;
		for (size_t i = 0; i < k.size(); ++i) {
			q.push(k[i]);
			while (!q.empty()) {
				int p = q.front() - 1;
				swap(l[p], r[p]);
				q.pop();
				if (l[p] != 0) {
					q.push(l[p]);
				}
				if (r[p] != 0) {
					q.push(r[p]);
				}
			}
		}
		vector<int> result(n, 0);
		int cur = 0;
		stack<int> s;
		s.push(1);
		while (!s.empty()) {
			while (!s.empty() && l[s.top() - 1] != 0) {
				s.push(l[s.top() - 1]);
			}
			int p = s.top() - 1;
			s.pop();
			result[cur++] = p + 1;
			while (!s.empty() && r[p] == 0) {
				p = s.top() - 1;
				s.pop();
				result[cur++] = p + 1;
			}
			if (r[p] != 0) {
				s.push(r[p]);
			}
			
		}
		return result;
	}
};


class Solution1 {
public:
	/**
	* 魔力转圈圈
	* @param n int整型
	* @param m int整型
	* @param l int整型vector
	* @param r int整型vector
	* @param k int整型vector
	* @return int整型vector
	*/
	void func(int node, vector<int>& l, vector<int>& r, vector<int>& result)
	{
		if (node == 0) {
			return;
		}
		func(l[node - 1], l, r, result);
		result.push_back(node);
		func(r[node - 1], l, r, result);
		return;
	}
	void rev(int node, int cur, vector<int>& l, vector<int>& r, vector<int>& record)
	{
		if (node == 0) {
			return;
		}
		record[node - 1] = (record[node - 1] + cur) & 1;
		if (record[node - 1] > 0) {
			swap(l[node - 1], r[node - 1]);
		}
		rev(l[node - 1], record[node - 1], l, r, record);
		rev(r[node - 1], record[node - 1], l, r, record);
		return;
	}
	vector<int> solve(int n, int m, vector<int>& l, vector<int>& r, vector<int>& k) {
		// write code here
		vector<int> record(n, 0);
		for (int i = 0; i < m; ++i) {
			record[k[i] - 1] += 1;
		}
		rev(1, 0, l, r, record);
		vector<int> result;
		func(1, l, r, result);
		return result;
	}
};


int main()
{
	vector<int> l{ 4, 3, 0, 0, 0 };
	vector<int> r{ 2, 0, 0, 5, 0 };
	vector<int> k{ 3, 1, 5 };
	Solution ss;
	ss.solve(5, 3, l, r, k);
	return 0;
}