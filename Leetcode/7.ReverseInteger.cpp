/*
7. Reverse Integer

Medium

link to the problem:
https://leetcode.com/problems/reverse-integer/
*/
class Solution {
public:
	int reverse(int x) {
		
		long long r = 0;

		while (x)
		{
			r = r * 10 + x%10;
			x /= 10;
		}

		if (r < -2147483648l || r >= 2147483648l)
			return 0;

		return (r);
	}
};
