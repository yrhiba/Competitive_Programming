/*

* Hard Leetcode Problem

link to the problem:
https://leetcode.com/problems/minimum-window-substring/

*/
class Solution {
public:
	string minWindow(string s, string t) {

		map<char, int>  mp;

		for (char &c : t)
			mp[c] += 1;

		int i = 0;
		int j = 0;

		pair<int, int> ans = {-1, 1e8};

		int cnt = 0;

		while (j <= s.size())
		{
			if (cnt == mp.size())
			{   
				if (ans.first == -1 || (j - i) < ans.second)
					ans = {i, j - i};

				if (mp.find(s[i]) != mp.end())
				{
					mp[s[i]] += 1;

					if (mp[s[i]] == 1)
						cnt -= 1;
				}

				i += 1;
			}
			else if (j < s.size())
			{
				if (mp.find(s[j]) != mp.end() )
				{
					mp[s[j]] -= 1;

					if (mp[s[j]] == 0)
						cnt += 1;
				}
				j += 1;
			}
			else
				j += 1;
		}

		if (ans.first != -1)
			return s.substr(ans.first, ans.second);
		return ("");
	}
};