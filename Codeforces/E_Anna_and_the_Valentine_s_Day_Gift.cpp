/*
E. Anna and the Valentine's Day Gift

link to the problem:
https://codeforces.com/contest/1931/problem/E
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
	ll n, m; cin >> n >> m;
	vector<string> a(n);
	vector<ll> leadingZeros;
	ll ans = 0;
	for (string &i : a)
	{
		cin >> i;
		for (int x = i.size(); x > 0; x--)
			if (i[x-1] != '0')
			{
				ans += x;
				if (x < i.size()) leadingZeros.push_back(i.size() - x);
				break;
			}
	}
	sort(leadingZeros.rbegin(), leadingZeros.rend());
	for (ll i = 1; i < leadingZeros.size(); i+=2) ans += leadingZeros[i];
	cout << ((ans<=m) ? "Anna" : "Sasha") << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t; cin >> t;
	while (t--)	solve();
}
