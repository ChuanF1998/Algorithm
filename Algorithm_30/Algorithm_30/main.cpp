/*
��Ŀ����
MP3 Player��Ϊ��Ļ��С����ʾ�����б��ʱ��ÿ��ֻ����ʾ���׸������û�Ҫͨ��
���¼�����������еĸ�����Ϊ�˼򻯴�������ÿ��ֻ����ʾ4�׸���������ʼ��
λ��Ϊ��1�׸衣

����Ҫʵ��ͨ�����¼����ƹ���ƶ�����������б������߼����£�

��������<=4��ʱ�򣬲���Ҫ��ҳ��ֻ��Ų�����λ�á�

����ڵ�һ�׸�����ʱ����Up�����Ų�����һ�׸�������������һ�׸���ʱ��
��Down�����Ų����һ�׸�����

����������û���Up�������Ų����һ�׸������û���Down�������Ų����һ�׸�����



2. ������������4��ʱ����һ����10�׸�Ϊ������

���ⷭҳ����Ļ��ʾ���ǵ�һҳ������ʾ��1 �C 4�ף�ʱ������ڵ�һ�׸����ϣ�
�û���Up������ĻҪ��ʾ���һҳ������ʾ��7-10�׸裩��ͬʱ���ŵ����һ
�׸��ϡ�ͬ���ģ���Ļ��ʾ���һҳʱ����������һ�׸����ϣ��û���Down������
ĻҪ��ʾ��һҳ�����Ų����һ�׸��ϡ�

һ�㷭ҳ����Ļ��ʾ�Ĳ��ǵ�һҳʱ������ڵ�ǰ��Ļ��ʾ�ĵ�һ�׸���ʱ���û�
��Up������Ļ�ӵ�ǰ��������һ�׿�ʼ��ʾ�����ҲŲ����һ�׸�������굱ǰ
��Ļ�����һ�׸�ʱ��Down������Ҳ���ơ�

������������÷�ҳ��ֻ��Ų�������С�

��������:
����˵����
1 �����������
2 �������� U����D

�������:
���˵��
1 �����ǰ�б�
2 �����ǰѡ�и���

ʾ��1
����
10
UUUU

���
7 8 9 10
7
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class music_page
{
public:
	int get_music(int n, string options, vector<int>& arr)
	{
		int cursor = 1; //��ʼ���Ϊ1
		int option_size = options.size();
		//��������С�ڵ���4��ֻ���ƶ����
		if (n<5) {   
			for (int i = 1; i <= n; ++i) {
				arr.push_back(i);
			}
			for (int i = 0; i<option_size; ++i) {
				if (options[i] == 'D'){
					if (cursor == n) { //�����nʱ������������1�����������1
						cursor = 1;
					}
					else {
						++cursor;
					}
				}
				if (options[i] == 'U'){
					if (cursor == 1){ //�����1ʱ������������n�����������1
						cursor = n;
					}
					else {
						--cursor;
					}
				}
			}
		}
		else {
			for (int i = 1; i<5; ++i) { //���ó�ʼ1��2��3��4
				arr.push_back(i);
			}
			for (int i = 0; i<option_size; ++i) {
				if (options[i] == 'D'){
					if (cursor == n){  //�����nʱ������������1���������¸�ֵ
						cursor = 1;
						arr.clear();
						for (int j = 0; j<4; ++j) {
							arr.push_back(j + 1);
						}
					}
					else{              //���������1
						++cursor;
						if (cursor>arr.back()){  //������С�����������һ��ֵ��С��ɾ����һ��
							arr.erase(arr.begin());
							arr.push_back(cursor); //�����ʱ�Ĺ��
						}
					}

				}
				if (options[i] == 'U'){
					if (cursor == 1){    //�����1ʱ������������n���������¸�ֵ
						cursor = n;
						arr.clear();
						for (int j = 3; j >= 0; --j) {
							arr.push_back(n - j);
						}
					}
					else {             //���������1
						--cursor;
						if (cursor<arr.front()){ //������С���������һ��ֵ��С��ɾ�����һ��
							arr.pop_back();
							arr.insert(arr.begin(), cursor); //�����ʱ�Ĺ��
						}
					}
				}
			}
		}
		return cursor;
	}
};


int main()
{
	music_page m;
	int n;
	string str;
	while (cin >> n >> str) {
		vector<int> arr;
		int cursor = m.get_music(n, str, arr);
		for (int i = 0; i<arr.size(); ++i) {
			cout << arr[i] << " ";
		}
		cout << endl;
		cout << cursor << endl;
	}
	return 0;
}