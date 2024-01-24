/*
239. Sliding Window Maximum

Solved

Hard

link to the problem:
https://leetcode.com/problems/sliding-window-maximum
*/
class Solution
{
private:
	int f_x(int k)
	{
		int x = 0;
		while ((1<<(x + 1)) <= k)
			x += 1;
		return (x);
	}

public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		
		int lg2 = this->f_x(k);
		int rqm[lg2+1][nums.size()];
		int n = nums.size();

		for (int i = 0; i < nums.size(); i++)
			rqm[0][i] = nums[i];

		for (int j = 1; j <= lg2; j++)
			for (int i = 0; i + (1<<j) - 1 < n; i++)
			{
				rqm[j][i] = max(rqm[j-1][i], rqm[j-1][i + (1<<(j-1))]);
			}

		vector<int> ans(nums.size() - k + 1);

		for (int i = 0; i + k - 1 < n; i++)
		{
			ans[i] = max(rqm[lg2][i], rqm[lg2][(i + k) - (1<<lg2)]);
		}

		return (ans);
	}
};
