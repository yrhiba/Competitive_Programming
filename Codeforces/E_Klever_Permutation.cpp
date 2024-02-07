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
	ll n, k; cin >> n >> k;
	set<ll> st;
	set<ll, greater<ll>> rst;
	for (ll i = 1; i <= n; i++)
	{
		st.insert(i);
		rst.insert(i);
	}
	vector<ll> a(n+1, 0);
	ll i = 1;
	while (!st.empty())
	{
		if (i%2)
		{
			for (ll j = i; !st.empty() && j <= n; j+=k)
			{
				a[j] = *st.begin();
				st.erase(a[j]);
				rst.erase(a[j]);
			}
		}
		else
		{
			for (ll j = i; !st.empty() && j <= n; j+=k)
			{
				a[j] = *rst.begin();
				st.erase(a[j]);
				rst.erase(a[j]);
			}
		}
		i+=1;
	}
	for (ll i = 1; i <= n; i++) cout << a[i] << " \n"[i==n];
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
