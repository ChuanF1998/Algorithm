/*
��Ŀ����
��һֻ���ӣ��ӳ������3������ÿ���¶���һֻ���ӣ�С���ӳ����������º�ÿ��������һֻ���ӣ��������Ӷ���������ÿ���µ���������Ϊ���٣�

��������:
����int�ͱ�ʾmonth

������� :
�����������int��

ʾ��1
����
9

���
3
*/

//�ݹ����

#include <iostream>
using namespace std;

class ribit_num
{
public:
	int get_ribit_num(int n)
	{
		int count = 1;
		if (n<3){
			return 1;
		}
		return get_ribit_num(n - 1) + get_ribit_num(n - 2);
	}
};


int main()
{
	ribit_num r;
	int n;
	while (cin >> n) {
		cout << r.get_ribit_num(n) << endl;
	}
	return 0;
}