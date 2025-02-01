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

void solve()
{
	ll n, q; cin >> n >> q;

	set<pair<ll, ll>> inc;
	set<pair<ll, ll>, greater<pair<ll, ll>>> dec;

	map<ll, ll> mp;

	for (int i = 1; i <= n; i++)
	{
		mp[i] = 0;
		//
		inc.insert({0, i});
		dec.insert({0, -i});
	}

	for (ll i = 0; i < q; i++)
	{
		ll type; cin >> type;

		if (type == 1 || type == 2)
		{
			ll x, y; cin >> x >> y;

			inc.erase({mp[y], y});
			dec.erase({mp[y], -y});

			if (type == 1) mp[y] += x;
			else if (type == 2) mp[y] -= x;

			inc.insert({mp[y], y});
			dec.insert({mp[y], -y});
		}
		else if (type == 3)
		{
			cout << abs(dec.begin()->second) << '\n';
		}
		else if (type == 4)
		{
			cout << inc.begin()->second << '\n';
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
