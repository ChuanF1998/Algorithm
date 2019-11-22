/*
题目描述
一个袋子里面有n个球，每个球上面都有一个号码(拥有相同号码的球是无区别的)。如果一个袋子是幸运的当且仅当所有球的号码的和大于所有球的号码的积。
例如：如果袋子里面的球的号码是{1, 1, 2, 3}，这个袋子就是幸运的，因为1 + 1 + 2 + 3 > 1 * 1 * 2 * 3
你可以适当从袋子里移除一些球(可以移除0个,但是别移除完)，要使移除后的袋子是幸运的。现在让你编程计算一下你可以获得的多少种不同的幸运的袋子。
输入描述:
第一行输入一个正整数n(n ≤ 1000)
第二行为n个数正整数xi(xi ≤ 1000)
输出描述:
输出可以产生的幸运的袋子数
示例1
输入
3
1 1 1

输出
2
*/

/*每次从全集中选择若干元素（小球）组成子集（袋子）。对于任意两个正整数a,b如果满足a+b>ab，则必有一个数为
1.可用数论证明：设a=1+x,b=1+y，则1+x+1+y>(1+x)(1+y)，---> 1>xy，则x，y必有一个为0，即a,b有一个为1.推广
到任意k个正整数，假设a1,a2,...ak，如果不满足给定条件，即和sum小于等于积pi。如果此时再选择一个数b,能使其
满足sum+b > pib，则，b必然为1，且为必要非充分条件。反之，如果选择的b>1，则sum+b <= pi*b，即
a1,a2,...,ak,b不满足给定条件。
因此，将球按标号升序排序。每次从小到大选择，当选择到a1,a2,...,ak-1时满足给定条件，而再增加选择ak时不满足
条件（ak必然大于等于max(a1,a2,...,ak-1)），继续向后选择更大的数，必然无法满足！此时不必再继续向后搜索。
如果有多个1，即当k=1时，sum(1)>pi(1)不满足，但下一个元素仍为1，则可以满足1+1>1*1， 所以要判断当前ak是否
等于1，如果等于1，虽然不能满足，组合的个数不能增加，但是继续向后搜索，仍然有满足条件的可能.对于重复数
字，组合只能算一个，要去重。*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class pocket_num
{
public:
	int get_pocket_num(vector<int>& arr, int n, int pos, int sum, int mul)
	{
		int count = 0;
		for (int i = pos; i<n; ++i){
			sum += arr[i];
			mul *= arr[i];
			if (sum > mul) {
				count += 1 + get_pocket_num(arr, n, i + 1, sum, mul);
			}
			else if (arr[i] == 1) {
				count += get_pocket_num(arr, n, i + 1, sum, mul);
			}
			else {
				break;
			}
			sum -= arr[i];
			mul /= arr[i];
			while (i<n - 1 && arr[i] == arr[i + 1]){
				++i;
			}
		}
		return count;
	}
};


int main()
{
	int n;
	int num;
	pocket_num p;
	while (cin >> n) {
		vector<int> arr(n);
		for (int i = 0; i<n; ++i) {
			cin >> num;
			arr[i] = num;
		}
		sort(arr.begin(), arr.end());
		cout << p.get_pocket_num(arr, n, 0, 0, 1) << endl;
	}
	return 0;
}