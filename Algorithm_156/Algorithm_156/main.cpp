/*
���ӣ�https://www.nowcoder.com/questionTerminal/34f17d5f2a8240bea661a23ec095a062?source=relative
��Դ��ţ����

�Ǽ�ս����չ��100��֮��NowCoder���������������˵����룡���ǵ�������һ��������
ͨ��һ�ű������Ϣӳ�������4λ���롣��Ĺ����ǣ�n��Ӧ��ֵ�Ǿ���X��n�η������Ͻǣ�
������������4λ����0��䣬�������4λ����ֻ������4λ��
|1 1|^n => |Xn ..|
|1 0|      |.. ..|
����n=2ʱ��
|1 1|^2 => |1 1| * |1 1| => |2 1|
|1 0|      |1 0|   |1 0|    |1 1|
��2��Ӧ�����ǡ�0002����

��������:
�����ж������ݡ�
ÿ���������У���һ�а���һ������n (1��n��100)���ڶ��а���n��������Xi (1��Xi��10000)


�������:
��Ӧÿһ�����룬���һ����Ӧ�����롣
ʾ��1
����
6<br/>18 15 21 13 25 27<br/>5<br/>1 10 100 1000 10000
���
418109877711037713937811<br/>00010089410135017501
*/

// write your code here cpp
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

vector<int> arr(10001);

class solution
{
public:
	void func()
	{
		arr[0] = 1;
		arr[1] = 1;
		arr[2] = 2;
		for (int i = 3; i <= 10000; ++i) {
			arr[i] = arr[i - 1] + arr[i - 2];
			if (arr[i] >= 10000) {
				arr[i] %= 10000;
			}
		}
		return;
	}
};

int main()
{
	solution ss;
	ss.func();
	int n;
	int scan;
	while (cin >> n) {
		for (int i = 0; i < n; ++i) {
			cin >> scan;
			cout << setfill('0') << setw(4) << arr[scan];
		}
		cout << endl;
	}
	return 0;
}