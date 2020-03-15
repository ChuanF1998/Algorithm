/*
题目描述
把只包含质因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，
但14不是，因为它包含质因子7。 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。
*/

/*
根据丑数定义，丑数一定由2、3、5中的一个或几个相乘得到
①arr[0] = 1与 2、3、5]得2，3，5.最小的数为 2
那么 arr[1] = 2;                    --->整理   2、3、5
②arr[0]与3、5相乘，   得 2、3、5 （重复的不算）
  arr[1]与2、3、5相乘，得 4、6、10 ，----》整理 3、4、5
  那么最小的是 3，arr[2] = 3;
③arr[0]与5相乘，      得 2、3、5
  arr[1]与3、5相乘，   得 4、6、10
  arr[2]与2、3、5相乘，得 6，9，15  --->整理 4、5、6
  那么最小的是4

能不能缩小相乘次数，当然能，可以发现，第一次三个数相比，2、3、5
第二次实际上是，4、3、5 比较，将2替换4，因为2已经放进数组了，
每一次在三元组寻找一个最小数据，找到后放入数组，最小数据被替换，
如果存在两个最小数据，那么两个都要被替换。

*/

#include <vector>
#include <algorithm>
class Solution {
public:
	int GetUglyNumber_Solution(int index) {
		if (index < 7) {
			return index;
		}
		std::vector<int> arr(index);
		int a2 = 0;
		int a3 = 0;
		int a5 = 0;
		arr[0] = 1;
		for (int i = 1; i < index; ++i) {
			arr[i] = std::min(arr[a2] * 2, std::min(arr[a3] * 3, arr[a5] * 5));
			if (arr[i] == arr[a2] * 2) {
				a2++;
			}
			if (arr[i] == arr[a3] * 3) {
				a3++;
			}
			if (arr[i] == arr[a5] * 5) {
				a5++;
			}
		}
		return arr[index - 1];
	}
};

int main()
{
	return 0;
}