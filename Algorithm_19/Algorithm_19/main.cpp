/*
��Ŀ����
��ȫ����Perfect number�����ֳ����������걸������һЩ�������Ȼ����

�����е������ӣ����������������Լ�����ĺͣ������Ӻ�������ǡ�õ���������

���磺28������Լ��1��2��4��7��14��28����ȥ������28�⣬����5������ӣ�1+2+4+7+14=28��

��������count(int n),���ڼ���n����(��n)��ȫ���ĸ��������㷶Χ, 0 < n <= 500000

����n������ȫ���ĸ����� �쳣�������-1

��������:
����һ������

������� :
�����ȫ���ĸ���

ʾ��1
����
1000

���
3
*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class perfect_num
{
public:
	int get_perfect_num(int n)
	{
		int count = 0;
		if (n == 1) {
			return 0;
		}
		for (int i = 2; i <= n; ++i) {
			if (is_perfect(i)){
				++count;
			}
		}
		return count;
	}
	//�ж��Ƿ�����ȫ��
	bool is_perfect(int n)
	{
		int divisor = 1;
		vector<int> arr;
		get_divisor(n, arr);   //�õ����������1�ͱ���������
		for (int i = 0; i<arr.size(); ++i) {
			divisor += arr[i];    //���
		}
		if (divisor == n) {
			return true;
		}
		else {
			return false;
		}
	}

	void get_divisor(int n, vector<int>& arr)
	{
		double n_sqrt = sqrt(n);
		for (int i = 2; i <= n_sqrt; ++i) {
			if (n%i == 0) {
				arr.push_back(i);
				if ((n / i) != i) {
					arr.push_back(n / i);
				}
			}
		}
	}
};

int main()
{
	perfect_num p;
	int n;
	while (cin >> n) {
		cout << p.get_perfect_num(n) << endl;
	}
	return 0;
}