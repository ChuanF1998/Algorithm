/*
题目描述
有一只兔子，从出生后第3个月起每个月都生一只兔子，小兔子长到第三个月后每个月又生一只兔子，假如兔子都不死，问每个月的兔子总数为多少？

输入描述:
输入int型表示month

输出描述 :
输出兔子总数int型

示例1
输入
9

输出
3
*/

//递归求解

#include <iostream>
using namespace std;

class ribit_num
{
public:
	int get_ribit_num(int n)
	{
		int count = 1;
		if (n<3){
			return 1;
		}
		return get_ribit_num(n - 1) + get_ribit_num(n - 2);
	}
};


int main()
{
	ribit_num r;
	int n;
	while (cin >> n) {
		cout << r.get_ribit_num(n) << endl;
	}
	return 0;
}