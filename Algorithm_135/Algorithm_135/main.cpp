/*
��Ŀ����
дһ������������������֮�ͣ�Ҫ���ں������ڲ���ʹ��+��-��*��/����������š�
*/


class Solution {
public:
	int Add(int num1, int num2)
	{
		int and_ = num1 & num2; //����������
		int xor_ = num1 ^ num2; //�����������
		//�����Ľ��Ϊ0���˳�
		while (and_) {
			and_ <<= 1;  //����Ľ�����ƣ���ʱû�е��ڳ���
			num1 = and_;  //���� 
			and_ &= xor_;  //
			xor_ ^= num1;
		}
		return xor_; //����������������
	}
};

int main()
{
	return 0;
}