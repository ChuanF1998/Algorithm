/*
题目描述
我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
*/

//跟递归一个思路
class Solution {
public:
	int rectCover(int number) {
		int sum = 0;
		int prev = 1;
		int next = 2;
		if (number == 1) {
			return 1;
		}
		if (number == 2) {
			return 2;
		}
		for (int i = 3; i <= number; ++i) {
			sum = prev + next;
			prev = next;
			next = sum;
		}
		return sum;
	}
};

int main()
{
	return 0;
}