/*
��Ŀ����
�����������ڼ�����У�ͨ���һ�������﷨���㷺Ӧ�����ļ����������ݿ⡢������ʽ������
��Ҫ���λʵ���ַ���ͨ������㷨��
Ҫ��
ʵ������2��ͨ�����
*��ƥ��0�������ϵ��ַ����ַ���Ӣ����ĸ������0-9��ɣ������ִ�Сд����ͬ��
����ƥ��1���ַ�


���룺
ͨ������ʽ��
һ���ַ�����


�����
����ƥ��Ľ������ȷ���true���������false

��������:
������һ������ͨ������ַ�����������һ����Ҫƥ����ַ���

�������:
����ƥ��Ľ������ȷ���true���������false

ʾ��1
����
te?t*.*
txt12.xls

���
false
*/

/*�����������е����룬����˵˵�ǵݹ��������ҵ�˼·�����ǣ�ͨ�� * �� �� �� . ��ͨ���ַ���
�ֳ�һ�����ִ���������һ���ִ������� * �ž����һ���ִ�����ʾ��1����Ϊ���� te  ? t ��
Ȼ����Щ�ִ���˳��һ��Ҫ��˳������ͨ�ַ������бȽϣ�������һ������λflag=0��������������flag�����ַ�����Ϊ *
��Ϊʲô����Ϊ*�ţ���Ϊ*��ͨ��ģ���Ӱ������ȽϽ��������ͨ�ִ�Ҳ����ͨ�ַ������бȽϣ����ִ�����ͨ�ַ���ƥ�����ˣ�
������ͨ�ַ����н����ִ���ͬ����������Ϊ * ��flag����Ϊ*��λ��+1����ƥ�䲻�ϣ�return false ���ִ�������ȫ��return true��

��һ�����Ӻ���⣺ͨ�� abc��qwe*rr*.*uu -> �ִ� abc �� qwe rr uu����ͨ�ַ��� abcrqwetttrr.uu
Ȼ���������һ�Σ�abcƥ������ --�� ***rqwetttrr.uu ��flagλ��Ϊ r ���λ��
          �ڶ��Σ��� ---��****qwetttrr.uu ,flag����Ϊ q ���λ��
		  �����Σ�qwe ƥ������ --��*******tttrr.uu ,flag����Ϊ t ���λ��
		  .....
		  ֱ���ִ�������
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class str_matching
{
public:
	string str_ismatching(string str1, string str2)
	{
		vector<string> arr;
		auto str1_first = str1.begin();
		auto str1_last = str1.end();
		auto temp = str1_first;
		while (str1_first != str1_last) {
			if (*str1_first == '?' || *str1_first == '*' || *str1_first == '.') {
				if (*temp == '*' || *temp == '.'){
					temp++;
					str1_first++;
				}
				else if (*temp == '?') {
					string str(temp, str1_first + 1);
					arr.push_back(str);
					temp = str1_first + 1;
					str1_first++;
				}
				else{
					string str(temp, str1_first);
					arr.push_back(str);
					temp = str1_first + 1;
					str1_first++;
				}
			}
			else {
				str1_first++;
			}
		}
		if (str1_first>temp){
			string str3(temp, str1_first);
			arr.push_back(str3);
		}
		size_t str2_length = str2.size();
		size_t k = 0;
		for (size_t i = 0; i<arr.size(); ++i){
			if (arr[i] == "?"){
				str2.replace(k, 1, 1, '*');
			}
			else {
				size_t pos = str2.find(arr[i]);
				if (pos == string::npos) {
					return "false";
				}
				else {
					str2.replace(pos, arr[i].size(), arr[i].size(), '*');
					k = pos + arr[i].size() + 1;
				}
			}
		}
		return "true";
	}
};


int main()
{
	str_matching s;
	string str1, str2;
	while (cin >> str1 >> str2) {
		cout << s.str_ismatching(str1, str2) << endl;
	}
	return 0;
}



#if 0

//�ݹ�����,������벻����
#include <iostream>
#include <string>
using namespace std;
bool match(const char* pattern, const char *str)
{
	//��ǰ�ַ�����������true
	if (*pattern == '\0' && *str == '\0')
		return true;
	//�����ַ�����һ���Ƚ������򷵻�false
	if (*pattern == '\0' || *str == '\0')
		return false;
	if (*pattern == '?')
	{
		//����?�ţ�ƥ��һ���ַ�������һ��λ��
		return match(pattern + 1, str + 1);
	}
	else if (*pattern == '*')
	{
		// ����*�ţ�ƥ��0��(str��Ų��)��1�������߶���ǰŲ��һ���ַ�������(str��ǰŲ��һ���ַ�)
		return match(pattern + 1, str) || match(pattern + 1, str + 1) || match(pattern, str + 1);
	}
	else if (*pattern == *str)
	{
		//�����ǰ�ַ���ȣ�ƥ����һ���ַ�
		return match(pattern + 1, str + 1);
	}
	return false;
}
int main()
{
	string pattern, str;
	while (cin >> pattern >> str)
	{
		bool ret = match(pattern.c_str(), str.c_str());
		if (ret)
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
	cout << "false" << endl;
	return 0;
}

#endif