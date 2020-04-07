/*
��Ŀ����
С����ѧУ��ѧϰ�˹����ַ���������, ���������ڴ������һ���ֵ����Ŀ��

С�׵�����ֵ������, �ֵ��ڵ�ÿ�����ʶ�����n��'a'��m��'z', �������е��ʰ����ֵ������С�

С������ϣ�����ܰ����ҳ���k��������ʲô��

��������:
�������һ����������n, m, k(1 <= n, m <= 100, 1 <= k <= 109), �Կո�ָ

�������:
�����k���ֵ��е��ַ���������޽⣬���-1��
ʾ��1
����
2 2 6

���
zzaa
˵��
�ֵ��е��ַ�������Ϊaazz azaz azza zaaz zaza zzaa
*/

/*
ÿȷ��һ���ַ������൱�ڽ���Χ��Сһ�룬�����Сһ�㲻�����ֶ��������(ֻ�����������ַ�)
��������a��ͷ���������z��ͷ����
*/

#include <iostream>
#include <string>
using namespace std;

class solution
{
public:
	string GetMax(int n, int m, int k)
	{
		string s;
		while (n > 0 && m > 0) {
			long long count = 1;
			for (int i = 1; i <= n - 1; ++i) {
				count *= n + m - i;
				count /= i;
				if (count >= k) {
					break;
				}
			}
			if (k <= count) {
				s += "a";
				n--;
			}
			if (k > count) {
				s += "z";
				k -= count;
				m--;
			}
		}
		if (k != 1) {
			return "-1";
		}
		while (n--) {
			s += "a";
		}
		while (m--) {
			s += "z";
		}
		return s;
	}
};

int main()
{
	solution s;
	int n;
	int m;
	int k;
	while (cin >> n >> m >> k) {
		cout << s.GetMax(n, m, k) << endl;
	}
	return 0;
}