/*
��Ŀ����
����n��������������ִ������ڵ������鳤��һ�������
��������:
ÿ������������� n���ո�ָ��n��������n������100��������һ���������ִ������ڵ���n/2��
�������:
������ִ������ڵ���n/2������
ʾ��1
����
3 9 3 2 5 6 7 3 2 3 3 3

���
3
*/


#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		int theNum = 0;  //���浱ǰ��
		int minus_count = 0;  //����
		if (numbers.empty()) {
			return theNum;
		}
		theNum = numbers[0]; 
		minus_count = 1;
		for (int i = 1; i < (int)numbers.size(); ++i) {
			//������1
			if (numbers[i] == theNum) { 
				minus_count++;
				if (minus_count >(int)numbers.size() / 2) {
					break;
				}
			}
			else {
				//�������һ
				minus_count--;
				//����Ϊ0ʱ�����浱ǰ����
				if (minus_count == 0) {
					theNum = numbers[i];
					minus_count++;
				}
			}
		}
		//���Ӧ���ж��Ƿ����
		//�������[1,2,4,5,2,2,2]��ô��Ȼ����
		//�������[1,2,3,4]���������theNumΪ4������4������
		minus_count = 0;
		for (int i = 0; i < (int)numbers.size(); ++i) {
			if (numbers[i] == theNum)
				minus_count++;
		}
		return (minus_count >(int)numbers.size() / 2) ? theNum : 0;
	}
};




int main()
{
	return 0;
}