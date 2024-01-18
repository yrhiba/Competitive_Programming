/*
17. Letter Combinations of a Phone Number

Medium

link to the problem:
https://leetcode.com/problems/letter-combinations-of-a-phone-number/
*/
class Solution
{
private:
	vector<string> phone = {
		"abc", // 2
		"def", // 3
		"ghi", // 4
		"jkl", // 5
		"mno", // 6
		"pqrs", // 7
		"tuv", // 8
		"wxyz" // 9
	};

	vector<string>	ans;
	string			cur;

	void	rec(string &digits, int i = 0)
	{
		if (i == digits.size())
		{
			if (!cur.empty())
				ans.push_back(cur);
			return ;
		}

		for (char c: phone[digits[i] - '2'])
		{
			cur.push_back(c);
			rec(digits, i + 1);
			cur.pop_back();
		}
	}

public:
	vector<string> letterCombinations(string digits) {
		return (rec(digits), ans);
	}
};
