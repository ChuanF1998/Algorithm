/*
题目描述
A,B,C三个人是好朋友,每个人手里都有一些糖果,我们不知道他们每个人
手上具体有多少个糖果,但是我们知道以下的信息：
A - B, B - C, A + B, B + C. 这四个数值.每个字母代表每个人所拥有的糖果数.
现在需要通过这四个数值计算出每个人手里有多少个糖果,即A,B,C。这里保证最
多只有一组整数A,B,C满足所有题设条件。

输入描述:
输入为一行，一共4个整数，分别为A - B，B - C，A + B，B + C，用空格隔开。 
范围均在-30到30之间(闭区间)。

输出描述:
输出为一行，如果存在满足的整数A，B，C则按顺序输出A，B，C，用空格隔
开，行末无空格。 如果不存在这样的整数A，B，C，则输出No

示例1
输入
1 -2 3 4

输出
2 1 3
*/



#include <iostream>
using namespace std;

class candies
{
public:
	void get_candies(int x, int y, int z, int m)
	{
		if ((x + z) % 2 != 0 || (m - y) % 2 != 0) {
			cout << "No" << endl;
			return;
		}
		int A = (x + z) / 2;
		int B = z - A;
		int C = m - B;
		if (A >= 0 && B >= 0 && C >= 0) {
			cout << A << " " << B << " " << C << endl;
		}
		else {
			cout << "No" << endl;
		}
		return;
	}
};


int main()
{
	candies c;
	int x, y, z, m;
	cin >> x >> y >> z >> m;
	c.get_candies(x, y, z, m);
	return 0;
}