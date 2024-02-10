/*
45. Jump Game II

Medium

link to the problem:
https://leetcode.com/problems/jump-game-ii/
*/
class Solution
{
private:
	vector< pair<int, int> > seg;
	int n;
	void setup(vector<int> &nums, int left, int right, int cur)
	{
		if (left == right)
		{
			seg[cur] = {min(left + nums[left], n-1), left};
			return ;
		}
		int mid = left + (right - left)/2;
		setup(nums, left, mid, cur*2+1);
		setup(nums, mid+1, right, cur*2+2);
		seg[cur] = max(seg[cur*2+1], seg[cur*2+2]);
	}
	pair<int, int> query(int ql, int qr, int left, int right, int cur)
	{
		if (ql <= left && right <= qr)
			return (seg[cur]);
		if (ql > right || left > qr)
			return (make_pair(0, 0));
		int mid = left + (right-left)/2;
		return max(query(ql, qr, left, mid, cur*2+1), 
		query(ql, qr, mid+1, right, cur*2+2));
	}

public:
	int jump(vector<int>& nums)
	{
		int ans = 0; n = nums.size();
		if (n == 1) return 0;
		seg.resize(n*4);
		setup(nums, 0, n-1, 0);
		for (int i = 0; i+1 < n; )
		{
			i = query(i, min(n-1, nums[i]+i), 0, n-1, 0).second;
			ans += 1;
		}
		return (ans);
	}
};
