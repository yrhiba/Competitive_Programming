/*
B. Symmetric Encoding

time limit per test: 2 second
memory limit per test: 256 megabytes
input: standard input
output: standard output

link to the problem:
https://codeforces.com/contest/1974/problem/B
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
	set<char> st;
	string r = "";
	for (char c : s)
		if (!st.count(c))
		{
			st.insert(c);
			r += c;
		}
	sort(r.begin(), r.end());
	map<char, char> mp;
	n = r.size();
	for (int i = 0; i < n; i++) mp[r[i]] = r[n - i - 1];
	string ans = "";
	for (char c : s) ans += mp[c];
	cout << ans << '\n';
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
