/*
CSES Problem Set

Collecting Numbers II

link to the problem:
https://cses.fi/problemset/task/2217
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
	ll n, m; cin >> n >> m;
	vector<ll> a(n+2), lt(n+2);
	//
	a[0] = lt[0] = 0;
	a[n+1] = lt[n+1] = n+1;
	//
	for (ll i = 1; i <= n; i++)
	{
		cin >> lt[i];
		a[lt[i]] = i;
	}
	//
	vector<bool> comp(n+2, false);
	//
	for (ll i = 0; i <= n; i++) comp[i] = (a[i] > a[i+1]);
	//
	ll ans = 1;
	for (bool c : comp) ans += c;
	//
	//
	while (m--)
	{
		ll x, y; cin >> x >> y;
		//
		swap(a[lt[x]], a[lt[y]]);
		swap(lt[x], lt[y]);
		//
		set<ll> idxToCheck;
		//
		idxToCheck.insert(lt[x]-1);
		idxToCheck.insert(lt[x]);
		idxToCheck.insert(lt[y]-1);
		idxToCheck.insert(lt[y]);
		//
		for (ll t : idxToCheck)
		{
			if (comp[t] != (a[t] > a[t+1]))
			{
				comp[t] = (a[t] > a[t+1]);
				if (comp[t]) ans += 1;
				else ans -= 1;
			}
		}
		//
		cout << ans << endl;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
