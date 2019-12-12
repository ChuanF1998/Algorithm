/*
��Ŀ����
һ�������� N ��Ԫ�أ�����������������͡� ���磺[-1,2,1]������
�������������Ϊ[2,1]�����Ϊ 3
��������:
����Ϊ���С� ��һ��һ������n(1 <= n <= 100000)����ʾһ����n��Ԫ�� 
�ڶ���Ϊn��������ÿ��Ԫ��,ÿ����������32λint��Χ�ڡ��Կո�ָ���

�������:
���������������к�����ֵ��
ʾ��1
����
3 -1 2 1

���
3
*/



#include <iostream>
#include <vector>
using namespace std;

class continue_arr
{
public:
	int get_max(vector<int>& arr)
	{
		int min_count = 0;
		int max_count = arr[0];
		size_t arr_size = arr.size();
		for (size_t i = 0; i < arr_size; ++i) {
			if (arr[i] >= 0) {
				min_count += arr[i];
				if (min_count > max_count) {
					max_count = min_count;
				}
			}
			else {
				min_count += arr[i];
				if (min_count < 0) {
					if (min_count > max_count) {
						max_count = min_count;
					}
					min_count = 0;
				}
			}
		}
		return max_count;
	}
};

int main()
{
	continue_arr c;
	int n;
	while (cin >> n) {
		vector<int> arr(n);
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}
		cout << c.get_max(arr) << endl;
	}
	return 0;
}