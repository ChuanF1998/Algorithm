#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct card
{
	string code;  //序列号
	bool is_correct;  //卡是否能读取（错误卡或已读的卡不能读）
	card(){}
	card(string code)
		:code(code)
		, is_correct(true)
	{}
};

class RFID_Read
{
public:
	//找出冲突位 arr代表一组卡 ，max_code代表最大序列号， conflict_bit用于存储冲突位
	void first_request(vector<card>& arr, string& max_code, vector<int>& conflict_bit)
	{
		int max_code_length = max_code.size();
		int arr_length = arr.size();
		for (int i = 0; i < arr_length; ++i) {     //标记非法卡，一会搜索时就忽略它
			if (arr[i].code.size() != max_code_length) {
				arr[i].is_correct = false;
			}
			else {
				cout << arr[i].code << endl;  //打印所有正确的卡
			}
		}
		int k = 0;
		for (int i = 0; i < arr_length; ++i) {  //找出第一张正确的卡
			if (arr[i].is_correct == true) {
				k = i;
				break;
			}
		}
		for (int i = 0; i < max_code_length; ++i) {  //找冲突位
			max_code[i] = arr[k].code[i];            //将第一张正确卡的序列号赋给max_code
			for (int j = 0; j < arr_length; ++j) {
				if (arr[k].code[i] != arr[j].code[i] && arr[j].is_correct == true) { //遇到冲突位时
					conflict_bit.push_back(i);                       //将冲突位的位数记录
					max_code[i] = 'X';                              //并将冲突位标记位X后退出判断下一位
					break;
				}
			}
		}
	}
	//找出某一张卡
	void find_card(vector<card>& arr, vector<int>& conflict_bit, string& s)
	{
		request(arr, conflict_bit, 0, '0', s);
		request(arr, conflict_bit, 0, '1', s);
	}

private:
	//二进制树型搜索算法   k代表conflict_bit数组的第k位， flag代表冲突位将被置位0或1， s代表当前读写器发出的序列号
	void request(vector<card>& arr, vector<int>& conflict_bit,int k, char flag, string& s)
	{
		int count = 0;
		s[conflict_bit[k]] = flag;  //将最高冲突位置为0或1
		for (int i = 0; i < arr.size(); ++i) {
			if (arr[i].code[conflict_bit[k]] == flag && arr[i].is_correct == true) { //找出与冲突位相同的序列号，count++
				++count;
				for (int j = 0; j <= conflict_bit[k]; ++j) {          //找出与当前冲突位之前位数不相同的序列号，count--
					if (arr[i].code[j] != s[j]) {                  
						--count;
						break;
					}
				}
			}
		}
		if (count < 2) {                                   //当找到的卡的数量等于1或0时，就打印该序列号并将该卡置为不可读，后退出循环
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
						cout << "第 " << i + 1 << " 个标签: " << arr[i].code << endl;
					}
				}
			}
			return;
		}
		else {  //继续下一个冲突位的判断
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
	cout << "请输入标签个数:" << endl;
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