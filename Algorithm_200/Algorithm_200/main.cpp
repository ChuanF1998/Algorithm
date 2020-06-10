/*
��Ŀ��ħ��תȦȦ
��Ŀ����
ţţ��ϲ���������������ţ���͸�����һ����1Ϊ������{n}n�����Ķ�������
������������������һЩ�ӹ���

ţţ�ո�ѧ��תȦȦ�����Ժ�ϲ����ת�������������Ŷ���������m����ת��

ÿ����תţţ��ָ��һ����㣬������������Ϊ���������е����н������Ҷ��ӻ�����

��β���֮��ţţϣ������������ķ�ʽ���������֮��Ķ�������
ʾ��1
����
����
5,3,[4,3,0,0,0],[2,0,0,5,0],[3,1,5]
���
����
[2,3,1,5,4]
˵��
�ʼ1�������Ϊ4���Ҷ���Ϊ2
2�������Ϊ3.
4���Ҷ���Ϊ5.
��һ�β������3�����3û�ж��ӣ�����û�з����仯
�ڶ��β������1�����1������ӱ�Ϊ2���Ҷ��ӱ�Ϊ4.
���4������ӱ�Ϊ5���Ҷ��ӱ�Ϊ�����ڡ����
���2������ӱ�Ϊ�����ڣ��Ҷ��ӱ��3
�����β������5�����5û�ж��ӣ��������仯��
�ʼ1�������Ϊ2���Ҷ���Ϊ4
2���Ҷ���Ϊ3.
4�������Ϊ5.
����������Ϊ[2,3,1,5,4]
*/
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;


//�÷�����ʱ
class Solution {
public:
	/**
	* ħ��תȦȦ
	* @param n int����
	* @param m int����
	* @param l int����vector
	* @param r int����vector
	* @param k int����vector
	* @return int����vector
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
	* ħ��תȦȦ
	* @param n int����
	* @param m int����
	* @param l int����vector
	* @param r int����vector
	* @param k int����vector
	* @return int����vector
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