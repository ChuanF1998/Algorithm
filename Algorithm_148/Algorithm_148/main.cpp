

#include <iostream>
#include <vector>
using namespace std;

class solution
{
public:
	int GetInterest(vector<vector<int> >& arr, int k)
	{
		if (arr.size() == 0) {
			return 0;
		}
		int valOf01 = 0;    //K�������ܺ�
		int valOf1 = 0;     //k�������ѵ������ܺ�
		int valOf0 = 0;      //k����˯�����ܺ�
		int max_val = -1;    //����˯��ֵ���
		int standard = 0;  //���ѵ��ܴ�С
		int single = k - 1;
		size_t i = 0;
		size_t size = arr[0].size();
		while (i < size) {
			//��һ����ֱ���ж�ǰ K-1 ����,����ִֻ��һ��
			while (i < size && single > 0) {
				if (arr[1][i] == 1) {
					standard += arr[0][i];
					valOf1 += arr[0][i];
				}
				valOf01 += arr[0][i];
				i++;
				single--;
			}
			//һ�μ�һ���������K��
			valOf01 += arr[0][i];
			if (arr[1][i] == 1) {
				standard += arr[0][i];
				valOf1 += arr[0][i];
			}
			//k������˯����ֵ
			valOf0 = valOf01 - valOf1;
			//����˯��ֵ���
			if (valOf0 > max_val) {
				max_val = valOf0;
			}
			//��ԭ��k - 1�������Ա��´α���
			valOf01 -= arr[0][i - k + 1];
			if (arr[1][i - k + 1] == 1) {
				valOf1 -= arr[0][i - k + 1];
			}
			//�±��1
			i++;
		}
		return standard + max_val;
	}
};
int main()
{
	solution s;
	int n;
	int k;
	while (cin >> n >> k) {
		vector<vector<int> > arr(2, vector<int>(n, 0));
		for (int i = 0; i < n; ++i) {
			cin >> arr[0][i];
		}
		for (int i = 0; i < n; ++i) {
			cin >> arr[1][i];
		}
		cout << s.GetInterest(arr, k) << endl;
	}
	return 0;
}