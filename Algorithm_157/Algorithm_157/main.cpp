/*
��Ŀ����
С���Ǻ�ϲ�����Լ�װ��������ģ������룩������Ҫ������ܳ������������̣����Ǿͽ���ȥ�ˡ�

���ڸ��������ǵ���������İ뾶�����ж�һ���ܷ�����ȥ��
��������:
�����ж������ݡ�

ÿ�����ݰ�����������n (1��n��2^128) ��r (1��r��2^128)���ֱ��������������İ뾶��

Բ����ʹ��3.14��
�������:
��Ӧÿһ�����ݣ��������װ������������Yes�������������No����
ʾ��1
����
����
6 1<br/>7 1<br/>9876543210 1234567890
���
����
Yes<br/>No<br/>No
*/

#include <iostream>
#include <string>
using namespace std;

class solution
{
public:
	string Get(string& s1, string& s2)
	{
		//string s3 = (s2.size(), '0');
		string s3;
		strSum(s2, s3, 628);
		if (s3.size() > s1.size() + 2) {
			return "Yes";
		}
		else if (s3.size() == s1.size() + 2) {
			return s3.compare(s1 + "00") >= 0 ? "Yes" : "No";
		}
		else {
			return "No";
		}
	}

	void strSum(string& str, string& s3, int num)
	{
		string tmp;
		int cy = 0;  //��λ
		int times = 0;
		while (num > 0) {
			int k = num % 10;
			tmp = str;
			//���ÿһλ���׼�ַ����ĳ˻�������Ჹλ��ʮλ��һ��0����λ��2��0
			for (int i = (int)tmp.size() - 1; i >= 0; --i) {
				int pro = (tmp[i] - '0') * k + cy;
				tmp[i] = pro % 10 + '0';
				cy = pro / 10;
			}
			if (cy > 0) {
				tmp.insert(tmp.begin(), cy + '0');
			}
			cy = 0;
			num /= 10;
			//��λ
			for (int i = 0; i < times; ++i) {
				tmp += "0";
			}
			//���
			int end = tmp.size() - 1;
			for (int i = s3.size() - 1; i >= 0; --i) {
				int pro = tmp[end] - '0' + s3[i] - '0' + cy;
				tmp[end] = pro % 10 + '0';
				cy = pro / 10;
				end--;
			}
			for (int i = end; i >= 0; --i) {
				int pro = tmp[end] - '0' + cy;
				tmp[end] = pro % 10 + '0';
				cy = pro / 10;
				end--;
			}
			if (cy > 0) {
				tmp.insert(tmp.begin(), cy + '0');
			}
			times += 1;
			s3 = tmp;
			cy = 0;
		}
		return;
	}
};

int main()
{
	solution ss;
	string s1;
	string s2;
	while (cin >> s1 >> s2) {
		cout << ss.Get(s1, s2) << endl;
	}
	return 0;
}