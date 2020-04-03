/*
��Ŀ����
�ֵ��˷��յļ��ڣ�ǡ��С��ȥţţ�Ĺ�԰�����档
ţţ��˵����������԰��ÿ���ط�������ָ�ƣ�С�ײ�̫���ţ��������뿼��ţţ��
�ڹ�԰����N��ƻ����ÿ��ƻ��������Ϊai��С��ϣ��֪��������������x��ƻ����������һ�ѵġ�
ţţ�����������̫�򵥣�����ϣ�����������ش�
��������:
��һ��һ����n(1 <= n <= 105)��
�ڶ���n����ai(1 <= ai <= 1000)����ʾ������������i���ж���ƻ��
������һ����m(1 <= m <= 105)����ʾ��m��ѯ�ʡ�
������m����qi����ʾС��ϣ��֪����qi��ƻ��������һ�ѡ�
�������:
m�У���i�������qi��ƻ��������һ�ѡ�

ʾ��1
����
5
2 7 3 4 9
3
1 25 11

���
1
5
3
*/


//ע��lower_bound�÷������ص��ǵ�����

#include <vector>
#include <iostream>
using namespace std;

class solution
{
public:
	vector<int> Get(vector<int>& apple, vector<int>& que)
	{
		vector<int> heap;
		if (apple.size() == 0 || que.size() == 0) {
			return heap;
		}
		vector<int> sum(apple.size());
		int count = 0;
		for (size_t i = 0; i < apple.size(); ++i) {
			count += apple[i];
			sum[i] = count;
		}
		int pos;
		int size = (int)sum.size() - 1;
		for (size_t i = 0; i < que.size(); ++i) {
			func(sum, que[i], 0, size, pos);
			//auto it = lower_bound(sum.begin(), sum.end(), que[i]);
			//heap.push_back(it - sum.begin() + 1);
			heap.push_back(pos + 1);
		}
		return heap;
	}

	void func(vector<int>& arr, int val, int begin, int end, int& pos)
	{
		int middle = (begin + end) >> 1;
		if (val == arr[middle]) {
			pos = middle;
			return;
		}
		if (end == begin + 1 && arr[begin] > val) {
			pos = begin;
			return;
		}
		if (end == begin + 1 && arr[begin] < val) {
			pos = end;
			return;
		}
		if (val < arr[middle]) {
			func(arr, val, begin, middle, pos);
		}
		if (val > arr[middle]) {
			func(arr, val, middle, end, pos);
		}
		return;
	}
};

int main()
{
	int n;
	solution s;
	while (cin >> n) {
		vector<int> apple(n);
		for (int i = 0; i < n; ++i) {
			cin >> apple[i];
		}
		int m;
		cin >> m;
		vector<int> que(m);
		for (int i = 0; i < m; ++i) {
			cin >> que[i];
		}
		vector<int> arr = s.Get(apple, que);
		for (size_t i = 0; i < arr.size(); ++i) {
			cout << arr[i] << endl;
		}
	}
	return 0;
}