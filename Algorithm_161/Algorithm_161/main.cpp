/*
���ӣ�https://www.nowcoder.com/questionTerminal/e8fb8f89f5d147ec92fd8ecfefe89b0d
��Դ��ţ����

һ�����������Էֽ��һ����������Ļ�������36=2*2*3*3��
������2��3�������ӡ�NowCoder������о����Ӹ����ķֲ����ɣ����ڸ�
��һϵ������������ϣ���㿪��һ���������ÿ�������������Ӹ�����

��������:
��������������ݡ�
ÿ�����ݽ���һ������n (2��n��100000)��


�������:
��Ӧÿ����������������Ӹ�����ÿ�����ռһ�С�
ʾ��1
����
30<br/>26<br/>20
���
3<br/>2<br/>2
*/

// write your code here cpp
#include <cmath>
#include <iostream>
using namespace std;

class solution
{
public:
	int Get(int num)
	{
		if (num > 100000 || num < 2) {
			return -1;
		}
		if (IsPrime(num)) {
			return 1;
		}
		int n = 0;
		int flag = 0;
		int sq = (int)sqrt(num);
		while (num > 1) {
			for (int i = 2; i <= sq; ++i) {
				if (num % i == 0) {
					num /= i;
					if (i > flag) {
						n += 1;
						flag = i;
					}
					break;
				}
			}
			if (IsPrime(num)) {
				if (num > flag) {
					n += 1;
				}
				break;
			}
		}
		return n;
	}

	bool IsPrime(int num)
	{
		if (num < 4) {
			return num > 1;
		}
		if (num % 6 != 1 && num % 6 != 5) {
			return false;
		}
		double sq = sqrt(num);
		for (int i = 5; i <= (int)sq; i += 6) {
			if (num % i == 0 || num % (i + 2) == 0) {
				return false;
			}
		}
		return true;
	}
};


int main()
{
	solution ss;
	int num;
	while (cin >> num) {
		cout << ss.Get(num) << endl;
	}
	return 0;
}