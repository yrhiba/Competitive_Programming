/*
Medium problem.
Longest Substring Without Repeating Characters
link to the problem:
https://leetcode.com/problems/longest-substring-without-repeating-characters/
*/
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int res = 0;
		int i = 0;
		while (i < s.size())
		{
			map<char, bool> mp;

			int j = 0;
			while ((i + j) < s.size())
			{
				if (mp.find(s[i+j]) == mp.end())
					mp[s[i+j]] = true;
				else
					break;

				j++;
			}
			res = max(res, j);
			i++;
		}
		return (res);
	}
};
