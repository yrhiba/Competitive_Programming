/*
309. Best Time to Buy and Sell Stock with Cooldown

Medium

link to the problem:
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown
*/
class Solution
{
private:
	int n;

	vector<int> dp[2];

	int rec(vector<int> &prices, int i = 0, bool amBuying = false)
	{
		if (i >= n) return (0);

		if (dp[amBuying][i] != -1)
			return dp[amBuying][i];

		if (amBuying)
		{
			return dp[amBuying][i] = max(prices[i] + rec(prices, i+2, !amBuying)
						, rec(prices, i+1, amBuying));
		}

		return dp[amBuying][i] = max(rec(prices, i+1, !amBuying) - prices[i],
			rec(prices, i+1, amBuying));
	}

public:
	int maxProfit(vector<int>& prices)
	{
		n = prices.size();

		dp[0] = dp[1] = vector<int>(n, -1);

		return (rec(prices));
	}
};
