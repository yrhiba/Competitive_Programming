/*

Starters 112 Division 3 (Rated)

Cursed Indices

link to the problem:
https://www.codechef.com/problems/CURSED

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

void solve()
{
	ll n; cin >> n;
	multiset<ll, greater<ll> > g;
	multiset<ll> l;
	vector<ll>	ans;
	for (ll i = 0; i < n; i++)
	{
		ll t; cin >> t;
		g.insert(t);
		l.insert(t);
	}
	auto f = l.begin();
	ans.push_back(*f);
	g.erase(g.find(*f));
	l.erase(f);
	ll	acc = ans.back(), count = 0;
	while (!g.empty() && !l.empty())
	{
		auto x = l.upper_bound(acc);
		if (x == l.end())
		{
			count += 1;
			auto y = g.lower_bound(acc);
			ans.push_back(*y);
			l.erase(l.find(*y));
			g.erase(y);
		}
		else
		{
			ans.push_back(*x);
			g.erase(g.find(*x));
			l.erase(x);
		}
		acc += ans.back();
	}
	cout << count << "\n";
	for (ll i = 0; i < ans.size(); i++)
		cout << ans[i] << " \n"[i+1 == ans.size()];
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
