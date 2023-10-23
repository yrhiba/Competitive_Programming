/*
Medium
link to the problem:
https://leetcode.com/problems/longest-repeating-character-replacement
*/
class Solution {
private:
	char most_char(vector<int> &letters_count)
	{
		char ans = 'A';
		for (char c = 'B'; c <= 'Z'; c++)
			if (letters_count[ans] < letters_count[c])
				ans = c;
		return (ans);
	}

public:
	int characterReplacement(string s, int k) {

		vector<int> letters_count(256); letters_count[s[0]] += 1;

		int p1 = 0, p2 = 0, ans = 0;

		while (p2 < s.size())
		{
			char most = most_char(letters_count);
			
			if ((p2 - p1 + 1) - letters_count[most] <= k)
			{
				ans = max(ans, p2 - p1 + 1);
				p2 += 1;
				letters_count[s[p2]] += 1;
			}
			else
			{
				letters_count[s[p1]] -= 1;
				p1 += 1;
			}
		}
		return (ans);
	}
};