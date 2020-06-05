/*
��Ŀ�������������
��Ŀ����
��Ŀ������

��һ�������ε����Ǵ�½�ϣ�һ�ж�������������ɵġ�
Ϊ�˼���Ǽ�ͨ��Ѷ���������Ѱ���������ƻ�����ѧ����
�ⶨ�ڹ��ҵİ�ͼ��ѡȡһ��������������������ε������Զ��
��Ϊ�˾�����̽��������΢�����źţ���Զ����������Խ��Խ�á����������˹���Ĵ����ѡȡ��ַ���Ե�ʮ����Ҫ��

����������������ѡ�����ѵĵ�ַ��ʹ���������������
�������Զ���������Σ����Զ��㳯��Ҳ���Զ��㳯�£��ı߳������ܴ�



�������⣺

����һ���߳�Ϊ a �������� 01 �������ҵ�һ������ȫ 1 �������Σ���������εı߳� b��

ʾ��1
����
����
2,[0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1]
���
����
2
˵��
����ͼ�������ҵ�һ���߳�Ϊ2���������Σ�������Ψһ��

��ע:
�������е��������ݣ����� 1 \leq a \leq 1001��a��100��

������������� 01 ���� maps �������±꣬ÿ���������δ����ң��ٴ��ϵ��¶�Ӧÿһ�����������ͼ��


*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	/**
	* ����������01����������ȫ1�������εı߳�
	* @param a int���� ������01����ı߳�
	* @param maps int����vector ����ľ������ݣ����ϵ��£�������˳������
	* @return int����
	*/
	int largestSubTriangle(int a, vector<int>& maps) {
		// write code here
		int m_len = a * 4 - 1;
		vector<vector<int> > m(a * 2, vector<int>(m_len, 0));
		vector<vector<int> > order(a * 2, vector<int>(m_len, 0));
		vector<vector<int> > re(a * 2, vector<int>(m_len, 0));
		int pos = 0;
		for (int i = 0; i < a; ++i) {
			for (int j = a - i - 1, d = 1; j < a * 3 + i; ++j, ++d) {
				m[i][j] = maps[pos++];
				order[i][j] = d % 2;
			}
		}
		for (int i = a; i < 2 * a; ++i) {
			for (int j = i - a, d = 0; j < 5 * a - i + 1; ++j, ++d) {
				m[i][j] = maps[pos++];
				order[i][j] = d % 2;
			}
		}
		int ans = 0;
		for (int i = 0; i < a * 2; ++i) {
			for (int j = 0; j < m_len; ++j) {
				if (m[i][j] == 1 && order[i][j] == 0) {
					re[i][j] = 1;
					if (i - 1 >= 0 && j - 1 >= 0 && j + 1 < m_len && m[i - 1][j] == 1) {
						re[i][j] = min(re[i - 1][j - 1], re[i - 1][j + 1]) + 1;
					}
				}
				ans = max(ans, re[i][j]);
			}
		}
		for (int i = a * 2 - 1; i >= 0; --i) {
			for (int j = 0; j < m_len; ++j) {
				if (m[i][j] == 1 && order[i][j] == 1) {
					re[i][j] = 1;
					if (i + 1 < a * 2 && j - 1 >= 0 && j + 1 < m_len && m[i + 1][j] == 1) {
						re[i][j] = min(re[i + 1][j - 1], re[i + 1][j + 1]) + 1;
					}
				}
				ans = max(ans, re[i][j]);
			}
		}
		return ans;
	}
};

int main()
{
	return 0;
}