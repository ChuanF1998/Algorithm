/*
��Ŀ����
��ʵ��һ�����������ҳ��ַ����е�һ��ֻ����һ�ε��ַ���
���磬�����ַ�����ֻ����ǰ�����ַ�"go"ʱ����һ��ֻ����һ
�ε��ַ���"g"�����Ӹ��ַ����ж���ǰ�����ַ���google"ʱ��
��һ��ֻ����һ�ε��ַ���"l"��
�������:
�����ǰ�ַ���û�д��ڳ���һ�ε��ַ�������#�ַ���
*/


//����һ������+���У����б���ֻ����һ�ε��ַ������ֶ�κ󣬴Ӷ�ͷɾ��ֱ����ͷ�ַ�ֻ����һ�Ρ�
//������������+�ַ������ַ������ڱ����ַ��������ַ������ҳ���һ��ֻ����һ�ε��ַ���

#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
	Solution()
	{
		_str_arr.resize(255, 0);
	}
	//Insert one char from stringstream
	void Insert(char ch)
	{
		_str_arr[ch]++;
		if (_str_arr[ch] == 1) {
			_once.push(ch);
		}
	}
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce()
	{
		while (!_once.empty() && _str_arr[_once.front()] > 1) {
			_once.pop();
		}
		if (!_once.empty()) {
			return _once.front();
		}
		return '#';
	}

public:
	vector<int> _str_arr;
	queue<char> _once;
};

int main()
{
	return 0;
}