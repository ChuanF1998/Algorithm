/*
题目描述
输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），
返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
*/

struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
		label(x), next(nullptr), random(nullptr) {
	}
};

class Solution {
public:
	RandomListNode* Clone(RandomListNode* pHead)
	{
		ListClone(pHead);
		RandomNode(pHead);
		return ListBreakUp(pHead);
	}

	//首先复制每个节点，并将复制后的节点放在原节点后面
	void ListClone(RandomListNode* pHead)
	{
		RandomListNode* Head = pHead;
		while (Head != nullptr) {
			RandomListNode* temp = new RandomListNode(Head->label);
			temp->next = Head->next;
			Head->next = temp;
			Head = Head->next->next;
		}
	}

	//连接随机节点
	void RandomNode(RandomListNode* pHead)
	{
		RandomListNode* Head = pHead;
		while (Head != nullptr) {
			if (Head->random == nullptr) {}
			//双数节点的随机指针指向前一个单数的随机指针的下一个节点
			//next:a->a'->b->b'->c->c'
			//random:a->c,那么 a'->c'
			else if (Head->random->next != nullptr) {
				Head->next->random = Head->random->next;
			}
			//如果a->d, 那么需要再为d开辟空间
			else {
				RandomListNode* temp = new RandomListNode(Head->random->label);
				Head->next->random = temp;
			}
			Head = Head->next->next;
		}
	}

	//拆分链表
	RandomListNode* ListBreakUp(RandomListNode* pHead)
	{
		if (pHead == nullptr) {
			return nullptr;
		}
		RandomListNode* Head = pHead;
		RandomListNode* pRoot = pHead->next;
		RandomListNode* newNode = pHead->next;
		Head->next = newNode->next;
		Head = Head->next;
		while (Head != nullptr) {
			newNode->next = Head->next;
			newNode = newNode->next;
			Head->next = newNode->next;
			Head = Head->next;
		}
		return pRoot;
	}
};

int main()
{
	return 0;
}