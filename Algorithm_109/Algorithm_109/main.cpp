/*
��Ŀ����
���ǿ�����2*1��С���κ��Ż�������ȥ���Ǹ���ľ��Ρ�
������n��2*1��С�������ص��ظ���һ��2*n�Ĵ���Σ��ܹ��ж����ַ�����
*/

//���ݹ�һ��˼·
class Solution {
public:
	int rectCover(int number) {
		int sum = 0;
		int prev = 1;
		int next = 2;
		if (number == 1) {
			return 1;
		}
		if (number == 2) {
			return 2;
		}
		for (int i = 3; i <= number; ++i) {
			sum = prev + next;
			prev = next;
			next = sum;
		}
		return sum;
	}
};

int main()
{
	return 0;
}