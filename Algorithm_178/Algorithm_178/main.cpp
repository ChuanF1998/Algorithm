/*
��Ŀ��ţ�õ�����
��Ŀ����
������֪��ţ�÷ǳ�ϲ���Ե��⡣
��һ��ţ�óԵ�������������֮һ������ȡ������һ����
�ڶ����ֽ�ʣ�µĵ���Ե�����֮һ������ȡ������һ����
�Ժ�ÿ��Ե�ǰһ��ʣ�µ�����֮һ������ȡ������һ����
����n��׼���Ե�ʱ��ֻʣ��һ�����⡣
ţ����֪����һ�쿪ʼ�Ե�ʱ�򵰸�һ���ж����أ�

ʾ��1
����
����
2
���
����
3
ʾ��2
����
����
4
���
����
10
��ע:
0<n< 30
*/
#include <vector>
using namespace std;

class Solution {
public:
	/**
	*
	* @param n int���� ֻʣ��һֻ�����ʱ�����ڵ�n�췢���ģ�
	* @return int����
	*/
	int cakeNumber(int n) {
		// write code here
		vector<int> arr(n + 1, 0);
		arr[n] = 1;
		for (int i = n - 1; i >= 1; --i) {
			arr[i] = (arr[i + 1] * 3 + 3) / 2;
		}
		return arr[1];
	}
};

int main()
{
	return 0;
}