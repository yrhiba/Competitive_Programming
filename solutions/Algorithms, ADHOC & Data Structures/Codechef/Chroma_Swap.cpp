/*

Chroma Swap

Starters 109 Division 3

link to the problem:
https://www.codechef.com/problems/ASH57

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

# define ll long long

using namespace std;

void solve()
{
	ll n; cin >> n;

	map<ll, multiset<ll> > mp;

	vector< pair<ll, ll> > a(n+1);
	for (ll i = 1; i <= n; i++)
		cin >> a[i].first;
	for (ll i = 1; i <= n; i++)
		cin >> a[i].second;

	vector<ll> b(n+1);
	for (ll i = 1; i <= n; i++)
		cin >> b[i];
	for (ll i = 1; i <= n; i++)
	{
		ll c; cin >> c;
		mp[c].insert(b[i]);
	}

	vector< bool > can_swap(n+1, false);

	for (ll i = 1; i <= n; i++)
	{
		if (mp.find(a[i].second) == mp.end()) continue;

		can_swap[i] = true;
		mp[a[i].second].insert(a[i].first);
	}


	vector<ll> ans(n+1, -1);

	for (ll i = 1; i <= n; i++)
	{
		if (!can_swap[i])
		{
			if (a[i].first < ans[i - 1])
			{
				cout << "No\n";
				return ;
			}

			ans[i] = a[i].first;
		}
		else
		{
			while (!(mp[a[i].second].empty()) && *(mp[a[i].second].begin()) < ans[i - 1])
				mp[a[i].second].erase(mp[a[i].second].begin());

			if (mp[a[i].second].empty())
			{
				cout << "No\n";
				return ;
			}

			ans[i] = *(mp[a[i].second].begin());
			mp[a[i].second].erase(mp[a[i].second].begin());
		}
	}

	cout << "Yes\n";
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
