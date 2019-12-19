/*
题目描述
一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
*/

//如果n=1，那么跳一次；如果n=2，2个单步或1个双步，两种跳法
//如果n>2,那么有f(n）= f(n-1) + f(n-2);相当于Fibonacci数列
//退出条件0时，return 0；n==1,return 1; n==2.return 2;
class Solution {
public:
	int jumpFloor(int number) {
		int count = 0;
		if (number <= 0) {
			return 0;
		}
		else if (number == 1) {
			return 1;
		}
		else if (number == 2) {
			return 2;
		}
		else {
			count += jumpFloor(number - 1);
			count += jumpFloor(number - 2);
		}
		return count;
	}
};

int main()
{
	return 0;
}