/*
647. Palindromic Substrings

Medium

link to the problem:
https://leetcode.com/problems/palindromic-substrings
*/
class Solution {
public:
	int countSubstrings(string s)
	{
		int ans = 0, n = s.size();
		for (int i = 0; i < n; i++)
		{
			// look for even pali
			int left = i;
			int right = i+1;
			while (left >= 0 && right < n
				&& s[left] == s[right])
			{
				left -= 1;
				right += 1;
				ans += 1;
			}
			// look for odd pali
			left = i;
			right = i;
			while (left >= 0 && right < n
				&& s[left] == s[right])
			{
				left -= 1;
				right += 1;
				ans += 1;
			}
		}
		return (ans);
	}
};
