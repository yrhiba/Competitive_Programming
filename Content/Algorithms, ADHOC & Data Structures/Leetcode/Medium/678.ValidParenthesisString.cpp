/*
678. Valid Parenthesis String

Medium

link to the problem:
https://leetcode.com/problems/valid-parenthesis-string
*/
class Solution {
public:
	bool checkValidString(string s)
	{
		vector<bool> f(s.size(), false);

		vector<int> p;
		vector<int> e;

		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '(')
				p.push_back(i);
			else if (s[i] == ')')
			{
				if (!p.empty())
					p.pop_back();
				else if (!e.empty())
					e.pop_back();
				else
					return (false);
			}
			else
				e.push_back(i);
		}

		while (true)
		{
			if (p.empty() || e.empty() || p.back() > e.back())
				break ;

			p.pop_back();
			e.pop_back();
		}

		return (p.empty());
	}
};
