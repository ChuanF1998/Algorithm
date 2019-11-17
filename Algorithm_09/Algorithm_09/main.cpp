/*
题目描述
有一棵无穷大的满二叉树，其结点按根结点一层一层地从左往右依次编号，根结点编号为1。现在有两个结点a，b。请设计一个算法，求出a和b点的最近公共祖先的编号。

给定两个int a,b。为给定结点的编号。请返回a和b的最近公共祖先的编号。注意这里结点本身也可认为是其祖先。

测试样例：
2，3
返回：1
*/


class LCA {
public:
	int getLCA(int a, int b) {
		// write code here
		if (b>a) {
			int temp = a;
			a = b;
			b = temp;
		}
		if ((a == b) || (a == b + 1)) {
			return a / 2;
		}
		if (a / 2 == b) {
			return b;
		}
		while (a != 1) {
			a = a / 2;
			if (a == b) {
				return a;
			}
			if (b>a) {
				int temp = a;
				a = b;
				b = temp;
			}
		}
		return 1;
	}
};

int main()
{
	return 0;
}