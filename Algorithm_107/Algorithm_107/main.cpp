/*
��Ŀ����
��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת��
����һ���ǵݼ�����������һ����ת�������ת�������СԪ�ء�
��������{3,4,5,1,2}Ϊ{1,2,3,4,5}��һ����ת�����������СֵΪ1��
NOTE������������Ԫ�ض�����0���������СΪ0���뷵��0
*/


#include <vector>

class Solution {
public:
	int minNumberInRotateArray(std::vector<int> rotateArray) {
		if (rotateArray.size() == 0) {
			return 0;
		}
		int begin = 0;
		int end = rotateArray.size() - 1;
		int temp;
		int min_pos = 0;
		while (rotateArray[begin] >= rotateArray[end]) {
			if (begin + 1 == end) {
				min_pos = end;
				break;
			}
			int flag = (begin + end) / 2;
			temp = rotateArray[flag];
			if (temp >= rotateArray[begin]) {
				begin = flag;
			}
			else {
				end = flag;
			}
		}
		return rotateArray[min_pos];
	}
};

int main()
{
	return 0;
}