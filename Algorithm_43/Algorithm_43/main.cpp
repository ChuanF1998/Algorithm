/*
��Ŀ����
A,B,C�������Ǻ�����,ÿ�������ﶼ��һЩ�ǹ�,���ǲ�֪������ÿ����
���Ͼ����ж��ٸ��ǹ�,��������֪�����µ���Ϣ��
A - B, B - C, A + B, B + C. ���ĸ���ֵ.ÿ����ĸ����ÿ������ӵ�е��ǹ���.
������Ҫͨ�����ĸ���ֵ�����ÿ���������ж��ٸ��ǹ�,��A,B,C�����ﱣ֤��
��ֻ��һ������A,B,C������������������

��������:
����Ϊһ�У�һ��4���������ֱ�ΪA - B��B - C��A + B��B + C���ÿո������ 
��Χ����-30��30֮��(������)��

�������:
���Ϊһ�У�����������������A��B��C��˳�����A��B��C���ÿո��
������ĩ�޿ո� �������������������A��B��C�������No

ʾ��1
����
1 -2 3 4

���
2 1 3
*/



#include <iostream>
using namespace std;

class candies
{
public:
	void get_candies(int x, int y, int z, int m)
	{
		if ((x + z) % 2 != 0 || (m - y) % 2 != 0) {
			cout << "No" << endl;
			return;
		}
		int A = (x + z) / 2;
		int B = z - A;
		int C = m - B;
		if (A >= 0 && B >= 0 && C >= 0) {
			cout << A << " " << B << " " << C << endl;
		}
		else {
			cout << "No" << endl;
		}
		return;
	}
};


int main()
{
	candies c;
	int x, y, z, m;
	cin >> x >> y >> z >> m;
	c.get_candies(x, y, z, m);
	return 0;
}