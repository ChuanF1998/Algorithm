/*
题目描述
给你一根长度为n的绳子，请把绳子剪成整数长的m段（m、n都是整数，n>1并且m>1），
每段绳子的长度记为k[0],k[1],...,k[m]。请问k[0]xk[1]x...xk[m]可能的最大乘积
是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。
输入描述:
输入一个数n，意义见题面。（2 <= n <= 60）
输出描述:
输出答案。
示例1
输入
8
输出
18
*/

/*
贪心算法：设绳子长度为length，最大乘积max。
length = 1，max = 0;
length = 2, max = 1;
length = 3, max = 2;
而当length = 4 时，max = 4 = 2*2；
length = 5 ，max = 2*3 = 6；
length = 6， max = 3*3 = 9；
length = 7， max = 3*2*2 = 12；
可以看出，当length >=5 时，最大乘积 = i个2 和 j个3 相乘
规律：先看length中有几个3，就相当于length = 3*i +k ,
k = 0，max = pow（3，i）
k = 1，此时存在另一种情况，2*2 > 3*1,此时3的个数减一，2的个数为2，max = pow（3，i-1）*(2*2);
k = 2, max = pow(3,i)*2;
*/

#include <algorithm>

class Solution {
public:
	int cutRope(int number) {
		int max = 1;
		if (number < 2) {
			return 0;
		}
		if (number == 2) {
			return 1;
		}
		if (number == 3) {
			return 2;
		}
		int times_of_3 = number / 3;
		int remain = number % 3;
		if (remain == 1) {
			--times_of_3;
		}
		int times_of_2 = (number - 3 * times_of_3) / 2;
		max = (int)pow(3, times_of_3)*(int)pow(2, times_of_2);
		return max;
	}
};

int main()
{
	return 0;
}