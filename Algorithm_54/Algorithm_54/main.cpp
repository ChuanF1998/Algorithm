/*
��Ŀ����
һֻ����һ�ο�������1��̨�ף�Ҳ��������2���������������һ��n����̨���ܹ��ж������������Ⱥ����ͬ�㲻ͬ�Ľ������
*/

//���n=1����ô��һ�Σ����n=2��2��������1��˫������������
//���n>2,��ô��f(n��= f(n-1) + f(n-2);�൱��Fibonacci����
//�˳�����0ʱ��return 0��n==1,return 1; n==2.return 2;
class Solution {
public:
	int jumpFloor(int number) {
		int count = 0;
		if (number <= 0) {
			return 0;
		}
		else if (number == 1) {
			return 1;
		}
		else if (number == 2) {
			return 2;
		}
		else {
			count += jumpFloor(number - 1);
			count += jumpFloor(number - 2);
		}
		return count;
	}
};

int main()
{
	return 0;
}