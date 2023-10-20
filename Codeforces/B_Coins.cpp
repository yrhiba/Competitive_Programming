/*
link to the problem:
https://codeforces.com/contest/47/problem/B
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
void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}
ll power(ll x, ll p)
{
	if (p == 0) return (1);
	ll res = power(x, p/2);
	if (p%2)
		return ((res * res) * x);
	return (res * res);
}
ll gcd(ll a, ll b)
{
	if (b == 0) return (a);
	return (gcd(b, a%b));
}
ll lcm(ll a, ll b)
{
	return ((a*b)/gcd(a, b));
}

void dfs(map<char, string> &graph, char letter, map<char, bool> &printed, map<char, bool> &visited, string &ans)
{
	if (ans.size() >= 3)
	{
		cout << ans << endl;
		exit(0);
	}

	visited[letter] = true;

	for (ll i = 0; i < graph[letter].size(); i++)
	{
		if (printed[graph[letter][i]]) continue;
		if (visited[graph[letter][i]])
		{
			cout << "Impossible" << endl;
			exit(0);
		}
		dfs(graph, graph[letter][i], printed, visited, ans);
	}

	visited[letter] = false;

	ans += letter; printed[letter] = true;
}

void solve()
{
	map<char, string> graph;

	string ans;

	for (ll i = 0; i < 3; i++)
	{
		string s; cin >> s;

		char a = s[0];
		char o = s[1];
		char b = s[2];

		if (o == '<')
			graph[b] += a;
		else
			graph[a] += b;
	}

	string letters = "ABC";

	map<char, bool> visited;
	map<char, bool> printed;

	for (ll i = 0; i < 3; i++)
	{
		if (printed[letters[i]]) continue;
		dfs(graph, letters[i], printed, visited, ans);
	}

	cout << ans << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
