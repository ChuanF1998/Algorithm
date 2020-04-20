/*
���ӣ�https://www.nowcoder.com/questionTerminal/0f6976af36324f8bab1ea61e9e826ef5?toCommentId=26412
��Դ��ţ����

��ν���ӷֽ⣬���ǰѸ�����������a���ֽ�����ɸ������ĳ˻����� a = a1 �� a2 �� a3 �� ... �� an
,���� 1 < a1 �� a2 �� a3 �� ... �� an������a1��a2��...��an��Ϊ������ �ȸ���һ������a��������ֽ������ӡ�

��������:
��������������ݣ�ÿ�����ݰ���һ��������a��2��a��1000000����


�������:
��Ӧÿ�����ݣ��ԡ�a = a1 * a2 * a3...������ʽ�����ʽ�ֽ��Ľ����
ʾ��1
����
10<br/>18
���
10 = 2 * 5<br/>18 = 2 * 3 * 3
*/

// write your code here cpp

#include <iostream>
#include <cmath>
using namespace std;

class solution
{
public:
	void Get(int a)
	{
		if (a < 2 || a > 1000000) {
			return;
		}
		cout << a << " =";
		if (Isprime(a)) {
			cout << " " << a << endl;
			return;
		}
		int sq = (int)sqrt(a);
		while (a > 1) {
			for (int i = 2; i <= sq; ++i) {
				if (a % i == 0) {
					a /= i;
					cout << " " << i << " *";
					break;
				}
			}
			if (Isprime(a)) {
				cout << " " << a;
				break;
			}
		}
		cout << endl;
	}

	bool Isprime(int num)
	{
		if (num < 4) {
			return num > 1;
		}
		if (num % 6 != 1 && num % 6 != 5) {
			return false;
		}
		int sq = (int)sqrt(num);
		for (int i = 5; i <= sq; i += 6) {
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
	int a;
	while (cin >> a) {
		ss.Get(a);
	}
	return 0;
}


#if 0
#include <iostream>
using namespace std;
int main()
{
	int a = 0, i = 0;
	while (cin >> a)
	{
		cout << a << " = ";
		i = 2;
		while (1)   //�ҵ���һ������������������Ϊ�˸�ʽ�Ĳ���
		{
			if (a % i == 0)
			{
				cout << i;
				a = a / i;
				break;
			}
			i++;
		}
		while (a != 1)   //�ҵ�ʣ���������������
		{
			i = 2;
			while (1)
			{
				if (a % i == 0)
				{
					cout << " * " << i;
					a = a / i;            //aһֱ�ڲ��ϵؼ�С
					break;
				}
				i++;
			}
		}
		cout << endl;
	}
	return 0;
}

#endif