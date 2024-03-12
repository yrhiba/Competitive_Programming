/*
1851. Minimum Interval to Include Each Query

Hard

link to the problem:
https://leetcode.com/problems/minimum-interval-to-include-each-query
*/
class Solution {
private:
	int n, q;
public:
	vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries)
	{
		n = intervals.size();
		q = queries.size();

		vector< pair<int, int> > Q(q);

		for (int i = 0; i < q; i++) Q[i] = {queries[i], i}; // O(q)

		sort(Q.begin(), Q.end()); // O(q log q)

		vector< pair<int, int> > a(n);

		for (int i = 0; i < n; i++)
			a[i] = {intervals[i][1]-intervals[i][0]+1, i}; // O(n)

		sort(a.begin(), a.end()); // O(n log n)

		vector<int> seg(q*4, -1);

		for (auto &[size, idx] : a)
		{
			int ql = getIdxOfLeft(Q, intervals[idx][0]);
			int qr = getIdxOfRight(Q, intervals[idx][1]);

			if (ql != -1 && qr != -1)
				update(seg, ql, qr, 0, q-1, size, 0); // O(log n)
		}

		vector< int > ans(q);

		setup(ans, Q, seg, 0, q-1, 0, -1);

		return (ans);
	}

private:
	int getIdxOfLeft(vector< pair<int, int> > &Q, int target)
	{
		int start = 0;
		int end = q-1;
		int mid, res = -1;
		while (start <= end)
		{
			mid = start + (end - start) / 2;
			if (Q[mid].first >= target) res = mid, end = mid-1;
			else start = mid+1;
		}
		return res;
	}
	int getIdxOfRight(vector< pair<int, int> > &Q, int target)
	{
		int start = 0;
		int end = q-1;
		int mid, res = -1;
		while (start <= end)
		{
			mid = start + (end - start) / 2;
			if (Q[mid].first <= target) res = mid, start = mid+1;
			else end = mid-1;
		}
		return res;
	}
	void update(vector<int> &seg, int ql, int qr, int left, int right, int value, int cur)
	{
		if (seg[cur] != -1) return ;
		if (ql <= left && right <= qr)
		{
			seg[cur] = value;
			return ;
		}
		if (left > qr || ql > right) return ;
		int mid = left + (right-left)/2;
		update(seg, ql, qr, left, mid, value, cur*2+1);
		update(seg, ql, qr, mid+1, right, value, cur*2+2);
	}
	void setup(vector<int> &ans, vector<pair<int, int>> &Q, vector<int> &seg, int left, int right, int cur, int value)
	{
		if (seg[cur] != -1)
		{
			value = (value != -1) ? min(value, seg[cur]) : seg[cur];
		}
		if (left == right)
		{
			ans[Q[left].second] = value;
			return ;
		}
		int mid = left + (right-left)/2;
		setup(ans, Q, seg, left, mid, cur*2+1, value);
		setup(ans, Q, seg, mid+1, right, cur*2+2, value);
	}
};
