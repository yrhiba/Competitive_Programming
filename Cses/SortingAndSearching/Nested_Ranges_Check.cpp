/*
CSES Problem Set

Nested Ranges Check

link to the problem:
https://cses.fi/problemset/task/2168/
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

bool comp_one(const pair<ll, ll> &a, const pair<ll, ll> &b)
{
	if (a.first != b.first) return a.first < b.first;
	return a.second > b.second;
}

bool comp_two(const pair<ll, ll> &a, const pair<ll, ll> &b)
{
	if (a.second != b.second) return a.second < b.second;
	return a.first > b.first;
}

void solve()
{
	ll n, idx = 0; cin >> n;
	vector<pair<ll, ll>> a(n);
	map<pair<ll, ll>, ll> mp;
	for (auto &[i, j] : a)
	{
		cin >> i >> j;
		mp[{i, j}] = idx++;
	}
	//
	vector<bool> ans1(n, false);
	sort(a.begin(), a.end(), comp_one);
	//
	set<ll> st;
	for (auto &[i, j] : a)
	{
		if (st.lower_bound(j) != st.end()) ans1[mp[{i, j}]] = true;
		st.insert(j);
	}
	//
	vector<bool> ans2(n, false);
	sort(a.begin(), a.end(), comp_two);
	//
	st = set<ll>();
	for (auto &[i, j] : a)
	{
		if (st.lower_bound(i) != st.end()) ans2[mp[{i, j}]] = true;
		st.insert(i);
	}
	//
	for (ll i = 0; i < n; i++)
		cout << (ans2[i] ? 1 : 0) << " \n"[i+1 == n];
	//
	for (ll i = 0; i < n; i++)
		cout << (ans1[i] ? 1 : 0) << " \n"[i+1 == n];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
