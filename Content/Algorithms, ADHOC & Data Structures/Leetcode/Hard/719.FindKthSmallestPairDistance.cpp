/*
Problem Name: Find K-th Smallest Pair Distance (Hard)

link to the problem:
https://leetcode.com/problems/find-k-th-smallest-pair-distance
*/
class Solution
{
private:
	bool good(vector<int> &nums, int dis, int k, int n)
	{
		int garantideSamller = 0;
		for (int i = 1; i < n; i++)
		{
			int left = 0, right = i-1, mid, res = -1;
			while (left <= right)
			{
				int mid = left + (right - left) / 2;

				if (abs(nums[i] - nums[mid]) <= dis)
				{
					res = mid;
					right = mid - 1;
				}
				else left = mid + 1;
			}

			if (res != -1)
				garantideSamller += (i - res);
		}
		return (garantideSamller >= k);
	}

public:
	int smallestDistancePair(vector<int>& nums, int k)
	{
		int n = nums.size();
		sort(nums.begin(), nums.end());

		int left = 0, right = 1e6+1, mid, res = -1;
		while (left <= right)
		{
			mid = left + (right - left) / 2;
			if (good(nums, mid, k, n))
			{
				res = mid;
				right = mid - 1;
			}
			else left = mid + 1;
		}
		return (res);
	}
};
