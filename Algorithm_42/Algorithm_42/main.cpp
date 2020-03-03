/*
题目描述
输入n个整数，输出出现次数大于等于数组长度一半的数。
输入描述:
每个测试输入包含 n个空格分割的n个整数，n不超过100，其中有一个整数出现次数大于等于n/2。
输出描述:
输出出现次数大于等于n/2的数。
示例1
输入
3 9 3 2 5 6 7 3 2 3 3 3

输出
3
*/


#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		int theNum = 0;  //保存当前数
		int minus_count = 0;  //次数
		if (numbers.empty()) {
			return theNum;
		}
		theNum = numbers[0]; 
		minus_count = 1;
		for (int i = 1; i < (int)numbers.size(); ++i) {
			//相等则加1
			if (numbers[i] == theNum) { 
				minus_count++;
				if (minus_count >(int)numbers.size() / 2) {
					break;
				}
			}
			else {
				//不等则减一
				minus_count--;
				//当减为0时，保存当前数，
				if (minus_count == 0) {
					theNum = numbers[i];
					minus_count++;
				}
			}
		}
		//最后应该判断是否成立
		//如果例：[1,2,4,5,2,2,2]那么必然成立
		//如果例：[1,2,3,4]这种情况，theNum为4，但是4不成立
		minus_count = 0;
		for (int i = 0; i < (int)numbers.size(); ++i) {
			if (numbers[i] == theNum)
				minus_count++;
		}
		return (minus_count >(int)numbers.size() / 2) ? theNum : 0;
	}
};




int main()
{
	return 0;
}