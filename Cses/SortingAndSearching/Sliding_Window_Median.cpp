/*
CSES Problem Set

Sliding Window Median

link to the problem:
https://cses.fi/problemset/task/1076/
*/
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <utility>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <fstream>
# define ull unsigned long long
# define ll long long
ll mod = 1e9 + 7;
using namespace std;

void update(vector<ll> &seg, ll idx, ll value, ll left, ll right, ll cur)
{
	if (left == right)
	{
		if (left == idx) seg[cur] += value;
		return ;
	}
	if (idx < left || idx > right) return ;
	ll mid = left + (right - left) / 2;
	update(seg, idx, value, left, mid, cur*2+1);
	update(seg, idx, value, mid+1, right, cur*2+2);
	seg[cur] = seg[cur*2+1] + seg[cur*2+2];
}

ll query(vector<ll> &seg, ll idx, ll left, ll right, ll cur)
{
	if (left == right) return (left);
	ll mid = left + (right - left) / 2;
	if (idx < seg[cur*2+1]) return query(seg, idx, left, mid, cur*2+1);
	return query(seg, idx - seg[cur*2+1], mid+1, right, cur*2+2);
}

void solve()
{
	ll n, k; cin >> n >> k;
	vector<ll> origin(n);
	vector<pair<ll, ll>> p(n);
	for (ll i = 0; i < n; i++)
	{
		cin >> p[i].first;
		p[i].second = i;
		origin[i] = p[i].first;
	}
	sort(p.begin(), p.end());
	vector<ll> a(n);
	for (ll i = 0, last = -1; i < n; i++)
	{
		p[i].first = i;
		swap(p[i].first, p[i].second);
		a[p[i].first] = p[i].second;
	}
	//
	vector<ll> utilAns(n);
	for (ll i = 0; i < n; i++) utilAns[a[i]] = origin[i];
	//
	vector<ll> seg(n*4, 0);
	for (ll i = 0; i < k; i++) update(seg, a[i], +1, 0, n-1, 0);
	for (ll left = 0, i = k; i < n; )
	{
		cout << utilAns[query(seg, k/2 - (k%2==0), 0, n-1, 0)] << " ";
		update(seg, a[left], -1, 0, n-1, 0), update(seg, a[i], +1, 0, n-1, 0);
		left += 1;
		i += 1;
	}
	cout << utilAns[query(seg, k/2 - (k%2==0), 0, n-1, 0)] << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
