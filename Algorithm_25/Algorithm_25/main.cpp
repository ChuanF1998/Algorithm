/*
题目描述
有这样一道智力题：“某商店规定：三个空汽水瓶可以换一瓶汽水。小张手上有十个空汽水瓶，她最多可以换多少瓶
汽水喝？”答案是5瓶，方法如下：先用9个空瓶子换3瓶汽水，喝掉3瓶满的，喝完以后4个空瓶子，用3个再换一瓶，
喝掉这瓶满的，这时候剩2个空瓶子。然后你让老板先借给你一瓶汽水，喝掉这瓶满的，喝完以后用3个空瓶子换一瓶
满的还给老板。如果小张手上有n个空汽水瓶，最多可以换多少瓶汽水喝？

输入描述:
输入文件最多包含10组测试数据，每个数据占一行，仅包含一个正整数n（1<=n<=100），表示小张手上的空汽
水瓶数。n=0表示输入结束，你的程序不应当处理这一行。

输出描述:
对于每组测试数据，输出一行，表示最多可以喝的汽水瓶数。如果一瓶也喝不到，输出0。

示例1
输入
3
10
81
0

输出
1
5
40
*/

#include <iostream>
#include <vector>
using namespace std;

class soda_water_num
{
public:
	int get_soda_water_num(int empty_b)
	{
		int count = 0;
		int count1 = 0;
		int cy = 1;
		while (empty_b>2)  //为什么是大于2，因为存在留1个空瓶的情况
		{
			int rest_of_empty = empty_b % 3; //剩余空瓶
			count1 += (empty_b - rest_of_empty) / 3; //本次得到的饮料数量
			count += count1;                      //总数加上本次得到的饮料数量
			rest_of_empty += count1;             //剩余空瓶再加上本次饮料喝完后的空瓶
			count1 = 0;                         //本次饮料置0，为下一次循环做准备（一定要置0，不然下次喝的就包括这次喝的，导致结果不正确）
			if (rest_of_empty == 2){       //空瓶数为2时
				rest_of_empty += cy;       //可以向商家借一瓶，喝完后将3个空瓶一起给他用于抵消借的这一瓶
				count += 1;              
				rest_of_empty = 0;
			}
			empty_b = rest_of_empty;     

		}
		return count;
	}
};

int main()
{
	soda_water_num s;
	while (true) {
		vector<int> arr(10);
		for (int i = 0; i<10; ++i) {
			cin >> arr[i];
			if (arr[i] == 0){
				break;
			}
		}
		for (int i = 0; i<10; ++i) {
			if (arr[i] == 0){
				break;
			}
			else {
				cout << s.get_soda_water_num(arr[i]) << endl;
			}
		}
	}
	return 0;
}