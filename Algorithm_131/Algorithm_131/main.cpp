/*
��Ŀ����
ţ���������һ����Ա��Fish��ÿ���糿���ǻ�����һ��Ӣ����־��дЩ�����ڱ����ϡ�
ͬ��Cat��Fishд�������ĸ���Ȥ����һ������Fish������������ȴ������������˼��
���磬��student. a am I������������ʶ������һ�ԭ���Ѿ��ӵ��ʵ�˳��ת�ˣ�
��ȷ�ľ���Ӧ���ǡ�I am a student.����Cat��һһ�ķ�ת��Щ����˳��ɲ����У����ܰ�����ô��
*/


//�ַ����������ã� Ȼ������������ո������ǰһ���ո�����ո���ִ�
//ע��ܿ��ո񣬻�Ҫ�������һ���ִ�����Ϊ��ѭ�������һ���ִ��޷�����

#include <string>
using namespace std;

class Solution {
public:
	string ReverseSentence(string str) {
		reverse(str.begin(), str.end());
		size_t prev = 0;
		size_t next = 0;
		for (; next < str.size(); ++next) {
			if (str[next] == ' ') {
				reverse(str.begin() + prev, str.begin() + next);
				prev = next + 1;
			}
		}
		reverse(str.begin() + prev, str.end());
		return str;
	}
};

int main()
{
	return 0;
}