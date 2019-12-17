/*
题目描述
输入一个链表，按链表从尾到头的顺序返回一个ArrayList。
*/


/*
做法一：利用栈先进后出的原理，先将链表中的value存到栈中，再出栈放到vector中
做法二：先将链表逆置，再直接放入到vector中
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
			
		}
};

class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> arr;
		stack<int> s;
		while (head != nullptr) {
			s.push(head->val);
			head = head->next;
		}
		while (!s.empty()) {
			arr.push_back(s.top());
			s.pop();
		}
		return arr;
	}
};

int main()
{
	return 0;
}