/*
���ӣ�https://www.nowcoder.com/questionTerminal/1d18c0841e64454cbc3afaea05e2f63c?toCommentId=32793
��Դ��ţ����

��Ȼ�мٱң� �����������ˣ�����ũ��Ĺ���ȴ�����ǰ���ûǮ��ô�����Ⱑ��
nowcoder���ȥ�����⣬�����������Ǯ���мٱң�������ϧnowcoder һ��С
�İ��������һ���������ȥ�ˡ�ֻ֪���ٱҵ���������ҵ�����Ҫ�ᣬ����һ����
ƽ����ƽ�������������޸�Ӳ�ң�����������ʱ����Ǹ��ɶ�ļٱ��ҳ�����

��������:
1��n��2^30,����0��������


�������:
���Ҫ�Ƽ���һ���ܰ��Ǹ��ٱ��ҳ�����
ʾ��1
����
3<br/>12<br/>0
���
1<br/>3
*/

/*
n��3�ı�����ֱ�ӷ�����
n�����ı�������һ���ֳ�n/3, n/3, n/3 + 1;���ʣ n/3 + 1
n�����ı�����2�� �ֳ� n/3, n/3 + 1, n/3 + 1; ���ʣ n/3 + 1
*/
// write your code here cpp
// write your code here cpp
#include <iostream>
using namespace std;

class solution
{
public:
	int Get(unsigned int n)
	{
		int times = 0;
		if (n == 1) {
			return times;
		}
		while (n > 1) {
			if (n % 3 == 0) {
				n /= 3;
			}
			else {
				n = n / 3 + 1;
			}
			times += 1;
		}
		return times;
	}
};

int main()
{
	solution ss;
	unsigned int n;
	while (cin >> n && n != 0) {
		cout << ss.Get(n) << endl;
	}
}