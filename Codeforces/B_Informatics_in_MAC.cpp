/*
B. Informatics in MAC

link to the problem:
https://codeforces.com/contest/1935/problem/B
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

void setup(vector<pair<int, int>> &s, ll left, ll right, ll cur)
{
	if (left == right)
	{
		s[cur] = {left, 0};
		return ;
	}
	int mid = left + (right - left) / 2;
	setup(s, left, mid, cur*2 + 1);
	setup(s, mid+1, right, cur*2 + 2);
	//
	if (s[cur*2+1].second == 0)
		s[cur] = s[cur*2+1];
	else if (s[cur*2+2].second == 0)
		s[cur] = s[cur*2+2];
	else
		s[cur] = {-1, 1};
}

void update(vector<pair<int, int>> &s, ll idx, ll value, ll left, ll right, ll cur)
{
	if (left == right)
	{
		if (left == idx) s[cur].second += value;
		return ;
	}
	if (idx < left || idx > right) return ;
	int mid = left + (right - left) / 2;
	update(s, idx, value, left, mid, cur*2+1);
	update(s, idx, value, mid+1, right, cur*2+2);
	//
	if (s[cur*2+1].second == 0)
		s[cur] = s[cur*2+1];
	else if (s[cur*2+2].second == 0)
		s[cur] = s[cur*2+2];
	else
		s[cur] = {-1, 1};
}

void solve()
{
	ll n; cin >> n;
	vector<ll> a(n);
	for (ll &i : a)	cin >> i;
	vector<pair<int, int>> sfx((n+1)*4);
	setup(sfx, 0, n, 0);
	for (ll &i : a) update(sfx, i, +1, 0, n, 0);
	vector<pair<int, int>> pfx((n+1)*4);
	setup(pfx, 0, n, 0);
	for (ll i = 0; i+1 < n; i++)
	{
		update(pfx, a[i], +1, 0, n, 0);
		update(sfx, a[i], -1, 0, n, 0);
		if (pfx.front() == sfx.front())
		{
			cout << 2 << "\n";
			cout << 1 << ' ' << i+1 << "\n";
			cout << i+2 << ' ' << n << "\n";
			return ;
		}
	}
	cout << -1 << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t; cin >> t;
	while (t--)
		solve();
}
