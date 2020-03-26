/*
题目描述
给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],
其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。
不能使用除法。（注意：规定B[0] = A[1] * A[2] * ... * A[n-1]，
B[n-1] = A[0] * A[1] * ... * A[n-2];）
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