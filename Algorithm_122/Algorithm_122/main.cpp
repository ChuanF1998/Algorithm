/*
��Ŀ����
�������������ҳ����ǵĵ�һ��������㡣��ע����Ϊ��������������
���Դ���������ݵ���ʾ����������ʽ��ʾ�ģ���֤������������ȷ�ģ�
*/

//����һ�����������������������n��������������n���ڵ㣬Ȼ��һ���ߣ��������У�����������
//����������1��˼·���һ�£������굱ǰ��������������һ���������й����ڵ㣬·������һ�±�Ȼ����
//������������һ��ջ

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