/*
��Ŀ����
ÿ����һ��ͯ��,ţ�Ͷ���׼��һЩС����ȥ�����¶�Ժ��С����,����������ˡ�
HF��Ϊţ�͵�����Ԫ��,��ȻҲ׼����һЩС��Ϸ������,�и���Ϸ��������:
����,��С������Χ��һ����Ȧ��Ȼ��,�����ָ��һ����m,�ñ��Ϊ0��С����
��ʼ������ÿ�κ���m-1���Ǹ�С����Ҫ���г��׸�,Ȼ���������Ʒ���������
��ѡ����,���Ҳ��ٻص�Ȧ��,��������һ��С���ѿ�ʼ,����0...m-1����....��
����ȥ....ֱ��ʣ�����һ��С����,���Բ��ñ���,�����õ�ţ������ġ�����
̽���ϡ���ذ�(��������Ŷ!!^_^)��������������,�ĸ�С���ѻ�õ������Ʒ
�أ�(ע��С���ѵı���Ǵ�0��n-1)

���û��С���ѣ��뷵��-1
*/

//������������������һ�ּ��㷨


#include <list>
using namespace std;
class Solution {
public:
	int LastRemaining_Solution(int n, int m)
	{
		if (n < 1 || m < 1) {
			return -1;
		}
		list<int> list;
		for (int i = 0; i < n; ++i) {
			list.push_back(i);
		}
		auto it = list.begin();
		while (list.size() > 1) {
			for (int i = 1; i < m; ++i) {
				it++;
				if (it == list.end()) {
					it = list.begin();
				}
			}
			auto next = ++it;
			if (next == list.end()) {
				next = list.begin();
			}
			it--;
			list.erase(it);
			it = next;
		}
		return *(it);
	}
};


class Solution1 {
public:
	int LastRemaining_Solution(int n, int m)
	{
		if (n < 1 || m < 1) {
			return -1;
		}
		int last = 0;
		for (int i = 2; i <= n; ++i) {
			last = (last + m) % i;
		}
		return last;
	}
};

int main()
{
	Solution s;
	int k = s.LastRemaining_Solution(5, 3);
	return 0;
}