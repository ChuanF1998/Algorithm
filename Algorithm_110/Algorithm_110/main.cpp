/*
题目描述
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。假设压入栈的所有数字均不相等。
例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。
（注意：这两个序列的长度是相等的）
*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		if (pushV.size() != popV.size()) {
			return false;
		}
		int pushVSize = pushV.size();
		int pushVpos = 0;  //pushV的下标
		int popVpos = 0;   //popv的下标
		stack<int> s;
		bool isPopOrder = true;  //我们先假设他们是成立的
		while (popVpos < (int)popV.size()) { //循环条件：出栈序列未判断完
			//栈不为空或栈顶元素与当前出栈的元素不等时（且数组未完全压完栈）
			if (s.empty() || (s.top() != popV[popVpos] && pushVpos < pushVSize)) {
				s.push(pushV[pushVpos]);  //往栈里面插入元素
				pushVpos++;
			}
			//栈不为空且栈顶元素等于当前出栈序列的值时就出栈
			if (!s.empty() && s.top() == popV[popVpos]) { 
				s.pop();
				popVpos++;
			}
			//栈不为空且压栈数组已经压完且栈顶不等于当前出栈序列的值时，就可以判断假设不成立，退出
			if (!s.empty() && pushVSize == pushVpos && s.top() != popV[popVpos]) {
				isPopOrder = false;
				break;
			}
		}
		return isPopOrder;
	}
};

int main()
{
	return 0;
}