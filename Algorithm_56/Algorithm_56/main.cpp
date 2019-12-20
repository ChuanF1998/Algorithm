/*
��Ŀ����
����һ������Ϊn�����ӣ�������Ӽ�����������m�Σ�m��n����������n>1����m>1����
ÿ�����ӵĳ��ȼ�Ϊk[0],k[1],...,k[m]������k[0]xk[1]x...xk[m]���ܵ����˻�
�Ƕ��٣����磬�����ӵĳ�����8ʱ�����ǰ������ɳ��ȷֱ�Ϊ2��3��3�����Σ���ʱ
�õ������˻���18��
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

//��̬�滮�����ӳ���Ϊ1ʱ���˻�Ϊ0������Ϊ2���˻�Ϊ1������Ϊ3���˻�Ϊ2
//���ǵ����ӳ���Ϊ4��ʱ�򣬳˻�Ϊ4 = 2*2�����ӳ���Ϊ5��ʱ�򣬳˻�Ϊ6 = 2*3��
//����Ϊ6ʱ���˻�Ϊ9 = 3*3����ʱ�������ӳ��ȴ���3ʱ��f(n) = f(n-i) * f(i)�����ֵ
#include <vector>
using namespace std;

class Solution {
public:
	int cutRope(int number) {
		if (number == 1) {
			return 0;
		}
		if (number == 2) {
			return 1;
		}
		if (number == 3) {
			return 2;
		}
		vector<int> arr(number + 1);
		arr[0] = 0;
		arr[1] = 1;
		arr[2] = 2;
		arr[3] = 3;
		int max = 0;
		for (int i = 4; i <= number; ++i) {
			for (int j = 1; j <= i / 2; ++j) {
				max = arr[j] * arr[i - j];
				if (max > arr[i]) {
					arr[i] = max;
				}
			}
		}
		return arr[number];
	}
};

int main()
{
	return 0;
}