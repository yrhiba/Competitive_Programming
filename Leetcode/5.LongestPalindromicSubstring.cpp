/*
Medium Leetcode Problem.

link to the problem:
https://leetcode.com/problems/longest-palindromic-substring/
*/

class Solution {
public:
	string longestPalindrome(string s) {
		
		string ans = "";

		for (int i = 0; i < s.size(); i++)
		{
			int left, right;

			// check for odd pali
			left = right = i;
			while (left - 1 >= 0 && right + 1 < s.size())
			{
				if (s[left - 1] == s[right + 1])
				{
					left -= 1;
					right += 1;
				}
				else
					break;
			}

			if ((right - left + 1) > ans.size())
				ans = s.substr(left, right - left + 1);

			if (i + 1 == s.size() || s[i] != s[i + 1]) continue;

			// check for even pali
			left = i;
			right = i + 1;
			while (left - 1 >= 0 && right + 1 < s.size())
			{
				if (s[left - 1] == s[right + 1])
				{
					left -= 1;
					right += 1;
				}
				else
					break;
			}

			if ((right - left + 1) > ans.size())
				ans = s.substr(left, right - left + 1);
		}

		return (ans);
	}
};