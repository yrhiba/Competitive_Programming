/*
link to the problem:
https://codeforces.com/contest/1941/problem/C
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
	string s; cin >> s;
	string P = "pie";
	string M = "map";
	//
	vector< pair<ll,ll> > a;
	//
	ll i = s.find(P);
	while (i != string::npos && i != -1)
	{
		a.push_back({i, 1});
		i = s.find(P, i+1);
	}
	i = s.find(M);
	while (i != string::npos && i != -1)
	{
		a.push_back({i, 2});
		i = s.find(M, i+1);
	}
	sort(a.begin(), a.end());
	ll ans = 0;
	for (ll i = 0; i < a.size(); i++)
	{
		ans += 1;
		//
		if (i+1 < a.size()
			&& a[i].second == 2 
			&& a[i].second != a[i+1].second 
			&& a[i].first + 2 == a[i+1].first)
		{
			i++;
		}
	}
	cout << ans << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t; cin >> t;
	while (t--) solve();
}
