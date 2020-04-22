/*
��Ŀ����Щ��ӵ���
��Ŀ����
��Ŀ������

�������⣺

����һ������Ϊ n �Ķ��飬����������Ϊ 1~n���� m �β����Ϊ�������� cutIn ���б�ʾ��
cutIn ��Ԫ�����δ�����Ҫ��ӵ��˵ı�ţ�ÿ�β�ӣ�����˶���ֱ���ƶ����������ǰ����
����Ҫ����һ�������������� m �β����Ϊ֮���ж��ٸ����Ѿ�����ԭ�������λ���ˡ�

ʾ��1
����
����
3,[3, 2, 3]
���
����
2
˵��
��ʼ����Ϊ [1, 2, 3]
3 ��ʼ��� [3, 1, 2]
2 ��ʼ��� [2, 3, 1]
3 ��ʼ��� [3, 2, 1]
����2����ԭ����β�ã�3��1�������Ѿ�����ԭ����λ���ˡ�
ʾ��2
����
����
3,[]
���
����
0
˵��
û���˽��в�ӣ������˶����Լ�ԭ����λ���ϡ�
��ע:
�����������ݣ���֤ n \leq 1e9n��1e9, m\leq 1e4m��1e4���� cutIn[i] \leq ncutIn[i]��n
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
	/**
	* �����ж��ٸ������ղ����Լ�ԭ����λ����
	* @param n int���� �����ܳ�
	* @param cutIn int����vector ���λ��ӵ���ǰ�����˵ı��
	* @return int����
	*/
	int countDislocation(int n, vector<int>& cutIn) {
		// write code here
		int max_pos = 0;  //������˱��
		int line = 1;     //��Ӷ���ı��
		int right = 0;     //��Ӻ��Ų�����˵�����
		map<int, int> m;
		for (int i = (int)cutIn.size() - 1; i >= 0; --i) {
			//�ظ���ӡ�ֻ�����һ�β��
			if (m.count(cutIn[i]) == 0) {
				m[cutIn[i]] = 1; //������ӳɹ�
				if (cutIn[i] == line) { //��Ų���
					right += 1;  //������һ
				}
				line += 1;
				max_pos = max(max_pos, cutIn[i]);
			}
		}
		return max_pos - right;
	}
};

int main()
{
	vector<int> cut{ 5241, 339, 155, 1514, 6887, 6769, 7763, 8997, 6435, 8930 };
	Solution ss;
	int k = ss.countDislocation(10000, cut);
	return 0;
}