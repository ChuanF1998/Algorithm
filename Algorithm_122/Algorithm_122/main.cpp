/*
题目描述
输入两个链表，找出它们的第一个公共结点。（注意因为传入数据是链表，
所以错误测试数据的提示是用其他方式显示的，保证传入数据是正确的）
*/

//方法一：遍历两个链表并计数，求差n。长的链表先走n个节点，然后一起走，相遇则有，不相遇则无
//方法二：与1的思路大概一致，遍历完当前链表后继续遍历另一条链表，若有公共节点，路径长度一致必然相遇
//方法三：利用一个栈

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(nullptr) {
	}
};
class Solution {
public:
	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
		if (pHead1 == nullptr || pHead2 == nullptr) {
			return nullptr;
		}
		int nodeNum1 = 0;
		int nodeNum2 = 0;
		ListNode* p1 = pHead1;
		ListNode* p2 = pHead2;
		while (p1 != nullptr) {
			nodeNum1++;
			p1 = p1->next;
		}
		while (p2 != nullptr) {
			nodeNum2++;
			p2 = p2->next;
		}
		int defference = nodeNum1 > nodeNum2 ? (nodeNum1 - nodeNum2) : (nodeNum2 - nodeNum1);
		if (nodeNum1 > nodeNum2) {
			return Find(pHead1, pHead2, defference);
		}
		else {
			return Find(pHead2, pHead1, defference);
		}
	}

	ListNode* Find(ListNode* pHead1, ListNode* pHead2, int defference)
	{
		if (pHead1 == nullptr || pHead2 == nullptr) {
			return nullptr;
		}
		while (defference--) {
			pHead1 = pHead1->next;
		}
		while (pHead1 != nullptr && pHead2 != nullptr) {
			if (pHead1 == pHead2) {
				return pHead1;
			}
			pHead1 = pHead1->next;
			pHead2 = pHead2->next;
		}
		return nullptr;
	}
};

int main()
{
	return 0;
}