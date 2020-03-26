/*
��Ŀ����
����һ������A[0,1,...,n-1],�빹��һ������B[0,1,...,n-1],
����B�е�Ԫ��B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]��
����ʹ�ó�������ע�⣺�涨B[0] = A[1] * A[2] * ... * A[n-1]��
B[n-1] = A[0] * A[1] * ... * A[n-2];��
*/

#include <vector>
using namespace std;

class Solution {
public:
	vector<int> multiply(const vector<int>& A) {
		int Asize = (int)A.size();
		vector<int> B(Asize);
		int product = 1;
		for (int i = 0; i < Asize; ++i) {
			product *= A[i];
			B[i] = product;
		}
		product = 1;
		for (int i = Asize - 1; i > 0; --i) {
			B[i] = B[i - 1] * product;
			product *= A[i];
		}
		B[0] = product;
		return B;
	}
};

int main()
{
	return 0;
}