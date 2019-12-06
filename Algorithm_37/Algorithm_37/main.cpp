/*
���ӣ�https://www.nowcoder.com/questionTerminal/6736cc3ffd1444a4a0057dee89be789b?orderByHotValue=1&page=1&onlyReference=false
��Դ��ţ����

ţţ�ٰ���һ�α�̱���,�μӱ�������3*n��ѡ��,ÿ��ѡ�ֶ���һ��
ˮƽֵa_i.����Ҫ����Щѡ�ֽ������,һ�����n������,��ÿ������3��
.ţţ���ֶ����ˮƽֵ���ڸö����Ա�еڶ���ˮƽֵ��
����:
һ������������Ա��ˮƽֵ�ֱ���3,3,3.��ô�����ˮƽֵ��3
һ������������Ա��ˮƽֵ�ֱ���3,2,3.��ô�����ˮƽֵ��3
һ������������Ա��ˮƽֵ�ֱ���1,5,2.��ô�����ˮƽֵ��2
Ϊ���ñ������п���,ţţ�밲�Ŷ���ʹ���ж����ˮƽֵ�ܺ����
��������ʾ:
���ţţ��6����Ա���ֵ���������
�������Ϊ:
team1:{1,2,5}, team2:{5,5,8}, ��ʱ��ˮƽֵ�ܺ�Ϊ7.
���������Ϊ:
team1:{2,5,8}, team2:{1,5,5}, ��ʱ��ˮƽֵ�ܺ�Ϊ10.
û�б��ܺ�Ϊ10����ķ���,�������10.

��������:
����ĵ�һ��Ϊһ��������n(1 �� n �� 10^5)

�ڶ��а���3*n������a_i(1 �� a_i �� 10^9),��ʾÿ������ѡ�ֵ�ˮƽֵ.


�������:
���һ��������ʾ���ж����ˮƽֵ�ܺ����ֵ.
ʾ��1
����
2
5 2 8 5 1 5
���
10
*/




#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class solution
{
public:
	long long get_maxlevel(vector<int> arr, int n)
	{
		long long max_count = 0;
		sort(arr.begin(), arr.end());
		for (size_t i = n; i < arr.size(); i += 2) {
			max_count += arr[i];
		}
		return max_count;
	}
};

int main()
{
	solution s;
	int n;
	while (cin >> n) {
		vector<int> arr(n * 3);
		for (int i = 0; i < n * 3; ++i) {
			cin >> arr[i];
		}
		cout << s.get_maxlevel(arr, n) << endl;
	}
	return 0;
}