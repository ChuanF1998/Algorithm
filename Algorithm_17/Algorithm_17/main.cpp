/*
��������:
����һ������

�������:
����������������1�ĸ���

ʾ��1
����
5

���
2
*/

#include <iostream>
using namespace std;

class one_num
{
public:
	int get_one_num(int num)
	{
		int i = 1;
		int count = 0;
		while (num!=0) {
			if ((i&num) == i) {
				++count;
				num ^= i;
			}
			i <<= 1;
		}
		return count;
	}
};


int main()
{
	one_num o;
	int num;
	while (cin >> num) {
		cout << o.get_one_num(num) << endl;
	}
	return 0;
}