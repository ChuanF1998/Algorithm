/*
��Ŀ���򵥴����¼
��Ŀ����
����һ���򵥴����¼����Сģ�飬�ܹ���¼����Ĵ������ڵ��ļ����ƺ��кš�


����


1�� ��¼���8�������¼��ѭ����¼������˵���ֻ��������ֵİ��������¼����
����ͬ�Ĵ����¼�����ļ������������16λ���ƺ��к���ȫƥ�䣩ֻ��¼һ��������������ӣ�


2�� ����16���ַ����ļ����ƣ�ֻ��¼�ļ��������Ч16���ַ���


3�� ������ļ����ܴ�·������¼�ļ����Ʋ��ܴ�·����


��������:
һ�л�����ַ�����ÿ�а�����·���ļ����ƣ��кţ��Կո������

�������:
�����еļ�¼ͳ�Ʋ�������������ʽ���ļ��� �������� ��Ŀ��һ���ո�������磺

ʾ��1
����
����
E:\V1R2\product\fpgadrive.c   1325
���
����
fpgadrive.c 1325 1
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string split(string& path)
{
	size_t pos = path.rfind('\\');
	string tmp = path.substr(pos + 1);
	if (tmp.size() > 16) {
		tmp = tmp.substr(tmp.size() - 16);
	}
	return tmp;
}

struct errlog
{
public:
	string _path;
	int _line;
	int _count;
public:
	bool operator==(const errlog& e)
	{
		if (e._path.compare(_path) == 0 && e._line == _line) {
			return true;
		}
		else {
			return false;
		}
	}
};

int main()
{
	string path;
	int line;
	vector<errlog> arr;
	while (cin >> path >> line) {
		errlog e;
		e._path = split(path);
		e._line = line;
		e._count = 1;
		auto res = find(arr.begin(), arr.end(), e);
		if (res == arr.end()) {
			arr.push_back(e);
		}
		else {
			res->_count++;
		}
	}
	for (size_t i = 0; i < arr.size(); ++i) {
		if (i + 8 >= arr.size()) {
			cout << arr[i]._path << " " << arr[i]._line << " " << arr[i]._count << endl;
		}
	}
	return 0;
}