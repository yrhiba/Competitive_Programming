# include "../header.hpp"

/*
	Tested only with range sum [a, b] + u
	Answer query per point.
*/

// when updating a range we have a left and right,
// when we coincide with a range that is fully insinde our (l, r) we stop
 
// update the node when you visited it, propagted down the update 
 
// range ubdate (l, r) + val: 
	// traverse the seg tree
	//update prev remaining update if ther is 
	// check if the node completely overlap with (l, r)
		// -update the node
		// -lazy propagate to children if it has and return  (lazy[2*ind]+=val, lazy[2*ind+2]+=val)
 
	// check if the node partially overlap
		// -go left , go right
	// no overlap 
		// -return (stop the traverse)
// range query  : check if node need ubdate other are just similar to noraml segTree

struct segTree{
	vector<ll> all;
	ll n;
	vector<ll> s;
	vector<ll> lazy;

	ll fn(ll a, ll b){
		return a + b;
	}
	segTree(vector<ll> &a){
		n = a.size();
		all = a;
		s.resize(4 * n);
		lazy.resize(4 * n);
		build(1, 0, n - 1);
	}
	void	build(ll node, ll start, ll end){
		if (start == end){
			s[node] = all[start];
			return ;
		}
		ll mid = (start + end) / 2;
		build(2 * node, start, mid);
		build(2 * node + 1, mid + 1, end);
		s[node] = fn(s[2*node], s[2*node + 1]);
	}
	
	void	push_down(ll node, ll start, ll end) {
		s[node] += lazy[node] * (end - start + 1);
		if (start != end){
			lazy[2 * node] += lazy[node];
			lazy[2 * node + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
 
	void	update(ll node, ll start, ll end, ll l, ll r, ll val){
		push_down(node, start, end);
		if (start > r ||  end < l) return ;
		if (start >= l && end <= r){
			lazy[node] += val;
			push_down(node, start, end);
			return ;
		}
		ll mid = (start + end) / 2;
		update(2 * node, start, mid, l, r, val);
		update(2 * node + 1, mid + 1, end, l, r, val);
		s[node] = fn(s[2 * node], s[2 * node + 1]);
	}

	void	update(ll l, ll r, ll val){
		update(1, 0, n - 1, l, r, val);
	}
	
	ll query(ll node, ll start, ll end, const ll l, const ll r){
		push_down(node, start, end);
		if (start > r || end < l) return 0;
		if (start >= l && end <= r) return s[node];
		ll mid = (start + end) / 2;
		ll left = query(2 * node, start, mid, l, r);
		ll right = query(2 * node + 1, mid + 1, end, l, r);
		return left + right;
	}

	ll query(ll l, ll r){
		return query(1, 0, n - 1, l, r);
	}
};


struct MyLazzySegTree
{
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
};
