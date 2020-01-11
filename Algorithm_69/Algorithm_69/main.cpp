/*
给定一个赎金信 (ransom) 字符串和一个杂志(magazine)字符串，判
断第一个字符串ransom能不能由第二个字符串magazines里面的字符构成。
如果可以构成，返回 true ；否则返回 false。

(题目说明：为了不暴露赎金信字迹，要从杂志上搜索各个需要的字母，组成单词来表达意思。)

注意：

你可以假设两个字符串均只含有小写字母。

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ransom-note
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
思路：定义一个数组，用字符的ascll码作为下标，然后遍历
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