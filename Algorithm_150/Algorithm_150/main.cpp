/*
��Ŀ����
�����ϿΣ���ʦ����С����ô����ӷ��ͳ˷����˷������ȼ����ڼӷ����������һ������������ţ���ô�������ȼ�����ߵġ����磺
1+2*3=7
1*(2+3)=5
1*2*3=6
(1+2)*3=9
����С��ϣ��������������3����a��b��c���������м����"+"�� "*"�� "("�� ")"���ţ��ܹ���õ����ֵ��
��������:
һ��������a��b��c (1 <= a, b, c <= 10)
�������:
�ܹ���õ����ֵ
ʾ��1
����
1 2 3

���
9
*/

//ͨ�ýⷨ�ƹ㵽n����̬�滮
#include <limits.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class solution
{
public:
	int GetMax(vector<int>& arr)
	{
		size_t size = arr.size();
		vector<vector<int> > m(size, vector<int>(size, INT_MIN)); //������ÿһ��������Ϊint����Сֵ,
		//INT_MAX��ͷ�ļ�<limits.h>
		//������������
		for (int j = 0; j < size; ++j) {
			for (int i = j; i >= 0; --i) {
				if (i == j) {
					m[i][j] = arr[j];
				}
				//ÿ�����ȡֵ�����ԣ��ҳ�����
				//���õ�Ϊm[1][4],��ô����
				//max(m[1][1] + m[2][4], m[1][1] * m[2][4])
				//max(m[1][2] + m[3][4], m[1][2] * m[3][4])
				//max(m[1][3] + m[4][4], m[1][3] * m[4][4])
				//���Ի�һ�������΢��֤һ��
				//ȡ������������ֵ�����ֵ
				for (int k = j - 1; k >= i; --k) {
					int tmp = max(m[i][k] + m[k + 1][j], m[i][k] * m[k + 1][j]);
					m[i][j] = max(tmp, m[i][j]);
				}
			}
		}
		//���m[0][size - 1]��������ֵ
		return m[0][size - 1];
	}
};

int main()
{
	int a;
	int b;
	int c;
	solution s;
	vector<int> arr(3);
	while (cin >> a >> b >> c)
	{
		arr.push_back(a);
		arr.push_back(b);
		arr.push_back(c);
		cout << s.GetMax(arr) << endl;
	}
	return 0;
}