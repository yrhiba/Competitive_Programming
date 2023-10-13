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

		set<char> st;
		int start = 0;

		for (int i = 0; i < s.size(); i++)
		{
			while (st.find(s[i]) != st.end())
			{
				st.erase(s[start]);
				start += 1;
			}

			res = max(res, i - start + 1);
			st.insert(s[i]);
		}
		return (res);
	}
};
