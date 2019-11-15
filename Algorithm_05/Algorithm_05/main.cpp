/*
题目描述
请编写一个函数，将两个数字相加。不得使用+或其他算数运算符。

给定两个int A和B。请返回A＋B的值

测试样例：
1,2
返回：3
*/

//循环条件：两数相与的结果不为0
//循环体：把数A与数B的相与结果给A，把数A与数B相异或的结果给B
//原理：若两个数相与的结果为0，那么这两个数的和=A^B-->(例：A=5->0101,B=2->0010,A^B=0111=7)
//若两个数相与的结果不为0，意味着相同位会产生进位，那么将相与的结果左移一位。

class UnusualAdd {
public:
	int addAB(int A, int B) {
		// write code here
		while ((A&B) != 0) {
			int A1 = A;
			int B1 = B;
			A = (A1&B1) << 1;
			B = A1^B1;
		}
		return A^B;
	}
};

int main()
{
	return 0;
}