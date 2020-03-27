/*
题目描述
请实现一个函数用来找出字符流中第一个只出现一次的字符。
例如，当从字符流中只读出前两个字符"go"时，第一个只出现一
次的字符是"g"。当从该字符流中读出前六个字符“google"时，
第一个只出现一次的字符是"l"。
输出描述:
如果当前字符流没有存在出现一次的字符，返回#字符。
*/


//方法一：数组+队列，队列保存只出现一次的字符，出现多次后，从队头删除直到队头字符只出现一次。
//方法二：数组+字符串，字符串用于保存字符，遍历字符串，找出第一个只出现一次的字符。

#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
	Solution()
	{
		_str_arr.resize(255, 0);
	}
	//Insert one char from stringstream
	void Insert(char ch)
	{
		_str_arr[ch]++;
		if (_str_arr[ch] == 1) {
			_once.push(ch);
		}
	}
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce()
	{
		while (!_once.empty() && _str_arr[_once.front()] > 1) {
			_once.pop();
		}
		if (!_once.empty()) {
			return _once.front();
		}
		return '#';
	}

public:
	vector<int> _str_arr;
	queue<char> _once;
};

int main()
{
	return 0;
}