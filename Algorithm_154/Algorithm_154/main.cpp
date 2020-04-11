/*
��Ŀ����
ǰ�����·�ӳ��ͷ����Ҽ�ֱ��ò����ٻ��ˣ�
��Ϊһ��̽���ռ�AI���о���Ա��������Ȼȥ���˴���硣
����̫���˷ܣ�������������һ����ֵ��Σ������μ��Լ�
������һ����ʩ����ħ������Ԩ��������Ҫ���ϴ���Ԩ��

��֪��Ԩ��N��̨�׹��ɣ�1 <= N <= 1000)������ÿ�����������
����2���������ݸ�̨��(1��2��4��....)�������̸�����������
�ж����ַ���������Ԩ
��������:
���빲��M�У�(1<=M<=1000)

��һ������һ����M��ʾ�ж�����������ݣ�

������M�У�ÿһ�ж�����һ��N��ʾ��Ԩ��̨����
�������:
������ܵ�������Ԩ�ķ�ʽ
ʾ��1
����
����
4
1
2
3
4
���
����
1
2
3
6
��ע:
Ϊ�˷�ֹ������ɽ������10^9 + 3ȡģ
*/

#include <iostream>
#include <vector>
using namespace std;
vector<int> result(1001);
vector<int> flag;

class solution
{
public:
	void func1()
	{
		int i = 1;
		while (i <= 1000) {
			flag.push_back(i);
			i <<= 1;
		}
	}

	void func2()
	{
		result[0] = 1;
		for (size_t i = 1; i < result.size(); ++i) {
			long long val = 0;
			for (size_t j = 0; j < flag.size(); ++j) {
				if (i >= flag[j]) {
					val += result[i - flag[j]];
				}
				else {
					break;
				}
			}
			result[i] = (int)(val % 1000000003);
		}
	}
};



int main()
{
	solution s;
	s.func1();
	s.func2();
	int m;
	while (cin >> m) {
		vector<int> arr(m);

		for (int i = 0; i < m; ++i) {
			cin >> arr[i];
		}
		for (int i = 0; i < m; ++i) {
			cout << result[arr[i]] << endl;
		}
	}
}