/*
CSES Problem Set

Room Allocation

link to the problem:
https://cses.fi/problemset/task/1164/
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
	multiset<vector<ll>> st;
	for (ll i = 0; i < n; i++)
	{
		ll a, b; cin >> a >> b;
		st.insert({a, b, i});
	}
	//
	ll maxRooms = 0;
	vector<ll> ans(n);
	//
	while (!st.empty())
	{
		ll id = ++maxRooms, room = (*st.begin())[2], roomEnd = (*st.begin())[1];
		ans[room] = id;
		st.erase(st.begin());
		//
		while (true)
		{
			auto it = st.lower_bound({roomEnd+1, 0, 0});
			if (it == st.end()) break;
			room = (*it)[2];
			roomEnd = (*it)[1];
			ans[room] = id;
			st.erase(it);
		}
	}
	//
	cout << maxRooms << "\n";
	for (ll i = 0; i < n; i++)
		cout << ans[i] << " \n"[i+1 == n];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
