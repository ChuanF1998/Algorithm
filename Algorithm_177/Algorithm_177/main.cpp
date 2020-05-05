/*
��Ŀ��ţ�ô����
��Ŀ����
������֪��ţ�÷ǳ�ϲ������Ϸ�����������ĵ�һ�죬������һ����������޵���Ϸ��
Ҳ�����Ѿ�֪����Ϸ���������������֪����û��ϵ���������ڸ�������
ɭ��������ô���������ǹ������ﲢ������ׯ��Ӣ�ۡ�
Ϊ�˼����⣬���ǰѹ����ų�һ�У����������кܶ๥���㣬����һ�ѽ���
ֻ���е������㣬���е�һ��������ʱ���������ѳ������ڶ��У�������������
����һ��������������������ǽ������и�ɲ������κι����㡣���磬�����һ
������ù���ĳ���Ϊ20���������ĸ����������������ϣ�2 5 10 18.�����������и
1.�п���һ�㣬��ʹ�õ�����Ϊ2 + 18 = 20��
2.�еڶ��㣬��ʹ�õ�����Ϊ3 + 15 = 18��
3.�е����㣬��ʹ�õ�����Ϊ5 + 10 = 15��
4.�е��ĵ㣬��ʹ�õ�������8 + 2 = 10��
��ʹ�õ�������Ϊ��20 + 18 + 15 + 10 = 63;
�������Բ�����һ�ֲ��ԣ�
1.�еڶ��㣬��ʹ�õ�������5 + 15 = 20��
2.�п���һ�㣬��ʹ�õ�����Ϊ2 + 3 = 5��
3.�е����㣬��ʹ�õ�������5 + 10 = 15��
4.�е��ĸ��㣬��ʹ�õ�����Ϊ8 + 2 = 10��
��ʹ�õ�����Ϊ��20 + 5 + 15 + 10 = 50;
���������ѵĲ�������С����Ҫ���ĵ�������
��ô�������ˣ�ţ����Ը���������ͳ��ȵĹ��ޣ����������������ٶ��ٵ������򵹹����أ�

ʾ��1
����
����
20,[2,5,10,18]
���
����
45
��ע:
���������С��300
���޳���С��1000000
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	/**
	*
	* @param monsterLength int���� ���޳���
	* @param monsterPoint int����vector ���޹�����λ��
	* @return int����
	*/
	int attackMonster(int monsterLength, vector<int>& monsterPoint) {
		// write code here
		int n = monsterPoint.size();
		vector<vector<int> > arr(n + 2, vector<int>(n + 2, 0));
		monsterPoint.push_back(0);
		monsterPoint.push_back(monsterLength);
		sort(monsterPoint.begin(), monsterPoint.end());
		for (int len = 2; len <= n + 1; ++len) {
			for (int i = 1; i + len - 1 <= n + 1; ++i) {
				arr[i][i + len - 1] = 300000001;
				for (int j = i; j < i + len - 1; ++j) {
					arr[i][i + len - 1] = min(arr[i][i + len - 1], arr[i][j] + arr[j + 1][i + len - 1]
						+ monsterPoint[i + len - 1] - monsterPoint[i - 1]);
				}
			}
		}
		return arr[1][n + 1];
	}
};

int main()
{
	Solution ss;
	vector<int> arr{ 2, 5, 10, 18 };
	int k = ss.attackMonster(20, arr);
	return 0;
}