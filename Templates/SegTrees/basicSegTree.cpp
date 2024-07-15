#include "header.hpp"

ll fn(ll a, ll b)
{
	return (a + b);
}
void segSetup(vector<ll> &seg, ll left, ll right, ll cur)
{
	if (left == right)
	{
		seg[cur] = 0;
		return;
	}
	ll mid = left + (right - left) / 2;
	segSetup(seg, left, mid, cur*2+1);
	segSetup(seg, mid+1, right, cur*2+2);
	seg[cur] = fn(seg[cur*2+1], seg[cur*2+2]);
}
void segUpdate(vector<ll> &seg, ll idx, ll value, ll left, ll right, ll cur)
{
	if (left == right)
	{
		if (left == idx) seg[cur] = value;
		return ;
	}
	if (idx < left || idx > right) return ;
	ll mid = left + (right - left) / 2;
	segUpdate(seg, idx, value, left, mid, cur*2+1);
	segUpdate(seg, idx, value, mid+1, right, cur*2+2);
	seg[cur] = fn(seg[cur*2+1], seg[cur*2+2]);
}
ll segQuery(vector<ll> &seg, const ll &ql, const ll &qr, ll left, ll right, ll cur)
{
	if (ql <= left && right <= qr) return seg[cur];
	if (ql > right || left > qr) return (0);
	ll mid = left + (right - left) / 2;
	return fn(
		segQuery(seg, ql, qr, left, mid, cur*2+1),
		segQuery(seg, ql, qr, mid+1, right, cur*2+2)
	);
}
