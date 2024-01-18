/*
131. Palindrome Partitioning

Medium

link to the problem:
https://leetcode.com/problems/palindrome-partitioning/
*/
class Solution
{
private:
	map<int, vector<int>>           palis;

	vector<vector<string>>          ans;
	vector<string>                  cur;

	void rec(string &s, int start = 0)
	{
		if (start == s.size())
		{
			ans.push_back(cur);
			return ;
		}

		for (int &end: palis[start])
		{
			cur.push_back(s.substr(start, end - start + 1));
			rec(s, end + 1);
			cur.pop_back();
		}
	}

public:
	vector<vector<string>> partition(string s)
	{
		int l, r;

		for (int i = 0; i < s.size(); i++)
		{
			// check for odd pali
			l = i;
			r = i;

			while (l >= 0 && r < s.size() && s[l] == s[r])
			{
				palis[l].push_back(r);
				l -= 1;
				r += 1;
			}

			// check for even pali
			l = i;
			r = i + 1;

			while (l >= 0 && r < s.size() && s[l] == s[r])
			{
				palis[l].push_back(r);
				l -= 1;
				r += 1;
			}
		}

		return (rec(s), ans);
	}
};
