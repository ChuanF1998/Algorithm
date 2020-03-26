/*
题目描述
写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
*/


class Solution {
public:
	int Add(int num1, int num2)
	{
		int and_ = num1 & num2; //两个数相与
		int xor_ = num1 ^ num2; //两个数相异或
		//相遇的结果为0就退出
		while (and_) {
			and_ <<= 1;  //相与的结果左移（当时没有等于出错）
			num1 = and_;  //保存 
			and_ &= xor_;  //
			xor_ ^= num1;
		}
		return xor_; //最后结果是两数相异或
	}
};

int main()
{
	return 0;
}