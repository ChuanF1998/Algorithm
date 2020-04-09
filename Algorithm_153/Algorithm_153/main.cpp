/*
��Ŀ����
С����һ���ӳ����εĻ�ľ�����һ����ľA�ĳ��Ϳ�����������һ����ľB�ĳ��Ϳ�
���ľA���Դ��ڻ�ľB�����档�����С���ر���֪����һ���ӻ�ľ�����Դ���ٲ㣬���ܰ�������취��
����ÿһ�������εĳ�L�Ϳ�W��Ϊ������������1 <= W <= L <= INT_MAX, 
�������泤���εĸ���ΪN, ���� 1 <= N <= 1000000.
��������ﹲ��5����ľ�ֱ�Ϊ (2, 2), (2, 4), (3, 3), (2, 5), (4, 5), 
�����ж���Щ��ľ�����Դ��4��, ��Ϊ(2, 2) < (2, 4) < (2, 5) < (4, 5)��
��������:
��һ��Ϊ��ľ���ܸ��� N

֮��һ����N�У��ֱ��Ӧ��ÿһ����ľ�Ŀ�W�ͳ�L
�������:
����ܹ����Դ�Ĳ���
ʾ��1
����
5
2 2
2 4
3 3
2 5
4 5

���
4
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int tier[1000000];
pair<int, int> tower[1000000];

class solution
{
public:
	int Get(int n)
	{
		if (n == 0) {
			return 0;
		}
		sort(tower, tower + n);
		tier[0] = tower[0].second;
		int len = 1;
		for (int i = 1; i < n; ++i) {
			if (tower[i].second >= tier[len - 1]) {
				tier[len++] = tower[i].second;
			}
			else {
				auto it = upper_bound(tier, tier + len, tower[i].second);
				*it = tower[i].second;
			}
		}
		return len;
	}
};

int main()
{
	solution ss;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> tower[i].first >> tower[i].second;
	}
	cout << ss.Get(n) << endl;
	return 0;
}



#if 0

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//int tier[1000000];
//pair<int, int> tower[1000000];

vector<pair<int, int> > tower(1000000);
vector<int> tier(1000000);

class solution1
{
public:
	int Get(int n)
	{
		if (n == 0) {
			return 0;
		}
		sort(tower.begin(), tower.begin() + n);
		tier[0] = tower[0].second;
		int len = 1;
		for (int i = 1; i < n; ++i) {
			if (tower[i].second >= tier[len - 1]) {
				tier[len++] = tower[i].second;
			}
			else {
				auto it = upper_bound(tier.begin(), tier.begin() + len, tower[i].second);
				*it = tower[i].second;
			}
		}
		return len;
	}
};

#endif