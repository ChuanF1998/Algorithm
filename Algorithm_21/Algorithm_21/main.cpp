/*
��Ŀ����
1

1  1  1

1  2  3  2  1

1  3  6  7  6  3  1

1  4  10 16 19  16 10  4  1

���������ε����󣬵�һ��ֻ��һ����1������ÿ�е�ÿ��������ǡ������������������Ͻ��������Ͻǵ�����3����֮�ͣ����������ĳ��������Ϊ��������0����

���n�е�һ��ż�����ֵ�λ�á����û��ż���������-1����������3,�����2������4�����3��



����n(n <= 1000000000)
��������:
����һ��int����

�������:
������ص�intֵ

ʾ��1
����
4

���
3
*/

//��n��i������С = ��n-1�е�i��+��n-1�е�i-1��+��n-1�е�i-2��
//�ݹ��˳�������i=1ʱ��return 1 ��i<1ʱ��return 0 ��n==1&&i>1ʱ return1 

#include <iostream>
using namespace std;

class even_number_location
{
public:
	long long get_location(long long n)
	{
		//int k=0;
		for (int i = 1; i <= n; ++i) {
			if (func(n, i) % 2 == 0){
				return i;
			}
		}
		return -1;
	}
	long long func(long long n, long long i)
	{
		//int count=0;
		if (i == 1){
			return 1;
		}
		if (i<1){
			return 0;
		}
		if (n == 1 && i>1) {
			return 0;
		}
		return func(n - 1, i) + func(n - 1, i - 1) + func(n - 1, i - 2);
	}
};


int main()
{
	even_number_location e;
	long long n;
	while (cin >> n) {
		cout << e.get_location(n) << endl;
	}
	return 0;
}