

//方法1：在类中定义全局变量，创建类

class A
{
public:
	A()
	{
		n++;
		sum += n;
	}

	static void reset()
	{
		sum = 0;
		n = 0;
	}
	static int getSum()
	{
		return sum;
	}
public:
	static int sum;
	static int n;
};

int A::sum = 0;
int A::n = 0;

class Solution1 {
public:
	int Sum_Solution(int n) {
		A::reset();
		A* p = new A[n];
		delete[] p;
		return A::getSum();
	}
};

//方法2：利用短路计算，当n==0时退出
class Solution2 {
public:
	int Sum_Solution(int n) {
		int ret = n;
		n && (ret += Sum_Solution(n - 1));
		return ret;
	}
};

//方法3：模板编程
template<int n>
inline int Getsum()
{
	return n + Getsum<n - 1>();
}
template<>
inline int Getsum<1>()
{
	return 1;
}

//方法4：虚函数

class base
{
public:
	virtual int GetSum(int n)
	{
		return 0;
	}
};

base* q[2];

class derived : public base
{
public:
	virtual int GetSum(int n)
	{
		return (q[!!n])->GetSum(n - 1) + n;
	}
};

class Solution {
public:
	int Sum_Solution(int n) {

		base b;
		derived d;
		q[0] = &b;
		q[1] = &d;
		return d.GetSum(n);
	}
};



int main()
{
	const int n = 50;
	int k = Getsum<n>();
	return 0;
}