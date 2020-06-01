/*
��Ŀ:�����������
��Ŀ����
ţţ�ո�ѧϰ�������Ķ��壬���ڸ���һ��������N��ţţϣ��֪��N���ٱ�ʾ�ɶ��ٸ������ĺ͡�
������ָ�ڴ���1����Ȼ���У�����1�����������ⲻ����������������Ȼ����

��ʾ
��°ͺղ��룺�������2��ż�������Բ�ֳ���������֮�͡��ò�����δ�ϸ�֤��������ʱû���ҵ�������

ʾ��1
����
����
3
���
����
1
˵��
3�������1������
ʾ��2
����
����
6
���
����
2
˵��
6���Ա�ʾΪ3 + 3��ע��ͬ������������ʹ�ö��
��ע:
2 \leq N \leq 10^92��N��10
9
*/

#include <cmath>

class Solution {
public:
	/**
	* �жϸ����������������ܱ�ʾ�ɶ��ٸ������ĺ�
	* @param N int���� ������������
	* @return int����
	*/
	int MinPrimeSum(int N) {
		// write code here

		if (isprime(N)) {
			return 1;
		}
		if (N % 2 == 0) {
			return 2;
		}
		else {
			if (isprime(N - 2)) {
				return 2;
			}
			else {
				return 3;
			}
		}
	}

	bool isprime(int n)
	{
		if (n < 4) {
			return n > 1;
		}
		if (n % 6 != 5 && n % 6 != 1) {
			return false;
		}
		int sq = sqrt(n);
		for (int i = 5; i <= sq; i += 6) {
			if (n % i == 0 || n % (i + 2) == 0) {
				return false;
			}
		}
		return true;
	}
};

int main()
{
	return 0;
}