/*
��Ŀ����
����һ��ż��������2����������2��������ɣ����ż����2�������кܶ������������ĿҪ��������ָ��ż��������������ֵ��С��������
��������:
����һ��ż��

�������:
�����������

ʾ��1
����
20

���
7
13
*/



#include <iostream>
#include <cmath>
using namespace std;

class minimun_poor
{
public:
	void Get_prime_pair(int num)
	{
		int one_half = num / 2;
		int other_one_half = num - one_half;
		while (num != one_half) {
			if (is_prime(one_half) && is_prime(other_one_half)) {
				cout << other_one_half << endl;
				cout << one_half << endl;
				return;
			}
			++one_half;
			--other_one_half;
		}
	}

	bool is_prime(int n)
	{
		if (n == 2 || n == 3){
			return true;
		}
		double n_sqrt = sqrt(n*1.0);
		for (int i = 2; i <= n_sqrt; ++i) {
			if (n%i == 0){
				return false;
			}
		}
		return true;
	}
};

int main()
{
	minimun_poor m;
	int num;
	while (cin >> num) {
		if (num>2 && num % 2 == 0){
			m.Get_prime_pair(num);
		}

	}
	return 0;
}