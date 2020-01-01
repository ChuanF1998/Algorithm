/*
��Ŀ����
СQ�õ�һ�����������: 1, 12, 123,...12345678910,1234567891011...��

����СQ�����ܷ�3����������ʺܸ���Ȥ��

СQ����ϣ�����ܰ�������һ�´����еĵ�l������r��(�����˵�)�ж��ٸ������Ա�3������

��������:
���������������l��r(1 <= l <= r <= 1e9), ��ʾҪ�����������ˡ�
�������:
���һ������, ��ʾ�������ܱ�3���������ָ�����
ʾ��1
����
����
2 5
���
����
3
˵��
12, 123, 1234, 12345...
����12, 123, 12345�ܱ�3������
*/

#include <iostream>

class Solution
{
public:
	int multiple_of_three(int l, int k)
	{
		if (l >= k || l < 1) {
			return 0;
		}
		int start = l % 3;
		int interval = k - l + 1;
		int remain = interval % 3;
		int count = (interval / 3) << 1;
		if (start == 2 && remain == 1) {
			count += 1;
		}
		if (start == 2 && remain == 2) {
			count += 2;
		}
		if (start == 1 && remain == 2) {
			count += 1;
		}
		return count;
	}
};



int main()
{
	Solution s;
	int l;
	int k;
	while (std::cin >> l >> k) {
		std::cout << s.multiple_of_three(l, k) << std::endl;
	}
	return 0;
}