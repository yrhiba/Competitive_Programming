/*
D. Card Game

link to the problem:
https://codeforces.com/contest/1932/problem/D
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
	ll n; cin >> n; n *= 2;
	char c; cin >> c;
	map<char, set<int>> mp;
	for (ll i = 0; i < n; i++)
	{
		string s; cin >> s;
		mp[s[1]].insert(s[0]-'0');
	}
	vector< pair<string, string> > ans; ans.reserve(n+2);
	for (auto &[i, v]:mp)
	{
		while ((i!=c) && v.size() >= 2)
		{
			pair<string, string> cur = {"", ""};
			cur.first += (char)(*v.begin() + '0'); v.erase(v.begin());
			cur.second += (char)(*v.begin() + '0'); v.erase(v.begin());
			cur.first += i;
			cur.second += i;
			ans.push_back(cur);
		}
	}
	vector<int> toe;
	for (auto &v : mp[c])
		for (auto &[i, q] : mp)
			if ((i!=c) && !q.empty())
			{
				pair<string, string> cur = {"", ""};
				cur.first += (char)(*q.begin() + '0'); q.erase(q.begin());
				cur.second += (char)(v + '0');
				cur.first += i;
				cur.second += c;
				ans.push_back(cur);
				toe.push_back(v);
				break;
			}
	for (int i : toe) mp[c].erase(i);
	while (mp[c].size() >= 2)
	{
		pair<string, string> cur = {"", ""};
		cur.first += (char)(*mp[c].begin() + '0'); mp[c].erase(mp[c].begin());
		cur.second += (char)(*mp[c].begin() + '0'); mp[c].erase(mp[c].begin());
		cur.first += c;
		cur.second += c;
		ans.push_back(cur);
	}
	if (ans.size() != n/2)
	{
		cout << "IMPOSSIBLE\n";
		return ;
	}
	for (auto &[i, j] : ans)
		cout << i << " " << j << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t; cin >> t;
	while (t--) solve();
}
