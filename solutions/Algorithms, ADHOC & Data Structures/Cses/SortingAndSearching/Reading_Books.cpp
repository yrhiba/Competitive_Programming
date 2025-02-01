/*
CSES Problem Set

Reading Books

linkt to the problem:
https://cses.fi/problemset/task/1631/
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
	vector<ll> a(n);
	for (ll &i : a) cin >> i;
	//
	if (n <= 1)
	{
		cout << a[0] * 2 << "\n";
		return ;
	}
	//
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	set<ll> x, y;
	ll s1 = 0, s2 = 0;
	//
	for (ll &i : a)
	{
		if (s1 <= s2)
		{
			s1 += i;
			x.insert(i);
		}
		else
		{
			s2 += i;
			y.insert(i);
		}
	}
	//
	if (s1 == s2) cout << s1 * 2;
	else
	{
		if (s1 < s2) swap(x, y), swap(s1, s2);
		if (s2 >= *(x.begin())) cout << s1 + s2;
		else cout << max(s1, s2) * 2;
	}
	//
	cout << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
