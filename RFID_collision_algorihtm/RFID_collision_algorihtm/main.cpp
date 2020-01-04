#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct card
{
	string code;  //���к�
	bool is_correct;  //���Ƿ��ܶ�ȡ�����󿨻��Ѷ��Ŀ����ܶ���
	card(){}
	card(string code)
		:code(code)
		, is_correct(true)
	{}
};

class RFID_Read
{
public:
	//�ҳ���ͻλ arr����һ�鿨 ��max_code����������кţ� conflict_bit���ڴ洢��ͻλ
	void first_request(vector<card>& arr, string& max_code, vector<int>& conflict_bit)
	{
		int max_code_length = max_code.size();
		int arr_length = arr.size();
		for (int i = 0; i < arr_length; ++i) {     //��ǷǷ�����һ������ʱ�ͺ�����
			if (arr[i].code.size() != max_code_length) {
				arr[i].is_correct = false;
			}
			else {
				cout << arr[i].code << endl;  //��ӡ������ȷ�Ŀ�
			}
		}
		int k = 0;
		for (int i = 0; i < arr_length; ++i) {  //�ҳ���һ����ȷ�Ŀ�
			if (arr[i].is_correct == true) {
				k = i;
				break;
			}
		}
		for (int i = 0; i < max_code_length; ++i) {  //�ҳ�ͻλ
			max_code[i] = arr[k].code[i];            //����һ����ȷ�������кŸ���max_code
			for (int j = 0; j < arr_length; ++j) {
				if (arr[k].code[i] != arr[j].code[i] && arr[j].is_correct == true) { //������ͻλʱ
					conflict_bit.push_back(i);                       //����ͻλ��λ����¼
					max_code[i] = 'X';                              //������ͻλ���λX���˳��ж���һλ
					break;
				}
			}
		}
	}
	//�ҳ�ĳһ�ſ�
	void find_card(vector<card>& arr, vector<int>& conflict_bit, string& s)
	{
		request(arr, conflict_bit, 0, '0', s);
		request(arr, conflict_bit, 0, '1', s);
	}

private:
	//���������������㷨   k����conflict_bit����ĵ�kλ�� flag�����ͻλ������λ0��1�� s����ǰ��д�����������к�
	void request(vector<card>& arr, vector<int>& conflict_bit,int k, char flag, string& s)
	{
		int count = 0;
		s[conflict_bit[k]] = flag;  //����߳�ͻλ��Ϊ0��1
		for (int i = 0; i < arr.size(); ++i) {
			if (arr[i].code[conflict_bit[k]] == flag && arr[i].is_correct == true) { //�ҳ����ͻλ��ͬ�����кţ�count++
				++count;
				for (int j = 0; j <= conflict_bit[k]; ++j) {          //�ҳ��뵱ǰ��ͻλ֮ǰλ������ͬ�����кţ�count--
					if (arr[i].code[j] != s[j]) {                  
						--count;
						break;
					}
				}
			}
		}
		if (count < 2) {                                   //���ҵ��Ŀ�����������1��0ʱ���ʹ�ӡ�����кŲ����ÿ���Ϊ���ɶ������˳�ѭ��
			int f = 0;
			for (int i = 0; i < arr.size(); ++i){
				if (arr[i].code[conflict_bit[k]] == flag && arr[i].is_correct == true) {
					for (int j = 0; j <= conflict_bit[k]; ++j) {
						if (arr[i].code[j] != s[j]) {
							break;
						}
						f = j;
					}
					if (f == conflict_bit[k]) {  
						arr[i].is_correct = false;
						cout << "�� " << i + 1 << " ����ǩ: " << arr[i].code << endl;
					}
				}
			}
			return;
		}
		else {  //������һ����ͻλ���ж�
			request(arr, conflict_bit, k + 1, '0', s);
			request(arr, conflict_bit, k + 1, '1', s);
		}
	}
};

int main()
{
	RFID_Read r;
	vector<card> arr;
	string str;
	int k;
	cout << "�������ǩ����:" << endl;
	cin >> k;
	for (int i = 0; i < k; ++i) {
		cin >> str;
		arr.push_back({ str });
	}
	string s = "11111111";
	vector<int> conflict_bit;
	r.first_request(arr, s, conflict_bit);
	r.find_card(arr, conflict_bit, s);
	return 0;
}