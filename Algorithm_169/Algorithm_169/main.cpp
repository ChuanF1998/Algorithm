/*
��Ŀ�����ݿ����ӳ�
��Ŀ����
Webϵͳͨ����Ƶ���ط������ݿ⣬���ÿ�η��ʶ����������ӣ����ܻ�ܲ
Ϊ��������ܣ��ܹ�ʦ���������Ѿ����������ӡ����յ����󣬲������ӳ���û��
ʣ����õ�����ʱ��ϵͳ�ᴴ��һ�������ӣ������������ʱ�����ӻᱻ�������ӳ��У�����������ʹ�á�

�����ṩ�㴦���������־���������һ�����ӳ������Ҫ�������ٸ����ӡ�
��������:
��������������ݣ�ÿ�����ݵ�һ�а���һ��������n��1��n��1000������ʾ�����������

������n�У�ÿ�а���һ��������id��A��B��C������Z���Ͳ�����connect��disconnect����
�������:
��Ӧÿһ�����ݣ�������ӳ������Ҫ�������ٸ����ӡ�
ʾ��1
����
����
6<br/>A connect<br/>A disconnect<br/>B connect<br/>C connect<br/>B disconnect<br/>C disconnect
���
����
2
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> arr(127, 0);

int main()
{
	int n;
	char id;
	string command;
	while (cin >> n) {
		int can_use = 0;
		int need = 0;
		for (int i = 0; i < n; ++i) {
			cin >> id >> command;
			if (command == "connect") {
				if (can_use > 0) {
					can_use -= 1;
					arr[id] += 1;
				}
				else {
					need += 1;
					arr[id] += 1;
				}
			}
			if (command == "disconnect") {
				if (arr[id] >= 1) {
					can_use += 1;
					arr[id] -= 1;
				}
			}
		}
		cout << need << endl;
	}
	return 0;
}