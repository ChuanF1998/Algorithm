/*
����һ����������������е�����k����㡣
*/

//ע������Ľڵ�������ܱ�kС

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