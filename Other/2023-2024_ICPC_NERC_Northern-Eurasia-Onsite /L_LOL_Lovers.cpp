/*

2023-2024 ICPC, NERC, Northern Eurasia Onsite 
(Unrated, Online Mirror, ICPC Rules, Teams Preferred)

L. LOL Lovers

link to the problem:
https://codeforces.com/contest/1912/problem/L

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

	vector<ll> pl(n+1, 0);
	vector<ll> po(n+1, 0);

	for (ll i = 0; i < n; i++)
	{
		pl[i+1] = pl[i] + (s[i] == 'L');
		po[i+1] = po[i] + (s[i] == 'O');
	}

	for (ll i = 1; i < n; i++)
	{
		if ((pl[i] + po[i]) && ((pl.back() - pl[i]) + (po.back() - po[i]))
			&& (pl[i] != (pl.back() - pl[i])) && (po[i] != (po.back() - po[i]))
		)
		{
			cout << i << '\n';
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
	solve();
}
