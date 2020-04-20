/*
链接：https://www.nowcoder.com/questionTerminal/0f6976af36324f8bab1ea61e9e826ef5?toCommentId=26412
来源：牛客网

所谓因子分解，就是把给定的正整数a，分解成若干个素数的乘积，即 a = a1 × a2 × a3 × ... × an
,并且 1 < a1 ≤ a2 ≤ a3 ≤ ... ≤ an。其中a1、a2、...、an均为素数。 先给出一个整数a，请输出分解后的因子。

输入描述:
输入包含多组数据，每组数据包含一个正整数a（2≤a≤1000000）。


输出描述:
对应每组数据，以“a = a1 * a2 * a3...”的形式输出因式分解后的结果。
示例1
输入
10<br/>18
输出
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
		while (1)   //找到第一个可以整除的素数，为了格式的操作
		{
			if (a % i == 0)
			{
				cout << i;
				a = a / i;
				break;
			}
			i++;
		}
		while (a != 1)   //找到剩余可以整除的素数
		{
			i = 2;
			while (1)
			{
				if (a % i == 0)
				{
					cout << " * " << i;
					a = a / i;            //a一直在不断地减小
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