
/*
题目：牛妹的面试
题目描述
众所周知，牛妹是一个offer收割姬，这次面试她遇到了这样的一个问题。
给了一个序列，让找出最长的“凸子序列”
何为“凸子序列”：数列中有一个xi,使得所有x0<x1<x2….xi-1<xi且xi>xi+1>xi+1>….>xn
eg：12345431,是山峰序列，12345234不是山峰序列
注：单调递增或单调递减序列也算山峰序列；单独一个数是长度为1的山峰序列

示例1
输入
复制
[1,2,3,6,1]
输出
复制
5
示例2
输入
[1,2,2,1]
输出
3
说明
1,2,1
备注:
给定的序列中数都大于0 且不超过10000，且序列长度不超过1000
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	/**
	* 返回最大山峰序列长度
	* @param numberList int整型vector 给定的序列
	* @return int整型
	*/
	int mountainSequence(vector<int>& numberList) {
		// write code here
		int size = (int)numberList.size();
		vector<int> arr1(size, 1);
		vector<int> arr2(size, 1);
		int ma = 0;
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < i; ++j) {
				if (numberList[i] > numberList[j]) {
					arr1[i] = max(arr1[i], arr1[j] + 1);
				}
				if (numberList[size - i - 1] > numberList[size - j - 1]) {
					arr2[size - i - 1] = max(arr2[size - 1 - i], arr2[size - j - 1] + 1);
				}
			}
		}
		for (int i = 0; i < size; ++i) {
			ma = max(ma, arr1[i] + arr2[i] - 1);
		}
		return ma;
	}
};

int main()
{
	return 0;
}