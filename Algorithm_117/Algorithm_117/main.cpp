/*
题目描述
输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
*/
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		vector<int> arr;
		//小于等于k个
		if ((int)input.size() < k) {
			return arr;
		}

		//大于k个，建堆，从倒数第一个非叶子节点开始向前
		int arrMaxFlag = (int)input.size() - 1;
		int parent = arrMaxFlag / 2;
		for (int i = parent; i >= 0; i--) {
			Heap_sort(input, i, arrMaxFlag);
		}
		//拆堆
		int end = arrMaxFlag;
		for (int i = 0; i < k; ++i) {
			arr.push_back(input[0]);
			swap(input[0], input[end]);
			arrMaxFlag -= 1;
			end = arrMaxFlag;
			Heap_sort(input, 0, arrMaxFlag);
		}
		return arr;
	}
	//堆排序，小根堆
	void Heap_sort(vector<int>& input, int parent, int arrMaxFlag)
	{
		int child = parent * 2 + 1;
		//向下调整，双亲节点与最小的叶子节点交换
		while (child <= arrMaxFlag) {
			if (child + 1 <= arrMaxFlag && input[child + 1] < input[child]) {
				child = child + 1;
			}
			if (input[child] < input[parent]) {
				swap(input[child], input[parent]);
			}
			parent = child;
			child = parent * 2 + 1;
		}
	}
};

int main()
{
	return 0;
}