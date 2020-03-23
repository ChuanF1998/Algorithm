/*
题目描述
牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。
同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。
例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，
正确的句子应该是“I am a student.”。Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？
*/


//字符串整体逆置， 然后遍历，遇到空格就逆置前一个空格到这个空格的字串
//注意避开空格，还要逆置最后一个字串，因为在循环中最后一个字串无法逆置

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