/*
��Ŀ����
��һ���������������������㰴�����һ��һ��ش����������α�ţ��������Ϊ1���������������a��b�������һ���㷨�����a��b�������������ȵı�š�

��������int a,b��Ϊ�������ı�š��뷵��a��b������������ȵı�š�ע�������㱾��Ҳ����Ϊ�������ȡ�

����������
2��3
���أ�1
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