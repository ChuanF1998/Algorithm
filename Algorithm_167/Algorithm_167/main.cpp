/*
���ӣ�https://www.nowcoder.com/questionTerminal/610e6c0387a0401fb96675f58cda8559?toCommentId=25418
��Դ��ţ����
��Ŀ�����齱
���깫˾���Ľ�Ʒ�ر���������񽱵Ĺ��ȴ�����⣺
1. ���ȣ�������Ա����һ��д���Լ����ֵ���������齱���У�
2. ����������������ϣ�ÿ�˴�����ȡһ��������
3. ����鵽��������д�ľ����Լ������֣���ô����ϲ�㣬�н��ˣ���
���ڸ�����μ�������������������ж��ٸ��ʻ�������˻񽱣�

��������:
��������������ݣ�ÿ�����ݰ���һ��������n��2��n��20����


�������:
��Ӧÿһ�����ݣ��ԡ�xx.xx%���ĸ�ʽ����������˻񽱵ĸ��ʡ�
ʾ��1
����
2
���
50.00%
*/


// write your code here cpp
// write your code here cpp
#include <iostream>
using namespace std;

long wrong[21];
long all[21];

class solution
{
public:
	void Get()
	{
		wrong[0] = 0;
		wrong[1] = 0;
		wrong[2] = 1;
		all[0] = 0;
		all[1] = 1;
		all[2] = 2;
		for (int i = 3; i <= 20; ++i) {
			wrong[i] = (i - 1) * (wrong[i - 1] + wrong[i - 2]);
			all[i] = i * all[i - 1];
		}
		return;
	}
};

int main()
{
	solution ss;
	ss.Get();
	int n;
	while (cin >> n) {
		double result = wrong[n] / (all[n] * 1.0);
		result *= 100;
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << result << "%" << endl;
	}
	return 0;
}