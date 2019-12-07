/*
链接：https://www.nowcoder.com/questionTerminal/2d3f6ddd82da445d804c95db22dcc471?orderByHotValue=1&page=1&onlyReference=false
来源：牛客网

[编程题]排序子序列

牛牛定义排序子序列为一个数组中一段连续的子序列,并且这段子序列是非递增或者
非递减排序的。牛牛有一个长度为n的整数数组A,他现在有一个任务是把数组A分为
若干段排序子序列,牛牛想知道他最少可以把这个数组分为几段排序子序列.
如样例所示,牛牛可以把数组A划分为[1,2,3]和[2,2,1]两个排序子序列,至少需要
划分为2个排序子序列,所以输出2

输入描述:
输入的第一行为一个正整数n(1 ≤ n ≤ 10^5)

第二行包括n个整数A_i(1 ≤ A_i ≤ 10^9),表示数组A的每个数字。


输出描述:
输出一个整数表示牛牛可以将A最少划分为多少段排序子序列

示例1
输入
6
1 2 3 2 2 1
输出
2

*/

/*
思路：先将prev=arr[0]，子序列数量初始count=1
①如果后一个数大于prev，则进入循环，当遇到后一个数小于前一个数时，则退出循环
prev置为当前退出时那一个比较小的数
②如果后一个数小于prev，则进入循环，当遇到后一个数大于后一个数时，则退出循环
prev置为当前退出时那一个比较大的数
③如果相等，当前不做处理，位置向后移动比较下一个
*/


#include <iostream>
#include <vector>
using namespace std;

class subsequence
{
public:
	int get_subquence_count(vector<int>& arr)
	{
		size_t arr_size = arr.size();
		size_t i = 1;
		int count = 1;  //初始数量为1
		int prev = arr[0]; //保存第一个数
		int next;
		while (i < arr_size) {
			next = arr[i]; 
			if (next > prev) {  //大于时进入循环
				for (; i < arr_size; ++i) {  
					if (arr[i] < arr[i - 1]) { //遇到小于时退出，保存prev
						prev = arr[i];
						++count;        //数量加1
						break;
					}
				}
			}
			else if (next < prev) {     //小于时进入循环
				for (; i < arr_size; ++i) {
					if (arr[i] > arr[i - 1]) {  //遇到大于时退出，保存prev
						prev = arr[i];
						++count;      //数量加1
						break;
					}
				}
			}
			else {
				++i; //相等时不做处理，++后比较下一个数
			}
		}
		return count;
	}
};


int main()
{
	subsequence s;
	int n;
	while (cin >> n) {
		vector<int> arr(n);
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}
		cout << s.get_subquence_count(arr) << endl;
	}
	return 0;
}