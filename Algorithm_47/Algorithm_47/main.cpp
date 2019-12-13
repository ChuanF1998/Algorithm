/*
��Ŀ����
����С����һ��W*H��������ӣ�������б��Ϊ0~H-1��������б��Ϊ0~W-1��
ÿ������������Է�һ�鵰�⣬�������鵰���ŷ����þ��벻�ܵ���2��
����������������(x1,y1),(x2,y2)��ŷ����þ���Ϊ:
( (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2) ) ������ƽ����
С����֪�������ԷŶ��ٿ鵰������������
��������:
ÿ������������񳤿�W,H���ÿո�ָ�.(1 �� W��H �� 1000)
�������:
���һ�������Էŵĵ�����

ʾ��1
����
3 2

���
4
*/




#include <iostream>
#include <vector>
using namespace std;

class solution
{
public:
	int get_max_cake(int w, int h, vector<vector<int> >& arr)
	{
		int count = 0;
		//vector<vector<int> > arr(w, vector<int>(h,0));
		for (int i = 0; i < w; ++i) {
			for (int j = 0; j < h; ++j) {
				if (arr[i][j] == 0) {
					arr[i][j] = 1;
					++count;
					if (i + 2 < w) {
						arr[i + 2][j] = -1;
					}
					if (j + 2 < h) {
						arr[i][j + 2] = -1;
					}
				}
			}
		}
		return count;
	}
};


int main()
{
	solution s;
	int w, h;
	vector<vector<int> >arr;
	while (cin >> w >> h) {
		arr.resize(w);
		for (auto& e : arr)
			e.resize(h, 0);
		cout << s.get_max_cake(w, h, arr) << endl;
		arr.clear();
	}
	return 0;
}