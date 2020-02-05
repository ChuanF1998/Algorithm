/*
输入一个链表，输出该链表中倒数第k个结点。
*/

//注意链表的节点个数可能比k小

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(nullptr) {
	}
};

class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		ListNode* p1 = pListHead;
		ListNode* p2 = p1;
		size_t i = 0;
		for (; p1 != nullptr; ++i) {
			if (i >= k) {
				p2 = p2->next;
			}
			p1 = p1->next;
		}
		if (i < k) {
			return nullptr;
		}
		return p2;
	}
};

int main()
{
	return 0;
}