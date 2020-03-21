/*
��Ŀ����
ͳ��һ�����������������г��ֵĴ�����
*/

//����������õݹ飬����Խ���ݹ�Խ����

#include <vector>
using namespace std;
class Solution {
public:
	int GetNumberOfK(vector<int> data, int k) {
		int right = (int)data.size();
		int min = right;
		int max = -1;
		func(data, k, 0, right - 1, min, max);
		return (max - min) >= 0 ? (max - min + 1) : 0;
	}

	void func(vector<int>& arr, int k, int left, int right, int& min, int& max)
	{
		if (left > right) {
			return;
		}
		int middle = (left + right) >> 1;
		if (arr[middle] == k) {
			if (middle <= min) {
				min = middle;
			}
			if (middle >= max) {
				max = middle;
			}
		}
		if (arr[middle] >= k) {
			func(arr, k, left, middle - 1, min, max);
		}
		if (arr[middle] <= k) {
			func(arr, k, middle + 1, right, min, max);
		}
		return;
	}
};

int main()
{
	return 0;
}