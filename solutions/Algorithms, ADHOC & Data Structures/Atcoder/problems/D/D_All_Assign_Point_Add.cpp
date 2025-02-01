/*
D - All Assign Point Add

link to the problem:
https://atcoder.jp/contests/abc278/tasks/abc278_d
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

void solve()
{
	ll n; cin >> n;
	vector<ll> a(n);
	for (ll &i : a) cin >> i;
	ll assigne = -1, assigneTime = -1, time = 0;
	vector< pair<ll, ll> > adds(n, {0, time});
	ll q; cin >> q;
	while (time < q)
	{
		ll t; cin >> t;
		if (t == 1)
		{
			ll xq; cin >> xq;
			assigne = xq;
			assigneTime = time;
		}
		else if (t == 2)
		{
			ll i, xq; cin >> i >> xq; i--;
			if (adds[i].second >= assigneTime) adds[i].first += xq;
			else adds[i] = {xq, time};
		}
		else if (t == 3)
		{
			ll i; cin >> i; i--;
			if (assigne == -1) cout << a[i] + adds[i].first << "\n";
			else
			{
				cout << assigne + ((adds[i].second >= assigneTime) ? adds[i].first : 0);
				cout << "\n";
			}
		}
		time += 1;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
