/*
300. Longest Increasing Subsequence

Medium

link to the problem:
https://leetcode.com/problems/longest-increasing-subsequence/
*/
class Solution
{
private:
	vector<int> seg;

	void normalize(vector<int> &nums)
	{
		vector<pair<int, int>> a(nums.size());
		map<int, int> mp;
		for (int i = 0; i < nums.size(); i++)
		{
			a[i] = {nums[i], i};
			mp[nums[i]] += 1;
		}
		sort(a.begin(), a.end());
		for (int i = 0, j = 0; i < nums.size(); j++)
		{
			int x = mp[a[i].first];
			while (x--)
			{
				a[i].first = j;
				swap(a[i].first, a[i].second);
				i++;
			}
		}
		sort(a.begin(), a.end());
		for (int i = 0; i < nums.size(); i++) nums[i] = a[i].second;
	}

	int query(int ql, int qr, int left, int right, int cur)
	{
		if (ql <= left && right <= qr) return seg[cur];
		if (ql > right || left > qr) return (0);
		int mid = left + (right - left) / 2;
		return max(
			query(ql, qr, left, mid, cur*2+1),
			query(ql, qr, mid+1, right, cur*2+2)
		);
	}

	void update(int idx, int value, int left, int right, int cur)
	{
		if (left == right)
		{
			if (idx == left) seg[cur] = value;
			return ;
		}
		if (idx < left || idx > right) return ;
		int mid = left + (right - left) / 2;
		update(idx, value, left, mid, cur*2+1);
		update(idx, value, mid+1, right, cur*2+2);
		seg[cur] = max(seg[cur*2+1],seg[cur*2+2]);
	}

public:
	int lengthOfLIS(vector<int>& nums)
	{
		normalize(nums);
		seg.resize(nums.size() * 4, 0);
		for (int i = 0; i < nums.size(); i++)
		{
			update(
				nums[i], 
				query(0, nums[i]-1, 0, nums.size()-1, 0) + 1,
				0,
				nums.size()-1,
				0
			);
		}
		return (seg.front());
	}
};
