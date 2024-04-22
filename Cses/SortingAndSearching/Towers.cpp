/*
CSES Problem Set

Towers

link to the problem:
https://cses.fi/problemset/task/1073/
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
	ll n, ans = 0; cin >> n;
	vector<ll> a(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	//
	multiset<ll> st;
	//
	for (ll i = 0; i < n; i++)
	{
		ll curCub = a[i];
		//
		auto bestChoice = st.upper_bound(curCub);
		if (bestChoice != st.end()) st.erase(bestChoice);
		else ans += 1;
		st.insert(curCub);
	}
	//
	cout << ans << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
