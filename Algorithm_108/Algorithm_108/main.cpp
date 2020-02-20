/*
题目描述
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。
求该青蛙跳上一个n级的台阶总共有多少种跳法。
*/

#include <iostream>
class Solution {
public:
	//递归
	int jumpFloorII(int number) {
		if (number == 1) {
			return 1;
		}
		if (number == 2) {
			return 2;
		}
		int sum = 0;
		for (int i = number - 1; i > 0; --i) {
			sum += jumpFloorII(i);
		}
		return sum + 1;
	}

	//循环
	int jumpFloorIII(int number)
	{
		int prev_sum = 1;
		int next_sum = 2;
		int sum = 1;
		if (number == 1) {
			return prev_sum;
		}
		if (number == 2) {
			return next_sum;
		}
		for (int i = 3; i <= number; ++i) {
			sum = next_sum + prev_sum + 1;
			prev_sum = prev_sum + next_sum;
			next_sum = sum;
		}
		return sum;
	}
};


int main()
{
	Solution s;
	for (int i = 1; i < 5; i++) {
		std::cout << s.jumpFloorIII(i) << std::endl;
	}
	return 0;
}