/*
��Ŀ����
����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ����
����������Yes,�������No���������������������������ֶ�������ͬ��
*/

//�����������ĺ������������һ��ֵ�Ƕ����������ĸ��ڵ㣬ע��߽磬���ж�����z
//����ʱע�ⷶΧ�����ܴ���ԭ���ڵ㣩���������޵ݹ�

#include <vector>


class Solution {
public:
	bool VerifySquenceOfBST(std::vector<int> sequence) {
		if (sequence.size() == 0) {
			return false;
		}
		return func(sequence, sequence[sequence.size() - 1], 0, sequence.size() - 1);
	}

	bool func(std::vector<int>& arr, int root, int begin, int end)
	{
		if (begin >= end) {
			return true;
		}
		int i = begin;
		//�ж��������Ƿ����
		for (; i < end; i++) { //�ֿ���������
			if (arr[i] > root) {
				break;
			}
		}
		//�ж��������Ƿ����
		for (int j = i; j < end; j++) {
			if (arr[j] < root) {
				return false;
			}
		}
		return func(arr, arr[i - 1], begin, i - 1) && func(arr, arr[end - 1], i, end - 1);
	}
};

int main()
{
	return 0;
}

