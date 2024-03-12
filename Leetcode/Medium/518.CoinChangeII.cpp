/*
518. Coin Change II

Medium

link to the problem:
https://leetcode.com/problems/coin-change-ii/s
*/
class Solution
{
private:
	vector< vector<int> > dp;

	int rec(int amount, vector<int>& coins, int cur = 0)
	{
		if (cur >= coins.size() || amount <= 0) return (amount == 0);

		if (dp[cur][amount] != -1) return dp[cur][amount];

		int ans = 0;

		for (int i = cur; i < coins.size(); i++)
		{
			if (coins[i] <= amount) ans += rec(amount - coins[i], coins, i);
		}

		return dp[cur][amount] = ans;
	}

public:
	int change(int amount, vector<int>& coins)
	{
		dp = vector< vector<int> >(coins.size(), vector<int>(amount+1, -1));
		return rec(amount, coins);
	}
};
