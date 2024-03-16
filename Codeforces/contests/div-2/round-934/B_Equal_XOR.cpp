/*
link to the problem:
https://codeforces.com/contest/1944/problem/B
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
	ll n, k; cin >> n >> k;
	multiset<ll> a, b;
	vector<ll> Arepeated, Brepeated;
	for (ll i = 0; i < n; i++)
	{
		ll t; cin >> t;
		a.insert(t);
		if (a.count(t) == 2)
		{
			Arepeated.push_back(t);
			a.erase(t);
		}
	}
	for (ll i = 0; i < n; i++)
	{
		ll t; cin >> t;
		b.insert(t);
		if (b.count(t) == 2)
		{
			Brepeated.push_back(t);
			b.erase(t);
		}
	}
	//
	vector<ll> ans1, ans2;
	for (ll i = 0; i < min(Arepeated.size(), Brepeated.size()); i+=1)
	{
		ans1.push_back(Arepeated[i]);
		ans1.push_back(Arepeated[i]);
		ans2.push_back(Brepeated[i]);
		ans2.push_back(Brepeated[i]);
	}
	for (ll i : a) ans1.push_back(i);
	for (ll i : b) ans2.push_back(i);
	//
	for (ll i = 0; i < 2*k; i++) cout << ans1[i] << " \n"[i+1 == 2*k];
	for (ll i = 0; i < 2*k; i++) cout << ans2[i] << " \n"[i+1 == 2*k];
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
