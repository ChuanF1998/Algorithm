/*
��Ŀ����
һ�����������������������֮�⣬���������ֶ����������Ρ���д�����ҳ�������ֻ����һ�ε����֡�
*/
#include <vector>

class Solution {
public:
	void FindNumsAppearOnce(std::vector<int> data, int* num1, int *num2) {
		int xor12 = 0;
		for (size_t i = 0; i < data.size(); ++i) {
			xor12 ^= data[i];
		}
		int flag = 1;
		while (!(flag & xor12)) {
			flag <<= 1;
		}
		*num1 = 0;
		*num2 = 0;
		for (size_t i = 0; i < data.size(); ++i) {
			if (flag & data[i]) {
				*num1 ^= data[i];
			}
			else {
				*num2 ^= data[i];
			}
		}
		return;
	}
};

int main()
{
	return 0;
}