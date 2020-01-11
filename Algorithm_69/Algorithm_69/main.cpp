/*
����һ������� (ransom) �ַ�����һ����־(magazine)�ַ�������
�ϵ�һ���ַ���ransom�ܲ����ɵڶ����ַ���magazines������ַ����ɡ�
������Թ��ɣ����� true �����򷵻� false��

(��Ŀ˵����Ϊ�˲���¶������ּ���Ҫ����־������������Ҫ����ĸ����ɵ����������˼��)

ע�⣺

����Լ��������ַ�����ֻ����Сд��ĸ��

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/ransom-note
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

/*
˼·������һ�����飬���ַ���ascll����Ϊ�±꣬Ȼ�����
*/

#include <string>
#include <vector>

class Solution {
public:
	bool canConstruct(std::string ransomNote, std::string magazine) {
		size_t ranson_length = ransomNote.size();
		size_t maga_length = magazine.size();
		if (ranson_length > maga_length) {
			return false;
		}
		std::vector<int> maga_arr(255, 0);
		for (size_t i = 0; i < maga_length; ++i) {
			maga_arr[magazine[i]]++;
		}
		for (size_t i = 0; i < ranson_length; ++i) {
			maga_arr[ransomNote[i]]--;
			if (maga_arr[ransomNote[i]] < 0) {
				return false;
			}
		}
		return true;
	}
};


int main()
{
	return 0;
}