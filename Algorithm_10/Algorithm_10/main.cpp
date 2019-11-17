/*
��Ŀ����
����: ��һ��byte���ֶ�Ӧ�Ķ�����������1�����������������3�Ķ�����Ϊ00000011���������2��1

����: һ��byte�͵�����

���: ��

����: ��Ӧ�Ķ�����������1�����������
��������:
����һ��byte����

�������:
���ת�ɶ�����֮������1�ĸ���

ʾ��1
����
3

���
2
*/


#include <iostream>
using namespace std;

class consecutive_numbers
{
public:
	int Get_max(int num)
	{
		int min_count = 0;
		int max_count = 0;
		int k = 1;
		for (int i = 0; i<8; ++i) {
			if ((k&num) == k){
				min_count++;
			}
			else{
				if (min_count >= max_count) {
					max_count = min_count;
					min_count = 0;
				}
			}
			k <<= 1;
		}
		if (min_count >= max_count){
			max_count = min_count;
		}
		return max_count;
	}
};

int main()
{
	consecutive_numbers c;
	int num;
	while (cin >> num) {
		cout << c.Get_max(num) << endl;
	}
	return 0;
}