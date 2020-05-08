/*
��Ŀ��Emacs������
��Ŀ����
Emacs�ų���ı༭�������Դ���һ������������������������ͬ��
���ǻ��ں�׺���ʽ�ģ���������ڲ������ĺ��档���硰2 3 +���ȼ�����׺���ʽ�ġ�2 + 3����
����ʵ��һ����׺���ʽ�ļ�������
��������:
��������������ݡ�

ÿ�����ݰ������У���һ����һ��������n (3��n��50)��
�����ŵڶ��а���n������ֵ���������ɵ��б�

��+- * /���ֱ�Ϊ�Ӽ��˳��������㣬���г���Ϊ����������5 / 3 = 1����
������� :
��Ӧÿһ�����ݣ�������ǵ���������
ʾ��1
����
����
3<br / >2 3 + <br / >5<br / >2 2 + 3 * <br / >5<br / >2 2 3 + *
���
����
5<br / >12<br / >10
*/

// write your code here cpp
// write your code here cpp
#include <iostream>
#include <string>
#include <stack>
using namespace std;


int main()
{
	int n;
	string str;
	stack<string> s;
	while (cin >> n) {
		cin.get();
		getline(cin, str);
		int end = (int)str.size() - 1;
		int begin = 0;
		int re = 0;
		bool istrue = true;
		while (begin <= end) {
			if (str[begin] == ' ') {
				begin++;
				continue;
			}
			else if (str[begin] >= '0' && str[begin] <= '9') {
				string num;
				while (begin <= end && str[begin] != ' ') {
					num += str[begin];
					begin++;
				}
				s.push(num);
			}
			else {
				if (str[begin] == '+') {
					string num1 = s.top();
					s.pop();
					string num2 = s.top();
					s.pop();
					re = atoi(num2.c_str()) + atoi(num1.c_str());
					s.push(to_string(re));
				}
				else if (str[begin] == '-') {
					string num1 = s.top();
					s.pop();
					string num2 = s.top();
					s.pop();
					re = atoi(num2.c_str()) - atoi(num1.c_str());
					s.push(to_string(re));
				}
				else if (str[begin] == '*') {
					string num1 = s.top();
					s.pop();
					string num2 = s.top();
					s.pop();
					re = atoi(num2.c_str()) * atoi(num1.c_str());
					s.push(to_string(re));
				}
				else {
					string num1 = s.top();
					s.pop();
					string num2 = s.top();
					s.pop();
					if (atoi(num1.c_str()) == 0) {
						istrue = false;
						break;
					}
					re = atoi(num2.c_str()) / atoi(num1.c_str());
					s.push(to_string(re));
				}
			}
			begin++;
		}
		if (istrue == true) {
			cout << atoi(s.top().c_str()) << endl;
			s.pop();
		}
		while (!s.empty()) {
			s.pop();
		}
	}
	return 0;
}