/*
��Ŀ����
������A��������B ����С��������ָ �ܱ�A��B��������С��������ֵ�����һ���㷨��������A��B����С��������

��������:
��������������A��B��

�������:
���A��B����С��������

ʾ��1
����
5 7

���
35
*/

//˼·��Ϊ�˼�Сʱ�临�Ӷȣ���һ����ʽ�� �������ĳ˻� = �����������Լ�� * ��С������
//����շת����������Լ������������������ڱ����ϵ-��ֱ���������Ǹ���
#include <iostream>
using namespace std;

class Least_common_multiple
{
public:
	long long Get(long long x, long long y)
	{
		if (x == 0 || y == 0){ //������Ҫ����Ϊ0
			return 0;
		}
		if (x<y) {  //��֤x����Ϊ���
			long long temp = x;
			x = y;
			y = temp;
		}
		if (x%y == 0){  //xΪ��С������
			return x;
		}
		long long z = x*y;
		long long dividend;
		long long Greatest_common_divisor; //���Լ��
		while (x>y) {
			dividend = x%y;
			if (dividend == 0) {
				Greatest_common_divisor = y;
				break;
			}
			if (dividend == 1) {
				Greatest_common_divisor = dividend;
				break;
			}
			x = y;
			y = dividend;
		}
		return z / Greatest_common_divisor;
	}
};

int main()
{
	long long x, y;
	Least_common_multiple s;
	while (cin >> x >> y) {
		cout << s.Get(x, y) << endl;
	}
	return 0;
}