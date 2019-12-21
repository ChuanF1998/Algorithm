/*
��Ŀ����
����һ������Ϊn�����ӣ�������Ӽ�����������m�Σ�m��n����������n>1����m>1����
ÿ�����ӵĳ��ȼ�Ϊk[0],k[1],...,k[m]������k[0]xk[1]x...xk[m]���ܵ����˻�
�Ƕ��٣����磬�����ӵĳ�����8ʱ�����ǰ������ɳ��ȷֱ�Ϊ2��3��3�����Σ���ʱ�õ������˻���18��
��������:
����һ����n����������档��2 <= n <= 60��
�������:
����𰸡�
ʾ��1
����
8
���
18
*/

/*
̰���㷨�������ӳ���Ϊlength�����˻�max��
length = 1��max = 0;
length = 2, max = 1;
length = 3, max = 2;
����length = 4 ʱ��max = 4 = 2*2��
length = 5 ��max = 2*3 = 6��
length = 6�� max = 3*3 = 9��
length = 7�� max = 3*2*2 = 12��
���Կ�������length >=5 ʱ�����˻� = i��2 �� j��3 ���
���ɣ��ȿ�length���м���3�����൱��length = 3*i +k ,
k = 0��max = pow��3��i��
k = 1����ʱ������һ�������2*2 > 3*1,��ʱ3�ĸ�����һ��2�ĸ���Ϊ2��max = pow��3��i-1��*(2*2);
k = 2, max = pow(3,i)*2;
*/

#include <algorithm>

class Solution {
public:
	int cutRope(int number) {
		int max = 1;
		if (number < 2) {
			return 0;
		}
		if (number == 2) {
			return 1;
		}
		if (number == 3) {
			return 2;
		}
		int times_of_3 = number / 3;
		int remain = number % 3;
		if (remain == 1) {
			--times_of_3;
		}
		int times_of_2 = (number - 3 * times_of_3) / 2;
		max = (int)pow(3, times_of_3)*(int)pow(2, times_of_2);
		return max;
	}
};

int main()
{
	return 0;
}