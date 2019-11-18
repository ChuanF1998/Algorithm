/*
题目描述
任意一个偶数（大于2）都可以由2个素数组成，组成偶数的2个素数有很多种情况，本题目要求输出组成指定偶数的两个素数差值最小的素数对
输入描述:
输入一个偶数

输出描述:
输出两个素数

示例1
输入
20

输出
7
13
*/



#include <iostream>
#include <cmath>
using namespace std;

class minimun_poor
{
public:
	void Get_prime_pair(int num)
	{
		int one_half = num / 2;
		int other_one_half = num - one_half;
		while (num != one_half) {
			if (is_prime(one_half) && is_prime(other_one_half)) {
				cout << other_one_half << endl;
				cout << one_half << endl;
				return;
			}
			++one_half;
			--other_one_half;
		}
	}

	bool is_prime(int n)
	{
		if (n == 2 || n == 3){
			return true;
		}
		double n_sqrt = sqrt(n*1.0);
		for (int i = 2; i <= n_sqrt; ++i) {
			if (n%i == 0){
				return false;
			}
		}
		return true;
	}
};

int main()
{
	minimun_poor m;
	int num;
	while (cin >> num) {
		if (num>2 && num % 2 == 0){
			m.Get_prime_pair(num);
		}

	}
	return 0;
}