/*
��Ŀ����
�ҳ��ַ����е�һ��ֻ����һ�ε��ַ�

��������:
����һ���ǿ��ַ���

�������:
�����һ��ֻ����һ�ε��ַ���������������-1

ʾ��1
����
asdfasdfo

���
o
*/

//˼·������һ��255��С�����飬�ȱ�����һ�飬���ַ���ascll��С��Ϊ����
//�±꣬����һ���ַ������ַ���Ӧ�������±��ֵ��һ
//��һ�α������������ַ���Ӧ�����±��ֵΪһʱ�������û�У���� -1

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class once_char
{
public:
	string get_once(string str)
	{
		string s;
		vector<int> arr(255, 0);
		for (size_t i = 0; i<str.size(); ++i) {
			++arr[str[i]];
		}
		for (size_t i = 0; i<str.size(); ++i) {
			if (arr[str[i]] == 1){
				s.push_back(str[i]);
				return s;
			}
		}
		return "-1";
	}
};


int main()
{
	once_char o;
	string str;
	while (cin >> str) {
		cout << o.get_once(str) << endl;
	}
	return 0;
}