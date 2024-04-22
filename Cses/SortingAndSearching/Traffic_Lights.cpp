/*
CSES Problem Set

Traffic Lights

link to the problem:
https://cses.fi/problemset/task/1163/
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
	ll x, n; cin >> x >> n;
	vector<ll> a(n);
	for (ll i = 0; i < n; i++) cin >> a[i];
	//
	set<ll> st; st.insert(0); st.insert(x);
	multiset<ll, greater<ll>> ans; ans.insert(x - 0);
	//
	for (ll i = 0; i < n; i++)
	{
		ll curP = a[i];
		//
		auto t = st.lower_bound(curP);
		//
		ll up = *t;
		ll lw = *(--t);
		//
		ans.erase(ans.find(up - lw));
		//
		ans.insert(curP - lw);
		ans.insert(up - curP);
		//
		st.insert(curP);
		//
		cout << *ans.begin() << " \n"[i+1 == n];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
