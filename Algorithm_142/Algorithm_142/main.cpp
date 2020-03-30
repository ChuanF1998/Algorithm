/*
题目描述
如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，
那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，
那么中位数就是所有数值排序之后中间两个数的平均值。我们使用Insert()方法读取数据流，
使用GetMedian()方法获取当前读取数据的中位数。
*/


#include <queue>
#include <functional>
using namespace std;

class Solution {
public:
	void Insert(int num)
	{
		//大根堆为空或者插入数据小于大根堆堆顶，则将数据插入大根堆
		if (max_heap.empty() || num < max_heap.top()) {
			max_heap.push(num);
		}
		//插入小根堆
		else {
			min_heap.push(num);
		}
		//调整：大根堆size超过小根堆size，超过1就将大根堆堆顶pop，然后插入到小根堆
		if (max_heap.size() > min_heap.size() + 1) {
			min_heap.push(max_heap.top());
			max_heap.pop();
		}
		//调整：小根堆size大于大根堆size
		if (max_heap.size() < min_heap.size()) {
			max_heap.push(min_heap.top());
			min_heap.pop();
		}
	}

	double GetMedian()
	{
		return (max_heap.size() > min_heap.size()) ? (double)max_heap.top() : ((double)max_heap.top() + (double)min_heap.top()) / 2;
	}
public:
	//保证大根堆size大于等于小根堆size，但不超过1. 
	//这样获取中位数：单数个情况，大根堆堆顶
	//双数个，（大根堆堆顶 + 小根堆堆顶）  /  2 ；
	priority_queue<int, vector<int>, less<int> > max_heap;   //大根堆
	priority_queue<int, vector<int>, greater<int> > min_heap; //小根堆
};


int main()
{
	return 0;
}