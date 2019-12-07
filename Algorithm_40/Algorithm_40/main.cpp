/*
���ӣ�https://www.nowcoder.com/questionTerminal/2d3f6ddd82da445d804c95db22dcc471?orderByHotValue=1&page=1&onlyReference=false
��Դ��ţ����

[�����]����������

ţţ��������������Ϊһ��������һ��������������,��������������Ƿǵ�������
�ǵݼ�����ġ�ţţ��һ������Ϊn����������A,��������һ�������ǰ�����A��Ϊ
���ɶ�����������,ţţ��֪�������ٿ��԰���������Ϊ��������������.
��������ʾ,ţţ���԰�����A����Ϊ[1,2,3]��[2,2,1]��������������,������Ҫ
����Ϊ2������������,�������2

��������:
����ĵ�һ��Ϊһ��������n(1 �� n �� 10^5)

�ڶ��а���n������A_i(1 �� A_i �� 10^9),��ʾ����A��ÿ�����֡�


�������:
���һ��������ʾţţ���Խ�A���ٻ���Ϊ���ٶ�����������

ʾ��1
����
6
1 2 3 2 2 1
���
2

*/

/*
˼·���Ƚ�prev=arr[0]��������������ʼcount=1
�������һ��������prev�������ѭ������������һ����С��ǰһ����ʱ�����˳�ѭ��
prev��Ϊ��ǰ�˳�ʱ��һ���Ƚ�С����
�������һ����С��prev�������ѭ������������һ�������ں�һ����ʱ�����˳�ѭ��
prev��Ϊ��ǰ�˳�ʱ��һ���Ƚϴ����
�������ȣ���ǰ��������λ������ƶ��Ƚ���һ��
*/


#include <iostream>
#include <vector>
using namespace std;

class subsequence
{
public:
	int get_subquence_count(vector<int>& arr)
	{
		size_t arr_size = arr.size();
		size_t i = 1;
		int count = 1;  //��ʼ����Ϊ1
		int prev = arr[0]; //�����һ����
		int next;
		while (i < arr_size) {
			next = arr[i]; 
			if (next > prev) {  //����ʱ����ѭ��
				for (; i < arr_size; ++i) {  
					if (arr[i] < arr[i - 1]) { //����С��ʱ�˳�������prev
						prev = arr[i];
						++count;        //������1
						break;
					}
				}
			}
			else if (next < prev) {     //С��ʱ����ѭ��
				for (; i < arr_size; ++i) {
					if (arr[i] > arr[i - 1]) {  //��������ʱ�˳�������prev
						prev = arr[i];
						++count;      //������1
						break;
					}
				}
			}
			else {
				++i; //���ʱ��������++��Ƚ���һ����
			}
		}
		return count;
	}
};


int main()
{
	subsequence s;
	int n;
	while (cin >> n) {
		vector<int> arr(n);
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}
		cout << s.get_subquence_count(arr) << endl;
	}
	return 0;
}