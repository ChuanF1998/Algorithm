/*
Fibonacci��������������ģ�
F[0] = 0
F[1] = 1
for each i �� 2: F[i] = F[i-1] + F[i-2]
��ˣ�Fibonacci���о����磺0, 1, 1, 2, 3, 5, 8, 13, ...��
��Fibonacci�����е������ǳ�ΪFibonacci��������һ��N������
�����Ϊһ��Fibonacci����ÿһ������԰ѵ�ǰ����X��ΪX-1
����X+1�����ڸ���һ����N��������Ҫ���ٲ����Ա�ΪFibonacci��

��������:
����Ϊһ��������N(1 �� N �� 1,000,000)

�������:
���һ����С�Ĳ�����ΪFibonacci��"
*/



#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int Get_min_step(vector <int> arr, int num)
	{
		int step = 0;
		int k = 0;
		size_t n = arr.size();
		for (size_t i = 0; i<n; ++i) {
			if (arr[i] >= num){   //һ������������ĳ�������������ʱ
				k = i;         //�˳��������������±�
				break;
			}
		}
		int temp = num;
		if (temp == arr[k]) {  //���ֱ�ӷ���0
			return 0;
		}
		while (temp > arr[k - 1]) { //������ͬʱ��¼����
			--temp;
			step++;
		}
		int miror = arr[k] - arr[k - 1];
		if (step < miror / 2) {  //�жϣ�С��1/2ʱ�˳�
			return step;
		}
		else{
			return miror - step;
		}
	}
};

int main()
{
	//����һ��Fibonacci����
	vector<int> arr;
	arr.push_back(0);
	arr.push_back(1);
	int i = 1;
	while (arr[i] < 1000000) {
		int value1 = arr[i];
		int value2 = arr[i - 1];
		arr.push_back(value1 + value2);
		++i;
	}
	int n;
	Solution s;
	while (cin >> n) {
		cout << s.Get_min_step(arr, n) << endl;
	}
	return 0;
}