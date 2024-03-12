/*
50. Pow(x, n)

Medium

link to the problem:
https://leetcode.com/problems/powx-n/
*/
class Solution
{
private:
	double _myPow(double x, long long n)
	{
		if (n == 0) return 1;
		double y = myPow(x, n/2);
		return y*y*((n%2)?x:1);
	}

public:
	double myPow(double x, int n)
	{
		if (n < 0) return 1 / _myPow(x, n*-1l);
		return _myPow(x, n);
	}
};
