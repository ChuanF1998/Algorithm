/*
��Ŀ����
�Ѻ�Ա��С��������ü�����������Σ���ĳ��С������һ����Ϸ�ű��ݣ�
���ʵı��ݽ��������ų����ʹ��������ǰ�������ۣ�С�����������˽⵽�� 
��Ϸ���������һ���½�Ŀ������޺�����������Ϸ��Ա���޺����ݡ����ǵ���ȫ���أ�
Ҫ����޺������У�վ��ĳ���˼��ϵ���Ӧ�üȱ��Լ����ֱ��Լ��ݣ�����ȡ� �ų�
��Ҫ���ν�Ŀ�е��޺���������ߣ����������ڶ࣬����ͷ����ΰ�����Ա�����⡣С
�������������ܼ򵥣�����ͳ���˲�������޺������ݵ�������Ա��������أ�����
�ܿ��ҵ�������޺�������Ա���С� ����������Ҳ�õ�������һ��������ر����ҳ�
���Ե���������޺����ĸ߶ȣ���ݱ�����Ϸ��Ա���α��Ϊ1��N��
��������:
����һ��������N����ʾ��Ա������
֮��N�У�ÿ�����������ֱ��Ӧ��Ϸ��Ա��ţ����غ���ߡ�
�������:
������m����ʾ�޺����ĸ߶ȡ�
ʾ��1
����
����
6<br/>1 65 100<br/>2 75 80<br/>3 80 100<br/>4 60 95<br/>5 82 101<br/>6 81 70<br/>
���
����
4
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct people
{
	int num;
	int wei;
	int hei;
};


int main()
{
	int n;
	while (cin >> n) {
		vector<people> arr(n);
		for (int i = 0; i < n; ++i) {
			cin >> arr[i].num >> arr[i].wei >> arr[i].hei;
		}
		sort(arr.begin(), arr.end(), [](const people& a, const people& b){
			if (a.wei < b.wei) {
				return true;
			}
			else if (a.wei == b.wei) {
				return a.hei > b.hei;
			}
			else {
				return false;
			}
		});
		vector<int> re(n, 0);
		re[0] = 0;
		int result = -1;
		for (int i = 0; i < n; ++i) {
			//int count = 0;
			for (int j = i; j >= 0; --j) {
				if (arr[i].hei >= arr[j].hei) {
					re[i] = max(re[i], re[j] + 1);
				}
			}
			result = max(result, re[i]);
		}
		cout << result << endl;
	}
	return 0;
}