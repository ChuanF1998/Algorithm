/*
��Ŀ����
����n��������������ִ������ڵ������鳤��һ�������
��������:
ÿ������������� n���ո�ָ��n��������n������100��������һ���������ִ������ڵ���n/2��
�������:
������ִ������ڵ���n/2������
ʾ��1
����
3 9 3 2 5 6 7 3 2 3 3 3

���
3
*/


#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int get_num(vector<int> arr)
	{
		int onehalf_num = arr[0];
		int count = 1;
		for (size_t i = 1; i < arr.size(); ++i) {
			if (onehalf_num = arr[i]) {
				count++;
			}
			else {
				count--;
				if (count == 0) {
					onehalf_num = arr[i];
					count++;
				}
			}
		}
		return onehalf_num;
	}
};



int main()
{
	Solution s;
	vector<int> arr;
	int k;
	while (cin >> k) {
		arr.push_back(k);
	}
	cout << s.get_num(arr) << endl;
	return 0;
}