/*
134. Gas Station

Medium

link to the problem:
https://leetcode.com/problems/gas-station/
*/
class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
	{
		int n = gas.size();

		int ans, cur, startIdx, t;

		ans = cur = t = gas[0]-cost[0], startIdx = 0;

		for (int i = 1; i < n; i++)
		{
			int x = gas[i] - cost[i];

			t += x;
			
			if (cur+x < x)
			{
				cur = x;
				startIdx = i;
			}
			else cur += x;
		}

		return (t>=0)?startIdx:-1;
	}
};
