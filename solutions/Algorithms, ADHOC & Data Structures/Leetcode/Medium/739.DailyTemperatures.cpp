/*
739. Daily Temperatures

Medium

link to the problem:
https://leetcode.com/problems/daily-temperatures/
*/

class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& temperatures)
	{
		vector<int> ans(temperatures.size(), 0);
		vector< pair<int, int> > st;

		st.push_back({temperatures[0], 0});

		for (int i = 1; i < temperatures.size(); i++)
		{
			while (!st.empty() && temperatures[i] > st.back().first)
			{
				ans[st.back().second] = i - st.back().second;
				st.pop_back();
			}

			st.push_back({temperatures[i], i});
		}

		return (ans);
	}
};
