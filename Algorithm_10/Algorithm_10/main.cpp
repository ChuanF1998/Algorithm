/*
题目描述
功能: 求一个byte数字对应的二进制数字中1的最大连续数，例如3的二进制为00000011，最大连续2个1

输入: 一个byte型的数字

输出: 无

返回: 对应的二进制数字中1的最大连续数
输入描述:
输入一个byte数字

输出描述:
输出转成二进制之后连续1的个数

示例1
输入
3

输出
2
*/


#include <iostream>
using namespace std;

class consecutive_numbers
{
public:
	int Get_max(int num)
	{
		int min_count = 0;
		int max_count = 0;
		int k = 1;
		for (int i = 0; i<8; ++i) {
			if ((k&num) == k){
				min_count++;
			}
			else{
				if (min_count >= max_count) {
					max_count = min_count;
					min_count = 0;
				}
			}
			k <<= 1;
		}
		if (min_count >= max_count){
			max_count = min_count;
		}
		return max_count;
	}
};

int main()
{
	consecutive_numbers c;
	int num;
	while (cin >> num) {
		cout << c.Get_max(num) << endl;
	}
	return 0;
}