/*
link to the problem:
https://leetcode.com/problems/climbing-stairs
*/
class Solution {
private:
	map<int, int> caculated; 
public:
	int climbStairs(int n) {
		if (n <= 0)
			return (0);
		if (caculated.find(n) != caculated.end())
			return (caculated[n]);
		return (caculated[n] = climbStairs(n - 1) + climbStairs(n - 2)), 1 + caculated[n];
	}
};