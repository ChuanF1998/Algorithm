/*
题目描述
1

1  1  1

1  2  3  2  1

1  3  6  7  6  3  1

1  4  10 16 19  16 10  4  1

以上三角形的数阵，第一行只有一个数1，以下每行的每个数，是恰好是它上面的数，左上角数到右上角的数，3个数之和（如果不存在某个数，认为该数就是0）。

求第n行第一个偶数出现的位置。如果没有偶数，则输出-1。例如输入3,则输出2，输入4则输出3。



输入n(n <= 1000000000)
输入描述:
输入一个int整数

输出描述:
输出返回的int值

示例1
输入
4

输出
3
*/

//第n行i个数大小 = 第n-1行的i个+第n-1行的i-1个+第n-1行的i-2个
//递归退出条件：i=1时，return 1 ；i<1时，return 0 ；n==1&&i>1时 return1 

#include <iostream>
using namespace std;

class even_number_location
{
public:
	long long get_location(long long n)
	{
		//int k=0;
		for (int i = 1; i <= n; ++i) {
			if (func(n, i) % 2 == 0){
				return i;
			}
		}
		return -1;
	}
	long long func(long long n, long long i)
	{
		//int count=0;
		if (i == 1){
			return 1;
		}
		if (i<1){
			return 0;
		}
		if (n == 1 && i>1) {
			return 0;
		}
		return func(n - 1, i) + func(n - 1, i - 1) + func(n - 1, i - 2);
	}
};


int main()
{
	even_number_location e;
	long long n;
	while (cin >> n) {
		cout << e.get_location(n) << endl;
	}
	return 0;
}