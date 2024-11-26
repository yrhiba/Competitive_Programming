# include "../header.hpp"

/*
	Tested only with range sum [a, b] + u
	Answer query per point.
*/

void setup(vector<pair<ll, ll>> &seg, vector<ll> &a, ll left, ll right, ll cur)
{
	if (left == right) {
		seg[cur] = {a[left], 0};
		return;
	}
	ll mid = left + (right - left) / 2;
	setup(seg, a, left, mid, cur*2+1);
	setup(seg, a, mid+1, right, cur*2+2);
	seg[cur].first = seg[cur*2+1].first + seg[cur*2+2].first;
	seg[cur].second = 0;
}

void update(vector<pair<ll, ll>> &seg, ll ql, ll qr, ll u, ll left, ll right, ll cur)
{
	if (ql <= left && right <= qr) {
		seg[cur].second += u;
		return ;
	}
	if (ql > right || left > qr) return ;
	ll mid = left + (right - left) / 2;
	update(seg, ql, qr, u, left, mid, cur*2+1);
	update(seg, ql, qr, u, mid+1, right, cur*2+2);
	seg[cur].first = seg[cur*2+1].first + seg[cur*2+2].first;
	seg[cur].first += (right - left + 1) * seg[cur].second;
}

ll query(vector<pair<ll, ll>> &seg, ll idx, ll left, ll right, ll cur)
{
	if (left == right)
	{
		if (left == idx) {
			seg[cur].first += seg[cur].second;
			seg[cur].second = 0;
			return seg[cur].first;
		}
		return (0);
	}
	if (idx < left || idx > right) return (0);
	ll mid = left + (right - left) / 2;
	if (seg[cur].second)
	{
		seg[cur].first += seg[cur].second * (right - left + 1);
		seg[cur*2+1].second += seg[cur].second;
		seg[cur*2+2].second += seg[cur].second;
		seg[cur].second = 0;
	}
	return query(seg, idx, left, mid, cur*2+1)
		+ query(seg, idx, mid+1, right, cur*2+2);
}
