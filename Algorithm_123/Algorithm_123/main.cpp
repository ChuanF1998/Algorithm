/*
�й�����

�У�С�����ǣ�

�������ܵļ��㣬С������һ֧��Ʊ����֪���������Ʊ�����쿪ʼ����Ʊ�������±仯��
��һ�첻�䣬�Ժ���һ�죬��һ�죬�����죬��һ�죬�����죬��һ��...�������ơ�

Ϊ������㣬����ÿ���Ǻ͵���Ϊ1����Ʊ��ʼ����ҲΪ1����������Ʊ�ĵ�n��ÿ�ɹ�Ʊֵ����Ǯ��
*/

#include <iostream>
using namespace std;

int Getmoney(int n)
{
	int start = 1;
	if (n == 1) {
		return start;
	}
	int day = 1;
	int tempDay = day;
	for (int i = 1; i < n; ++i) {
		tempDay--;
		if (tempDay >= 0) {
			start++;
		}
		if (tempDay < 0) {
			day++;
			start--;
			tempDay = day;
		}
	}
	return start;
}

int main()
{
	int n;
	while (cin >> n) {
		cout << Getmoney(n) << endl;
	}
	return 0;
}

