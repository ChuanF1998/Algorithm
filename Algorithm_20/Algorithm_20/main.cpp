/*
��Ŀ����
�˿�����Ϸ���Ӧ�ö��Ƚ���Ϥ�ˣ�һ������54����ɣ���3~A��2��4�ţ�С��1�ţ�����1�š������С�����������ַ����ַ�����ʾ�����У�Сдjoker��ʾС������дJOKER��ʾ������:)
3 4 5 6 7 8 9 10 J Q K A 2 joker JOKER
���������ƣ�������֮���á�-�����ӣ�ÿ���Ƶ�ÿ�����Կո�ָ�����-������û�пո��磺4 4 4 4-joker JOKER
��Ƚ������ƴ�С������ϴ���ƣ���������ڱȽϹ�ϵ�����ERROR

��������
��1������ÿ���ƿ����Ǹ��ӣ����ӣ�˳�ӣ�����5�ţ���������ը�����ĸ����Ͷ����е�һ�֣���������������������뱣֤�����ƶ��ǺϷ��ģ�˳���Ѿ���С�������У�
��2������ը���Ͷ������Ժ������ƱȽ�֮�⣬�������͵���ֻ�ܸ���ͬ���͵Ĵ��ڱȽϹ�ϵ���磬���Ӹ����ӱȽϣ������������Ƚϣ��������ǲ���������磺�����Ӳ�ֳɸ��ӣ�
��3����С��������ƽʱ�˽�ĳ���������ͬ�����ӣ����ӣ������Ƚ������С��˳�ӱȽ���С�ƴ�С��ը������ǰ�����е��ƣ�ը��֮��Ƚ������С�������������ƣ�
��4������������Ʋ��������ȵ������

����ʾ��
��1������ը���Ͷ���֮�⣬��������ͬ���ͱȽϡ�
��2�������Ѿ���֤�Ϸ��ԣ����ü�������Ƿ��ǺϷ����ơ�
��3�������˳���Ѿ�������С����������˲�����������.
��������:
���������ƣ�������֮���á�-�����ӣ�ÿ���Ƶ�ÿ�����Կո�ָ�����-������û�пո���4 4 4 4-joker JOKER��
�������:
����������нϴ�����֣��������ӷ����˿���˳�򲻱䣬���Կո��������������ڱȽϹ�ϵ�����ERROR��

ʾ��1
����
4 4 4 4-joker JOKER

���
joker JOKER
*/



#include <iostream>
#include <string>
#include <vector>
using namespace std;

class large_poker
{
public:
	string get_largr_poker(string& str)
	{
		string str_cmp = str;  //�ȿ���һ�ݸ�����һ���������
		auto cmp_first = str_cmp.begin();
		auto cmp_last = str_cmp.end();
		while (cmp_first != cmp_last) { //���ա�-���ֿ�
			if (*cmp_first == '-') {
				break;
			}
			++cmp_first;
		}
		string str1_cmp(str_cmp.begin(), cmp_first);
		string str2_cmp(cmp_first + 1, str_cmp.end());

		auto first = str.begin();
		auto last = str.end();
		auto it = str.begin();
		while (it != last){
			if (*it == '0') {   //Ϊ���жϷ��㣬��10�����˿˱��1
				it = str.erase(it);
			}
			else {
				it++;
			}
		}

		while (first != last) {
			if (*first == '-') {
				break;
			}
			++first;
		}
		string str1(str.begin(), first);
		string str2(first + 1, str.end());
		//����һ������С�����ƣ�10����Ϊ1
		vector<char> poker{ '3', '4', '5', '6', '7', '8', '9', '1', 'J', 'Q', 'K', 'A', '2' };
		string s1 = poker_species(str1);
		string s2 = poker_species(str2);
		//��ը���������ǣ�ը��ҲҪ������ը����һ��ը��
		if (s1 == "big_bomb") {
			return str1_cmp;
		}
		else if (s1 == "s_single") {
			if (s2 == "b_single"){
				return str2_cmp;
			}
			else {
				return str1_cmp;
			}
		}
		else if (s1 == "b_single") {
			return str1_cmp;
		}
		else if (s1 == "ordinary_bomb") {
			if (s2 == "no"){
				return str1_cmp;
			}
			else if (s2 == "big_bomb"){
				return str2_cmp;
			}
			else{
				int m = 0;
				int n = 0;
				for (int i = 0; i<13; ++i){
					if (str1[0] == poker[i]){
						m = i;
					}
					if (str2[0] == poker[i]){
						n = i;
					}
				}
				if (m>n){
					return str1_cmp;
				}
				else {
					return str2_cmp;
				}
			}
		}

		if (s2 == "big_bomb") {
			return str2_cmp;
		}
		else if (s2 == "s_single") {
			if (s1 == "b_single"){
				return str1_cmp;
			}
			else {
				return str2_cmp;
			}
		}
		else if (s2 == "b_single") {
			return str2_cmp;
		}
		else if (s2 == "ordinary_bomb") {
			if (s1 == "no"){
				return str2_cmp;
			}
			else if (s2 == "big_bomb"){
				return str2_cmp;
			}
			else{
				int m = 0;
				int n = 0;
				for (int i = 0; i<13; ++i){
					if (str1[0] == poker[i]){
						m = i;
					}
					if (str2[0] == poker[i]){
						n = i;
					}
				}
				if (m>n){
					return str1_cmp;
				}
				else {
					return str2_cmp;
				}
			}
		}

		if (str1.size() != str2.size()) {
			return "ERROR";
		}

		int m = 0;
		int n = 0;
		for (int i = 0; i<13; ++i){
			if (str1[0] == poker[i]){
				m = i;
			}
			if (str2[0] == poker[i]){
				n = i;
			}
		}
		if (m>n) {
			return str1_cmp;
		}
		else {
			return str2_cmp;
		}
	}
	string poker_species(string& str) {
		if (str == "joker JOKER"){
			return "big_bomb";
		}
		if (str == "joker"){
			return "s_single";
		}
		if (str == "JOKER"){
			return "b_single";
		}
		if (str.size() == 7) {
			return "ordinary_bomb";
		}
		return "no";
	}
};

int main()
{
	large_poker l;
	string str;
	while (getline(cin, str)){
		cout << l.get_largr_poker(str);
	}
	return 0;
}