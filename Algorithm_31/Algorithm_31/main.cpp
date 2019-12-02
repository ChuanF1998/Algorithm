/*
��Ŀ����
С�׾���������������Ϸ.��һ��,������һ�������������Ϸ,���Ľ�ɫ�ĳ�ʼ
����ֵΪ a.�ڽ�������һ��ʱ����,��������������n������,ÿ������ķ�����
Ϊb1,b2,b3...bn. ��������Ĺ��������biС�ڵ���С�׵ĵ�ǰ����ֵc,��ô
���������ɴ�ܹ���,�� ��ʹ���Լ�������ֵ����bi;���bi����c,����Ҳ�ܴ�
�ܹ���,����������ֵֻ������bi ��c�����Լ��.��ô��������,��һϵ�еĶ�
����,С�׵���������ֵΪ����?

��������:
����ÿ������,��һ������������n(1��n<100000)��ʾ�����������a��ʾС�׵�
��ʼ����ֵ.

�ڶ���n������,b1,b2...bn(1��bi��n)��ʾÿ������ķ�����

�������:
����ÿ������,���һ��.ÿ�н�����һ������,��ʾС�׵���������ֵ
ʾ��1
����
3 50
50 105 200
5 20
30 20 15 40 100

���
110
205

*/


#include <iostream>
#include <vector>
using namespace std;

class ability_value
{
public:
	int get_ability(vector<int>& arr, int n)
	{
		int value = n;
		for (size_t i = 0; i<arr.size(); ++i) {
			if (value >= arr[i]) {
				value += arr[i];
			}
			else {
				value += get_maxdivisor(arr[i], value);
			}
		}
		return value;
	}
	//շת����������Լ��
	int get_maxdivisor(int x, int y)
	{
		int divisor;
		while (x>y) {
			divisor = x%y;
			if (divisor == 0) {
				divisor = y;
				break;
			}
			if (divisor == 1) {
				divisor = 1;
				break;
			}
			x = y;
			y = divisor;
		}
		return divisor;
	}
};


int main()
{
	ability_value s;
	int n, a;
	while (cin >> n >> a) {
		vector<int> arr(n);
		for (int i = 0; i<n; ++i) {
			cin >> arr[i];
		}
		cout << s.get_ability(arr, a) << endl;
	}
	return 0;
}