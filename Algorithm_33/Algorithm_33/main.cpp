/*
��Ŀ����
�����ڼ�С��ʹ��΢���յ��ܶ��������ǳ����ġ��ڲ鿴��ȡ�����¼
ʱ���֣�ĳ����������ֵĴ��������˺��������һ�롣���С���ҵ�
�ú����д�������㷨˼·�ʹ���ʵ�֣�Ҫ���㷨�����ܸ�Ч��

����һ������Ľ������gifts�����Ĵ�Сn���뷵���������Ľ�

��û�н���������һ�룬����0��
����������
[1,2,3,2,2],5
���أ�2
*/

//˼·��������Ȼ�����ͳ����ͬ���ֵĴ�С����������1/2�����

#include <algorithm>
#include <vector>
using namespace std;


class Gift {
public:
	int getValue(vector<int> gifts, int n) {
		// write code here
		sort(gifts.begin(), gifts.end());
		int max_num = gifts[0];
		int max_count = 0;
		for (size_t i = 0; i<gifts.size(); ++i)
		{
			if (gifts[i]>max_num) {
				max_num = gifts[i];
				max_count = 0;
			}
			++max_count;
			if (max_count>n / 2) {
				return max_num;
			}
		}
		return 0;
	}
};


int main()
{
	return 0;
}