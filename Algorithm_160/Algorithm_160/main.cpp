/*
链接：https://www.nowcoder.com/questionTerminal/1d18c0841e64454cbc3afaea05e2f63c?toCommentId=32793
来源：牛客网

居然有假币！ 现在猪肉涨了，但是农民的工资却不见涨啊，没钱怎么买猪肉啊。
nowcoder这就去买猪肉，结果找来的零钱中有假币！！！可惜nowcoder 一不小
心把它混进了一堆真币里面去了。只知道假币的重量比真币的质量要轻，给你一个天
平（天平两端能容纳无限个硬币），请用最快的时间把那个可恶的假币找出来。

输入描述:
1≤n≤2^30,输入0结束程序。


输出描述:
最多要称几次一定能把那个假币找出来？
示例1
输入
3<br/>12<br/>0
输出
1<br/>3
*/

/*
n是3的倍数，直接分三份
n是三的倍数还多一，分成n/3, n/3, n/3 + 1;最后剩 n/3 + 1
n是三的倍数多2， 分成 n/3, n/3 + 1, n/3 + 1; 最后剩 n/3 + 1
*/
// write your code here cpp
// write your code here cpp
#include <iostream>
using namespace std;

class solution
{
public:
	int Get(unsigned int n)
	{
		int times = 0;
		if (n == 1) {
			return times;
		}
		while (n > 1) {
			if (n % 3 == 0) {
				n /= 3;
			}
			else {
				n = n / 3 + 1;
			}
			times += 1;
		}
		return times;
	}
};

int main()
{
	solution ss;
	unsigned int n;
	while (cin >> n && n != 0) {
		cout << ss.Get(n) << endl;
	}
}