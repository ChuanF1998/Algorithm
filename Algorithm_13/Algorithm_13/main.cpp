//��������
/*
��Ŀ����
�������������������

xcopy /s c:\ d:\��

�����������£�

����1��������xcopy

����2���ַ���/s

����3���ַ���c:\

����4: �ַ���d:\

���дһ��������������ʵ�ֽ������и�����������������



��������

1.�����ָ���Ϊ�ո�
2.�����á������������Ĳ���������м��пո񣬲��ܽ���Ϊ�������������������������xcopy /s ��C:\program files�� ��d:\��ʱ��������Ȼ��4������3������Ӧ�����ַ���C:\program files��������C:\program��ע���������ʱ����Ҫ������ȥ�������Ų�����Ƕ�������
3.����������
4.������������֤��������ֲ�����Ҫ�������




��������:
����һ���ַ����������пո�

�������:
��������������ֽ��Ĳ�����ÿ����������ռһ��

ʾ��1
����
xcopy /s c:\\ d:\\

���
4
xcopy
/s
c:\\
d:\\
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class string_segmentation
{
public:
	void Get_string(string str)
	{
		int count = 0;
		vector<string> arr;
		string temp;
		auto first = str.begin();
		auto last = str.end();
		while (first != last) {
			if (*first != '"') {
				while (*first != ' ' && first != last) {
					temp.push_back(*first);
					first++;
				}
				count++;
				arr.push_back(temp);
				temp.clear();
			}
			else {
				while (*(first + 1) != '"' && first != last) {
					temp.push_back(*first);
					first++;
				}
				count++;
				arr.push_back(temp);
				temp.clear();
			}
			if (first != last){
				++first;
			}
		}
		cout << count << endl;
		for (size_t i = 0; i<arr.size(); ++i) {
			cout << arr[i] << endl;
		}
	}
};


int main()
{
	string_segmentation s;
	string str;
	while (getline(cin, str)) {
		s.Get_string(str);
	}
	return 0;
}