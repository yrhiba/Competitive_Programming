/*
84. Largest Rectangle in Histogram

Solved

Hard

link to the problem:
https://leetcode.com/problems/largest-rectangle-in-histogram
*/
class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {

		int n = heights.size();

		stack<pair<int, int>> st;

		int ans = 0;

		for (int i = 0, x = 0; i < n; i++, x = i)
		{
			while (!st.empty() && heights[i] < st.top().first)
			{
				ans = max(ans, (i - st.top().second) * st.top().first);
				x = st.top().second;
				st.pop();
			}

			st.push({heights[i], x});
		}

		while (!st.empty())
		{
			ans = max(ans, (n - st.top().second) * st.top().first);
			st.pop();
		}

		return (ans);
	}
};
