/*
��Ŀ:ţţ��66
��Ŀ����
������֪��ţţ��ϲ��6������֣���Ϊţţ��66���������
��������֪����������nλʮ���������ж��ٸ����ֲ�����������6����1��ʼ��ģ�
����ֻ����һ��������n��1<=n<20��

ʾ��1
����
����
1
���
����
"10"
˵��
1��2,3,4,5,6,7,8,9,10 ��ʮ�������ж���������
ʾ��2
����
����
2
���
����
"99"
˵��
��Ϊ66������
*/


#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	/**
	*
	* @param n int����
	* @return string�ַ���
	*/
	int a[100][100];
	string calculate(int n) {
		// write code here
		if (n == 1) return "10";
		int i, j;
		a[1][1] = 0;
		a[1][2] = 1;
		a[2][1] = a[2][2] = 9;
		for (i = 3; i <= n; i++)
		for (j = 1; j <= i; j++)
		{
			a[i][j] += (a[i - 1][j] + a[i - 2][j]) * 9;
			if (a[i][j] >= 10 && a[i][j]<100)
			{
				a[i][j + 1] += a[i][j] / 10;
				a[i][j] = a[i][j] % 10;
			}
			if (a[i][j] >= 100)
			{
				a[i][j + 2] += a[i][j] / 100;
				a[i][j + 1] += a[i][j] / 10 % 10;
				a[i][j] %= 10;
			}
		}
		string str("");
		for (i = n; i>0; i--)
			str.append(to_string(a[n][i]));
		return str;
	}
};

int main()
{
	return 0;
}