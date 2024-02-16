/*
763. Partition Labels

Medium

link to the problem:
https://leetcode.com/problems/partition-labels/
*/
class Solution {
public:
	vector<int> partitionLabels(string s)
	{
		int n = s.size();
		vector< pair<int, int> > occur(27, make_pair(-1, -1));
		for (int i = 0; i < n; i++)
		{
			if (occur[s[i]-'a'].first == -1) occur[s[i]-'a'] = {i, i};
			else occur[s[i]-'a'].second = i;
		};
		vector<int> time(n, 0);
		for (auto &[i, j] : occur)
		{
			if (i == -1) continue;
			time[i] += 1;
			time[j] -= 1;
		}
		for (int i = 1; i < n; i++) time[i] += time[i-1];
		vector<int> ans;
		int cur = 0;
		for (auto &i : time)
		{
			cur += 1;
			if (!i)
			{
				ans.push_back(cur);
				cur = 0;
			}
		}
		return ans;
	}
};
