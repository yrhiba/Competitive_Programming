/*
Medium
link to the problem:
https://leetcode.com/problems/permutation-in-string/
*/
class Solution {
public:
	bool checkInclusion(string s1, string s2) {

		vector<int> s1_letters(256, 0);
		vector<int> s2_letters(256, 0);

		for (char &c : s1)
			s1_letters[c] += 1;

		int i = 0;
		int j = 0;

		while (j < s2.size())
		{
			if ((s2_letters[s2[j]] + 1) > s1_letters[s2[j]])
			{
				if (j - i == s1.size())
					return true ;
				else
				{
					s2_letters[s2[i]] -= 1;
					i += 1;
				}
			}
			else
			{
				s2_letters[s2[j]] += 1;
				j += 1;
			}
		}
		bool ans = true;
		for (char c = 'a'; c <= 'z'; c++)
			if (s1_letters[c] != s2_letters[c])
			{
				ans = false;
				break ;
			}

		return ans;
	}
};