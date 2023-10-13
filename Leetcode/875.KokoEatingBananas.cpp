/*
link to the problem:
https://leetcode.com/problems/koko-eating-bananas
*/
class Solution {
private:
	bool good(vector<int> &piles, int &h, int &k)
	{
		int hours_needed = 0;
		for (int i = 0; i < piles.size(); i++)
			hours_needed += ((piles[i] + k - 1) / k);
		return (hours_needed <= h);
	}
public:
	int minEatingSpeed(vector<int>& piles, int h) {
		
		int start = 1;
		int end = 1e9 + 1;
		int ans;
		int mid;

		while (start <= end)
		{
			mid = start + (end - start + 1) / 2;

			if (good(piles, h, mid))
			{
				ans = mid;
				end = mid - 1;
			}
			else
			{
				start = mid + 1;
			}
		}

		return (ans);
	}
};