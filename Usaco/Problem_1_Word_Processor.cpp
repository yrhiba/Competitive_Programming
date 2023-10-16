/*
Bronze	
Word Processor
Easy

link to the problem:
http://www.usaco.org/index.php?page=viewproblem2&cpid=987
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

void solve()
{
	ll n, k; cin >> n >> k;

	vector< vector<string> > ans;

	vector<string> line;

	ll c = 0;
	for (ll i = 0; i < n; i++)
	{
		string s; cin >> s;

		if (c + s.size() <= k)
		{
			line.push_back(s);
			c += s.size();
		}
		else
		{
			ans.push_back(line);
			line.clear();
			line.push_back(s);
			c = s.size();
		}
	}

	if (line.size())
		ans.push_back(line);

	for (ll i = 0; i < ans.size(); i++)
	{
		for (ll j = 0; j < ans[i].size(); j++)
		{
			cout << ans[i][j];
			if (j+1 < ans[i].size())
				cout << " ";
		}
		cout << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	// TO TEST LOCALY PLEASE COMMENT THIS LINE
	setIO("word");
	solve();
}
