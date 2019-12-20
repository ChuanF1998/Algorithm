/*
题目描述
给你一根长度为n的绳子，请把绳子剪成整数长的m段（m、n都是整数，n>1并且m>1），
每段绳子的长度记为k[0],k[1],...,k[m]。请问k[0]xk[1]x...xk[m]可能的最大乘积
是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时
得到的最大乘积是18。
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

//动态规划：绳子长度为1时，乘积为0；长度为2，乘积为1；长度为3，乘积为2
//但是当绳子长度为4的时候，乘积为4 = 2*2；绳子长度为5的时候，乘积为6 = 2*3；
//长度为6时，乘积为9 = 3*3，此时发现绳子长度大于3时，f(n) = f(n-i) * f(i)的最大值
#include <vector>
using namespace std;

class Solution {
public:
	int cutRope(int number) {
		if (number == 1) {
			return 0;
		}
		if (number == 2) {
			return 1;
		}
		if (number == 3) {
			return 2;
		}
		vector<int> arr(number + 1);
		arr[0] = 0;
		arr[1] = 1;
		arr[2] = 2;
		arr[3] = 3;
		int max = 0;
		for (int i = 4; i <= number; ++i) {
			for (int j = 1; j <= i / 2; ++j) {
				max = arr[j] * arr[i - j];
				if (max > arr[i]) {
					arr[i] = max;
				}
			}
		}
		return arr[number];
	}
};

int main()
{
	return 0;
}