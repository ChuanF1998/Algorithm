/*
��Ŀ����
ϴ����������ʮ�ֳ�����������Ҫдһ������ģ��ϴ�ƵĹ��̡� ������Ҫϴ2n���ƣ����ϵ��������ǵ�1�ţ���2�ţ���3��һֱ����2n�š����ȣ����ǰ���2n���Ʒֳ����ѣ��������ŵ�1�ŵ���n�ţ��ϰ�ѣ����������ŵ�n+1�ŵ���2n�ţ��°�ѣ������žͿ�ʼϴ�ƵĹ��̣��ȷ������ֵ����һ���ƣ��ٷ������ֵ����һ���ƣ����ŷ������ֵĵ����ڶ����ƣ��ٷ������ֵĵ����ڶ����ƣ�ֱ�����������ֵĵ�һ���ơ����Ű��ƺϲ������Ϳ����ˡ� ������6���ƣ��ʼ�Ƶ�������1,2,3,4,5,6�����ȷֳ����飬��������1,2,3����������4,5,6����ϴ�ƹ����а�˳�������6,3,5,2,4,1�������������ٴκϳ�һ����֮�����ǰ��մ������µ�˳�������ƣ��ͱ��������1,4,2,5,3,6�� ���ڸ���һ��ԭʼ���飬������⸱��ϴ��k��֮��������µ����С�
��������:
��һ��һ����T(T �� 100)����ʾ��������������ÿ�����ݣ���һ��������n,k(1 �� n,k �� 100)��������һ����2n����a1,a2,...,a2n(1 �� ai �� 1000000000)����ʾԭʼ������ϵ��µ����С�
�������:
����ÿ�����ݣ����һ�У����յ����С�����֮���ÿո��������Ҫ����ĩ�������Ŀո�
ʾ��1
����
3 3 1 1 2 3 4 5 6 3 2 1 2 3 4 5 6 2 2 1 1 1 1

���
1 4 2 5 3 6 1 5 4 3 2 6 1 1 1 1
*/


//�����뵽�ķ��������뷨
#include <iostream>
#include <vector>
using namespace std;

class poker_sequence
{
public:
	void get_poker_sequence(vector<int>& arr, int n, int k)
	{
		for (int i = 0; i<k; ++i) {
			vector<int> arr1(arr.begin(), arr.begin() + n);
			vector<int> arr2(arr.begin() + n, arr.end());
			arr.clear();
			for (int j = 0; j<n; ++j) {
				arr.push_back(arr1[j]);
				arr.push_back(arr2[j]);
			}
		}
	}
};


int main()
{
	poker_sequence p;
	int T;
	int n, k;
	while (cin >> T) {
		for (int i = 0; i<T; ++i) {
			cin >> n >> k;
			vector<int> arr(2 * n);
			for (int j = 0; j<2 * n; ++j) {
				cin >> arr[j];
			}
			p.get_poker_sequence(arr, n, k);
			for (int e = 0; e<2 * n - 1; ++e) {
				cout << arr[e] << " ";
			}
			cout << arr[2 * n - 1] << endl;
		}
	}
	return 0;
}



#if 0
//ֱ���������н���
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int T, n, k;
	cin >> T;
	while (T--)
	{
		cin >> n >> k;
		int num = 2 * n;
		vector<int> table(num);
		for (int i = 0; i < num; ++i)
			cin >> table[i];
		//ϴk����
		while (k--)
		{
			vector<int> n1(table.begin(), table.end());
			for (int i = 0; i < n; ++i)
			{
				//�����ǰ��С�ڵ���n���������֣��������´γ��ֵ�λ���� 2*��ǰλ��
				//��֮��Ӧ�ĵ�ǰλ�� + n���������֣�����,�����´γ��ֵ�λ���� 2*��ǰλ�� + 1
				table[2 * i] = n1[i];
				table[2 * i + 1] = n1[i + n];
			}
		}
		for (int i = 0; i < num - 1; ++i)
			cout << table[i] << " ";
		cout << table[num - 1] << endl;
	}
	return 0;
}

#endif