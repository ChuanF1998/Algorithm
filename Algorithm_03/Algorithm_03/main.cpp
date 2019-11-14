/*
��Ŀ����
������n���ַ����ַ��������������ַ������ȶ��ǲ�ͬ�ġ��������ѧϰ���������ַ��������򷽷��� 1.�����ַ������ֵ����������磺
"car" < "carriage" < "cats" < "doggies < "koala"
2.�����ַ����ĳ����������磺
"car" < "cats" < "koala" < "doggies" < "carriage"
������֪���Լ�����Щ�ַ�������˳���Ƿ��������������򷽷�������Ҫæ�ų���Ҷ��������Ҫ������æ��֤��
��������:
�����һ��Ϊ�ַ�������n(n �� 100)
��������n��,ÿ��һ���ַ���,�ַ������Ⱦ�С��100������Сд��ĸ���
�������:
�����Щ�ַ����Ǹ����ֵ������ж����Ǹ��ݳ����������"lexicographically",

������ݳ������ж������ֵ����������"lengths",

������ַ�ʽ���������"both"���������"none"
*/


/*����ע�͵��Ĵ����������ⲻ�����ҵ��뷨��ֻҪ�����򣨲����ǽ������򣩾��㣬��Ŀ��˼��ֻ���������*/





#include <iostream>
#include <string>
#include <vector>
using namespace std;


class str_sort
{
public:
	string Get_way(vector<string> str)
	{
		int lex_way = 1;
		int len_way = 1;
		size_t i = 1;
		size_t n = str.size();
		if (n == 1) {
			return "both";
		}
		if (str[i].compare(str[i - 1]) > 0) {
			while (i<n) {
				if (str[i].compare(str[i - 1]) > 0) {
					++i;
				}
				else {
					lex_way = 0;
					break;
				}
			}
		}
		else {
			lex_way = 0;
			//while(i<n) {
			//   if(str[i].compare(str[i-1]) < 0) {
			//       ++i;
			//   }
			//   else {
			//       lex_way=0;
			//       break;
			//   }
			// }
		}
		i = 1;
		if (str[i].size()>str[i - 1].size()) {
			while (i<n) {
				if (str[i].size()>str[i - 1].size()) {
					++i;
				}
				else {
					len_way = 0;
					break;
				}
			}
		}
		else {
			len_way = 0;
			//while(i<n) {
			//     if(str[i].size()< str[i-1].size()) {
			//         ++i;
			//     }
			//     else {
			//         len_way=0;
			//         break;
			//     }
			// }
		}
		if (lex_way == 1 && len_way == 1) {
			return "both";
		}
		else if (lex_way == 1 && len_way == 0) {
			return "lexicographically";
		}
		else if (lex_way == 0 && len_way == 1) {
			return "lengths";
		}
		else {
			return "none";
		}
	}
};


int main()
{
	str_sort s;
	int n;
	string k;
	while (cin >> n){
		if (n >= 1){
			vector<string> str(n);
			for (int i = 0; i<n; i++) {
				cin >> k;
				str[i] = k;
			}
			cout << s.Get_way(str) << endl;
		}

	}
	return 0;
}