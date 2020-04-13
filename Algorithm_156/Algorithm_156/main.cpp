/*
链接：https://www.nowcoder.com/questionTerminal/34f17d5f2a8240bea661a23ec095a062?source=relative
来源：牛客网

星际战争开展了100年之后，NowCoder终于破译了外星人的密码！他们的密码是一串整数，
通过一张表里的信息映射成最终4位密码。表的规则是：n对应的值是矩阵X的n次方的左上角，
如果这个数不足4位则用0填充，如果大于4位的则只输出最后4位。
|1 1|^n => |Xn ..|
|1 0|      |.. ..|
例如n=2时，
|1 1|^2 => |1 1| * |1 1| => |2 1|
|1 0|      |1 0|   |1 0|    |1 1|
即2对应的数是“0002”。

输入描述:
输入有多组数据。
每组数据两行：第一行包含一个整数n (1≤n≤100)；第二行包含n个正整数Xi (1≤Xi≤10000)


输出描述:
对应每一组输入，输出一行相应的密码。
示例1
输入
6<br/>18 15 21 13 25 27<br/>5<br/>1 10 100 1000 10000
输出
418109877711037713937811<br/>00010089410135017501
*/

// write your code here cpp
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

vector<int> arr(10001);

class solution
{
public:
	void func()
	{
		arr[0] = 1;
		arr[1] = 1;
		arr[2] = 2;
		for (int i = 3; i <= 10000; ++i) {
			arr[i] = arr[i - 1] + arr[i - 2];
			if (arr[i] >= 10000) {
				arr[i] %= 10000;
			}
		}
		return;
	}
};

int main()
{
	solution ss;
	ss.func();
	int n;
	int scan;
	while (cin >> n) {
		for (int i = 0; i < n; ++i) {
			cin >> scan;
			cout << setfill('0') << setw(4) << arr[scan];
		}
		cout << endl;
	}
	return 0;
}