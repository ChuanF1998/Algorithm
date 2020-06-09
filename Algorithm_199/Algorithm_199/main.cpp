/*
��Ŀ���߶����������
��Ŀ����
����һ���߶���������룬�����·�ʽ�����߶�����
�������ans����ʼans=0
���庯��build(x,y,z)����������
/////////////////////////
start build
��ֵ ans=x
�ж� ��(y=z) �� end build
�������mid
��ֵ mid=(y+z)/2 {�˴�����Ϊ��ȡ��}
���� build(x*2,y,mid)
���� build(x*2+1,mid+1,z)
end build
/////////////////////////
��������ǣ�����T��ѯ�ʣ�ÿ��ѯ�ʸ���n�������ÿ��n������build(1,1,n)�����ans��
����ÿ��n��ѯ���໥��������ans����һ��ѯ�ʽ�������㡣
����ʱT����������ÿ��n��洢������a�и�����

ʾ��1
����
����
2,[4,5]
���
����
[7,9]
˵��
��n=4ʱ����������߶����������ż����Ӧ������Ϊ
1[1,4],2[1,2],3[3,4],4[1,1],5[2,2],6[3,3],7[4,4]
��n=5ʱ����������߶����������ż����Ӧ������Ϊ
1[1,5],2[1,3],3[4,5],4[1,2],5[3,3],6[4,4],7[5,5],8[1,1],9[2,2]
����[]����Ǳ�ţ�[]�ڱ�ʾ�������ʼλ�ú���ĩλ�á�
��֪����n=4ʱ������Ϊ7����n=5ʱ������Ϊ9
��ע:
T<=100000
0<n<=10^8
*/
#include <vector>
using namespace std;

class Solution {
public:
	/**
	*
	* @param T int����
	* @param a int����һά����
	* @param aLen int a���鳤��
	* @return int����vector
	*/
	void build(int& max, int x, int y, int z)
	{
		if (y == z) {
			if (x > max) {
				max = x;
			}
			return;
		}
		int mid = (y + z) >> 1;
		build(max, x * 2, y, mid);
		build(max, x * 2 + 1, mid + 1, z);
		return;
	}
	vector<int> wwork(int T, int* a, int aLen) {
		// write code here
		vector<int> result;
		int max = 0;
		for (int i = 0; i < aLen; ++i) {
			max = 0;
			build(max, 1, 1, a[i]);
			result.push_back(max);
		}
		return result;
	}
};


class Solution1 {
public:
	/**
	*
	* @param T int����
	* @param a int����һά����
	* @param aLen int a���鳤��
	* @return int����vector
	*/
	vector<int> wwork(int T, int* a, int aLen) {
		// write code here
		vector<int> result;
		for (int i = 0; i < aLen; ++i) {
			int n = a[i];
			int rt = 1;
			while (n != 1) {
				int l = n >> 1;
				int r = n - l;
				if ((l & (-l)) == l && r > l) {
					n = r;
					rt = rt * 2;
				}
				else {
					n = l;
					rt = rt * 2 + 1;
				}

			}
			result.push_back(rt);
		}
		return result;
	}
};


int main()
{
	//int k = (2 & (-2) == 2);
	int l = (2 & (-2)) == 2;
	return 0;
}