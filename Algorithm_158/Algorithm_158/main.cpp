/*
��Ŀ����
�ֵ��˳��緹��ʱ�䣬������ͬ��ո��з��������µ�GSS-483���Զ�
�򷹻����ˣ������������ڶԻ����˽��й��ܲ��ԡ�
Ϊ�˼����⣬���Ǽ����緹һ����N���ˣ����ڵ�i���ˣ�������ͬ��
���䶨����һ���óԳ̶ȣ����ѳԳ̶ȣ�����Ǹ����Ļ�������A[i]��
����һЩ�������������ѣ����ƣ�������һ��ֻ�ܽ���һ��ָ�������L, 
R������ʾ�����˽���ȥ���L~Rһ��R-L+1���ˡ�
���Ų��˷ѵ�ԭ�����Ǿ��������˴������Ĳˣ�������ҲҪ�����꣬����
����ϣ�������˴�Ĳ˵ĺóԳ̶�֮�����
Ȼ�������Ʊ��ͬ��ϣ���Ի����˽��ж�β��ԣ�ʵ���Ͽ�����Ϊ�˶�Ե��ó�
�Ĳˣ�������֪�������˴�M�β��ܴﵽ�����ĺóԳ̶�֮��
��Ȼ�����һ�εĲ��ǲ����ٴ�ģ�������Ҳ���ԶԻ���������-1, -1����ʾһ����Ҳ����
��������:
��һ�У�N, M

�ڶ��У�A[1], A[2], ..., A[N]
�������:
һ������S����ʾM�δ�˵����óԳ̶�֮��
ʾ��1
����
����
7 2
1 2 3 -2 3 -10 3
���
����
10
˵��
[1 2 3 -2 3] -10 [3]
ʾ��2
����
����
7 4
1 2 3 -2 3 -10 3
���
����
12
˵��
[1 2 3] -2 [3] -10 [3]

���Ĵθ�������-1, -1��ָ��
��ע:
N <= 10^5 = 100000

|A[i]| <= 10^4 = 10000

10%����M = 1

50%����M <= 2

80%����M <= 100

100%����M <= 10^4 = 10000
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr(100001);
vector<vector<int> > sub(2, vector<int>(100000, 0));
vector<int> tmp(100000, 0);


class solution
{
public:
	int Get(int n, int m)
	{
		if (m == 0) {
			return arr[0];
		}
		int num = 0;
		int sum = 0;
		int i = 1;
		while (i <= n) {
			if (arr[i] >= 0) {
				while (i <= n && arr[i] >= 0) {
					sum += arr[i];
					i++;
				}
				sub[1][num] = sum;
				sum = 0;
				num++;
			}
			else {
				while (i <= n && arr[i] < 0) {
					sum += arr[i];
					i++;
				}
				sub[1][num] = sum;
				sum = 0;
				num++;
			}
		}
		for (int i = 0; i < num; ++i) {
			tmp[i] = sub[1][i];
		}
		int count = 0;
		if (m >= num) {
			for (int i = 0; i < num; ++i) {
				if (sub[1][i] > 0) {
					count += sub[1][i];
				}
				tmp[i] = sub[1][i];
			}
			return count;
		}
		else {
			return func(num, m, tmp);
		}
	}

	int func(int num, int m, vector<int>& tmp)
	{
		int k = 0;
		int v = 0;
		int sum = 0;
		for (int i = 0; i < m; ++i) {
			sum = 0;
			k = (i + 1) & 1;
			v = i & 1;
			sub[k][0] = tmp[0];
			for (int j = 1; j < num; ++j) {
				sum = max(sum, sub[v][j - 1]);
				sub[k][j] = max(sum, sub[k][j - 1]) + tmp[j];
			}
		}
		int count = 0;
		for (int i = 0; i < num; ++i) {
			if (sub[k][i] > count) {
				count = sub[k][i];
			}
		}
		return count;
	}
};

int main()
{
	arr[0] = 0;
	solution ss;
	int N;
	int M;
	while (cin >> N >> M) {
		for (int i = 1; i <= N; ++i) {
			cin >> arr[i];
		}
		cout << ss.Get(N, M) << endl;
	}
	return 0;
}