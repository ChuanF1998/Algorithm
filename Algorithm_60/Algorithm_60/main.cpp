/*
��Ŀ����
����һ��double���͵ĸ�����base��int���͵�����exponent����base��exponent�η���

��֤base��exponent��ͬʱΪ0
*/

/*
Ҫ����base == 0 �� exponent < 0 ���������Ϊ�����������η�ʱҪ���� 1/x������Ϊ0�����
�ٱ��취��������ʱ�临�Ӷ� O��n��
��a��n�η� = a �� n/2 �η� * a �� n/2 �η���nΪż����
  a��n�η� = a �� n/2 �η� * a �� n/2 �η� * base (nΪ������
  ʱ�临�Ӷ� O��logn��
*/

#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	double Power(double base, int exponent) {
		double power = 1.0;
		int exponent_copy = exponent;
		if (exponent <= 0) {
			exponent_copy = -exponent_copy;
		}
		if (fabs(base) <= 1.0e-9 && exponent < 0) {
			return 0.0;
		}
		power = result(base, exponent_copy);
		if (exponent > 0) {
			return power;
		}
		else {
			return 1 / power;
		}
	}

	double result(double base, int exponent)
	{
		if (exponent == 0) {
			return 1;
		}
		if (exponent == 1) {
			return base;
		}
		double n = result(base, exponent >> 1);
		n *= n;
		if ((exponent & 1) == 1) {
			n *= base;
		}
		return n;
	}
};

int main()
{
	return 0;
}