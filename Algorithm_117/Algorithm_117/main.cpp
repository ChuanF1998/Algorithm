/*
��Ŀ����
����n���������ҳ�������С��K��������������4,5,1,6,2,7,3,8��8�����֣�����С��4��������1,2,3,4,��
*/
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		vector<int> arr;
		//С�ڵ���k��
		if ((int)input.size() < k) {
			return arr;
		}

		//����k�������ѣ��ӵ�����һ����Ҷ�ӽڵ㿪ʼ��ǰ
		int arrMaxFlag = (int)input.size() - 1;
		int parent = arrMaxFlag / 2;
		for (int i = parent; i >= 0; i--) {
			Heap_sort(input, i, arrMaxFlag);
		}
		//���
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
	//������С����
	void Heap_sort(vector<int>& input, int parent, int arrMaxFlag)
	{
		int child = parent * 2 + 1;
		//���µ�����˫�׽ڵ�����С��Ҷ�ӽڵ㽻��
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