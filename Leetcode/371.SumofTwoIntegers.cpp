/*
371. Sum of Two Integers

Medium

link to the problem:
https://leetcode.com/problems/sum-of-two-integers
*/
class Solution
{
public:
	int getSum(int a, int b)
	{
		int c, r;

		c = a ^ b;
		r = (a & b)<<1;

		while (r)
		{
			int t = c ^ r;
			r = (c & r)<<1;
			c = t;
		}

		return c;
	}
};
