/*
��Ŀ����
���1~13��������1���ֵĴ���,�����100~1300��������1���ֵĴ�����Ϊ�����ر�����һ��1~13�а���1������
��1��10��11��12��13��˹�����6��,���Ƕ��ں�����������û���ˡ�ACMerϣ�����ǰ����,�����������
�ձ黯,���Ժܿ���������Ǹ�����������1���ֵĴ�������1 �� n ��1���ֵĴ�������
*/


/*˼·���е㸴�ӡ�
�ٱ���21233�����λ���� 1�� ��ô����λ10000--19999����
ʣ��4λÿһλ��ȡ1��ʣ��3λ������ȡ 0--9����ô��10000����֮����� 4 * 10^3

�ڱ���12343�����λ��1�� ��ô����λֻ��10000-12343��
ʣ��4λÿһλ��ȡ1��ʣ��3λ������ȡ 0--9����ô��10000����֮����� 4 * 10^3

�������ʼλ��Ϊ0������

����С��Χ���жϵ�λ
*/
#include <string>
class Solution {
public:
	int NumberOf1Between1AndN_Solution(int n)
	{
		std::string str = std::to_string(n);
		return NumberOf1(str);
	}

	int NumberOf1(std::string str)
	{
		if (str.empty() || str[0] > '9' || str[0] <= '0') {
			return 0;
		}
		int numof1 = 0;
		int bitNum = str.size() - 1;
		std::string substr(str.begin() + 1, str.end());
		if (str[0] >= '2') {
			numof1 += func(bitNum) + (str[0] - '0') * bitNum * func(bitNum - 1);
		}
		else {
			int num = atoi(str.c_str());
			numof1 += num - func(bitNum) + 1 + bitNum * func(bitNum - 1);
		}
		numof1 += NumberOf1(substr);
		return numof1;
	}

	int func(int n)
	{
		int product = 1;
		for (int i = 0; i < n; ++i) {
			product *= 10;
		}
		return product;
	}
};


int main()
{
	return 0;
}