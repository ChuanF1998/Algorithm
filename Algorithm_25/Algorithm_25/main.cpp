/*
��Ŀ����
������һ�������⣺��ĳ�̵�涨����������ˮƿ���Ի�һƿ��ˮ��С��������ʮ������ˮƿ���������Ի�����ƿ
��ˮ�ȣ�������5ƿ���������£�����9����ƿ�ӻ�3ƿ��ˮ���ȵ�3ƿ���ģ������Ժ�4����ƿ�ӣ���3���ٻ�һƿ��
�ȵ���ƿ���ģ���ʱ��ʣ2����ƿ�ӡ�Ȼ�������ϰ��Ƚ����һƿ��ˮ���ȵ���ƿ���ģ������Ժ���3����ƿ�ӻ�һƿ
���Ļ����ϰ塣���С��������n������ˮƿ�������Ի�����ƿ��ˮ�ȣ�

��������:
�����ļ�������10��������ݣ�ÿ������ռһ�У�������һ��������n��1<=n<=100������ʾС�����ϵĿ���
ˮƿ����n=0��ʾ�����������ĳ���Ӧ��������һ�С�

�������:
����ÿ��������ݣ����һ�У���ʾ�����Ժȵ���ˮƿ�������һƿҲ�Ȳ��������0��

ʾ��1
����
3
10
81
0

���
1
5
40
*/

#include <iostream>
#include <vector>
using namespace std;

class soda_water_num
{
public:
	int get_soda_water_num(int empty_b)
	{
		int count = 0;
		int count1 = 0;
		int cy = 1;
		while (empty_b>2)  //Ϊʲô�Ǵ���2����Ϊ������1����ƿ�����
		{
			int rest_of_empty = empty_b % 3; //ʣ���ƿ
			count1 += (empty_b - rest_of_empty) / 3; //���εõ�����������
			count += count1;                      //�������ϱ��εõ�����������
			rest_of_empty += count1;             //ʣ���ƿ�ټ��ϱ������Ϻ����Ŀ�ƿ
			count1 = 0;                         //����������0��Ϊ��һ��ѭ����׼����һ��Ҫ��0����Ȼ�´κȵľͰ�����κȵģ����½������ȷ��
			if (rest_of_empty == 2){       //��ƿ��Ϊ2ʱ
				rest_of_empty += cy;       //�������̼ҽ�һƿ�������3����ƿһ��������ڵ��������һƿ
				count += 1;              
				rest_of_empty = 0;
			}
			empty_b = rest_of_empty;     

		}
		return count;
	}
};

int main()
{
	soda_water_num s;
	while (true) {
		vector<int> arr(10);
		for (int i = 0; i<10; ++i) {
			cin >> arr[i];
			if (arr[i] == 0){
				break;
			}
		}
		for (int i = 0; i<10; ++i) {
			if (arr[i] == 0){
				break;
			}
			else {
				cout << s.get_soda_water_num(arr[i]) << endl;
			}
		}
	}
	return 0;
}