/*
��Ŀ����������
��Ŀ����
һ�黨������������Щͼ��������һ��ֱ�ӿ��õ�С����������Ҳ��һЩͼ����
���ڸ����Ļ�������С����������һ���ܴӻ������о����ܼ�������С�������أ�
��������:
��������������ݡ�

ÿ�����ݰ��������ַ���s,t���ֱ��ǳɶԳ��ֵĻ�������С�������䲼����
���ÿɼ�ASCII�ַ���ʾ�ģ��ɼ���ASCII�ַ��ж��ٸ��������Ļ���Ҳ�ж����ֻ�������������С�������ᳬ��1000���ַ�����
�������:
��Ӧÿ�����룬����ܴӻ��Ʋ��м��������С�������������һ�鶼û�У��Ǿ����0��ÿ�����ռһ�С�
ʾ��1
����
����
abcde a3<br/>aaaaaa aa
���
����
0<br/>3
*/
// write your code here cpp
#include <iostream>
#include <string>
using namespace std;

class solution
{
public:
	int Get(string& s, string& t)
	{
		if (s.size() == 0 && t.size() == 0) {
			return 0;
		}
		int count = 0;
		int s_size = s.size();
		int t_size = t.size();
		size_t pos = 0;
		size_t begin = 0;
		do {
			pos = s.find(t, begin);
			if (pos != string::npos) {
				count += 1;
				begin = pos + t_size;
			}
		} while (pos != string::npos);
		return count;
	}
};

int main()
{
	solution ss;
	string s;
	string t;
	while (cin >> s >> t) {
		cout << ss.Get(s, t) << endl;
	}
	return 0;
}