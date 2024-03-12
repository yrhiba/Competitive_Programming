/*

190. Reverse Bits

Easy

link to the problem:
https://leetcode.com/problems/reverse-bits/

*/
class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		uint32_t res = 0;
		for (int i = 31; n; i--)
		{
			if (n%2)
				res += (1<<i);
			n /= 2;
		}
		return res;
	}
};