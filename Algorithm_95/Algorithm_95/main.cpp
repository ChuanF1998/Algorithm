/*
题目描述
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后
半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
*/

#include <vector>
#include <iostream>

#if 0
class Solution {
public:
	void reOrderArray(std::vector<int> &array) {
		std::vector<int> arr;
		for (int i = 0; i < (int)array.size(); ++i) {
			if (array[i] % 2 == 1) {
				arr.push_back(array[i]);
			}
		}
		for (int i = 0; i < (int)array.size(); ++i) {
			if (array[i] % 2 == 0) {
				arr.push_back(array[i]);
			}
		}
		array = arr;
	}
};
#endif

//不开辟新空间，时间复杂度O（n），空间复杂度O(1)
class Solution {
public:
	void reOrderArray(std::vector<int> &array) {
		int odd_count = 0;
		//计算奇数的个数以便于找出第一个偶数的下标
		for (int i = 0; i < (int)array.size(); ++i) {
			if (array[i] % 2 == 1) {
				odd_count++;
			}
		}
		int odd_pos = 0; //奇数的下标
		int pos = 0;      //数组下标
		int even_pos = odd_count; //偶数的下标
		int temp;
		/*
		基本思路：先默认将数组分为奇偶两部分，从数组起始位置开始遍历，只要遇见偶数就跳过，
		遇见奇数则做进一步判断：奇数下标所代表的数为奇数时，则说明该数在正确的位置上；
		                        奇数下标所代表的数为偶数时，则交换，交换规则如下：
								临时变量保存当前奇数下标所代表的值，当前奇数下标所代表的值换成当前数组下标的
								的值（也就是现在遍历到的奇数），当前数组下标的数换成当前偶数下标所代表的数，
								然后当前偶数下标的数保存临时变量，也就是遇到的第一个偶数，这样可以保证奇偶的有序性
								完成后偶数下标加1，当前数组下标的数为偶数时，数组下标才加1
		例[1,2,3,4,5,6,7],4个奇数，3个偶数，那么调整后的第一个偶数下标就为4，设奇数下标odd为0，偶数even下标为4
		                 pos从0开始遍历，pos = 0，arr[pos] = 1,arr[odd] = 1,在正确位置，odd加1，pos加1 
						                 pos = 1，arr[pos] = 2,偶数，pos加1
										 pos = 2，arr[pos] = 3,arr[odd] = arr[1] = 2,则交换，交换后的数组 [1,3,5,4,2,6,7],
								因为此时arr[2] = 5,pos不变，odd = 2,even = 5;
										 pos = 2, arr[pos] = 5，arr[odd] = 5,正确, pos加1，odd加1 = 3
										 pos = 3，arr[pos] = 4, arr[odd] = 4，pos加1；
										 pos = 4，pos加1
									  	 。。。
										 直到pos = 6，arr[pos] = 7, arr[odd] = 4，arr[even] = 6,交换后的数组[1,3,5,7,2,4,6]
		*/
		while (pos < (int)array.size()) {
			if (array[pos] % 2 == 1) {   //当前下标的数为奇数时
				if (array[odd_pos] % 2 == 0) { //若此时奇数的下标为偶数时，则交换
					temp = array[odd_pos];
					array[odd_pos] = array[pos];
					array[pos] = array[even_pos];
					array[even_pos] = temp;
					odd_pos++;
					even_pos++;
					if (array[pos] % 2 == 0) {
						pos++;
					}
				}
				else {    //奇数下标所代表的数为奇数则表明该数在正确的位置上，奇数下标加1
					pos++;
					odd_pos++;
				}
			}
			else {  //当前下标的数为偶数时
				pos++;
			}
		}
	}
};

int main()
{
	Solution s;
	std::vector <int> arr{ 1,2 ,3 ,4,5,6,7};
	s.reOrderArray(arr);
	return 0;
}