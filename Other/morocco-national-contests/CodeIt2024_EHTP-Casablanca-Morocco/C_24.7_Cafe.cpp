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
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>> , greater<pair<ll, ll>> > pr;
	multiset<ll> tables;

	ll n, m; cin >> n >> m;

	vector<vector<ll>> groups(n, vector<ll>(3));
	for (ll i = 0; i < n; i++)
		for (ll j = 0; j < 3; j++) cin >> groups[i][j];

	sort(groups.begin(), groups.end());

	for (ll i = 0; i < m; i++)
	{
		ll t; cin >> t;
		tables.insert(t);
	}

	ll ans = 0;

	for (ll i = 0, curTime; i < n; i++)
	{
		curTime = groups[i][0];

		while (!pr.empty() && pr.top().first <= curTime)
		{
			tables.insert(pr.top().second);
			pr.pop();
		}

		auto table = tables.lower_bound(groups[i][2]);
		if (table == tables.end()) continue;

		ans += 1;
		pr.push({groups[i][1]+1, *table});
		tables.erase(table);
	}

	cout << ans << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
