/*
C. LR-remainders

link to the problem:
https://codeforces.com/contest/1932/problem/C
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
#include <numeric>
# define ull unsigned long long
# define ll long long
const ll mod = 1e9 + 7;
using namespace std;

ll m;

void setup(vector<ll> &seg, vector<ll> &a, ll left, ll right, ll cur)
{
	if (left == right)
	{
		seg[cur] = a[left]%m;
		return ;
	}
	ll mid = left+(right-left)/2;
	setup(seg, a, left, mid, cur*2+1);
	setup(seg, a, mid+1, right, cur*2+2);
	seg[cur] = seg[cur*2+1]*seg[cur*2+2];
	seg[cur] %= m;
}

ll query(vector<ll> &seg, ll ql, ll qr, ll left, ll right, ll cur)
{
	if (ql <= left && right <= qr) return seg[cur];
	if (ql > right || left > qr) return -1;
	ll mid = left+(right-left)/2;
	ll q1 = query(seg, ql, qr, left, mid, cur*2+1);
	ll q2 = query(seg, ql, qr, mid+1, right, cur*2+2);
	if (q1 == -1) return q2;
	if (q2 == -1) return q1;
	return (q1*q2)%m;
}

void solve()
{
	ll n; cin >> n >> m;
	vector<ll> a(n);
	for (auto &i : a) cin >> i;
	vector<ll> seg(n*4);
	setup(seg, a, 0, n-1, 0);
	string s; cin >> s;
	ll left = 0, right = n-1;
	for (char c : s)
	{
		cout << query(seg, left, right, 0, n-1, 0) << " ";
		if (c == 'L') left += 1;
		else right -= 1;
	}
	cout << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t; cin >> t;
	while (t--) solve();
}
