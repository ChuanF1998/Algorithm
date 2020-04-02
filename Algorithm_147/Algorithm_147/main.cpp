/*
��Ŀ����
С����һ�����ϵ���Ϸ�����������ž������Ϸ����˹���顣��Ϊ���ȽϹ��ϣ����Թ����һ��Ķ���˹���鲻ͬ��
ӫĻ��һ���� n �У�ÿ�ζ�����һ�� 1 x 1 �ķ���������£���ͬһ���У������µķ���������ǰ�ķ���֮�ϣ�
��һ���з��鶼��ռ��ʱ����һ�лᱻ��ȥ�����õ�1�֡�
��һ�죬С���ֿ���һ����Ϸ�����浽�� m ����������ʱ������̫���ľ͹ص��ˣ�С��ϣ��������������Ϸ����õķ�����
��������:
��һ�������� n, m
�ڶ��� m ������c1, c2, ... , cm �� ci ��ʾ�� i ���������ڵڼ���
���� 1 <= n, m <= 1000, 1 <= ci <= n
�������:
С�������Ϸ��õķ���
ʾ��1
����
����
3 9
1 1 2 2 2 3 1 2 3
���
����
2
*/

//����һ���������򣬼�����ͬ�ַ�������һֱ�����С�ģ�ע���������(arr[i] - arr[i - 1] > 1������)
//�����������⹹��һ�����飬�������ֵ��Ϊ��������±꣬�����������ֵ��ѡ��С�ġ�

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class solution
{
public:
	int Getscore(vector<int>& arr, int m)
	{
		if (arr.size() == 0) {
			return 0;
		}
		sort(arr.begin(), arr.end());
		int flag = arr[0];
		int min_size = m + 1;
		int max_size = 1;
		for (size_t i = 1; i < arr.size(); ++i) {
			if (arr[i] - arr[i - 1] > 1) {
				return 0;
			}
			if (arr[i] == flag) {
				max_size++;
			}
			else {
				if (min_size > max_size) {
					min_size = max_size;
				}
				max_size = 1;
				flag = arr[i];
			}
		}
		if (min_size > max_size) {
			min_size = max_size;
		}
		return min_size;
	}
};


int main()
{
	int n;
	int m;
	solution s;
	while (cin >> n >> m) {
		vector<int> arr(m);
		for (int i = 0; i < m; ++i) {
			cin >> arr[i];
		}
		cout << s.Getscore(arr, m) << endl;
	}
	return 0;
}