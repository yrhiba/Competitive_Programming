/*
FORM USACO GUIDE

Fence Painting
Bronze - Very Easy

link to the problem:
http://www.usaco.org/index.php?page=viewproblem2&cpid=567

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
ll mod = 1000000007;
using namespace std;
ll powermod(ll x, ll p)
{
	if (p == 0) return (1);
	ll res = powermod(x, p/2) % mod;
	if (p%2)
		return ((((res * res) % mod) * (x % mod)) % mod);
	return ((res * res) % mod);
}
ll power(ll x, ll p)
{
	if (p == 0) return (1);
	ll res = power(x, p/2);
	if (p%2)
		return ((res * res) * x);
	return (res * res);
}

void solve()
{
	ifstream fin ("paint.in");
	ofstream fout ("paint.out");

	vector< pair<ll, ll> > distances(2);

	for (ll i = 0; i < 2; i++)
		fin >> distances[i].first >> distances[i].second;

	sort(distances.begin(), distances.end());
 
	if (distances[1].first <= distances[0].second)
		distances[1].first = distances[0].second;


	ll ans = 0;

	ans += distances[0].second - distances[0].first;

	if (distances[1].first < distances[1].second)
		ans += distances[1].second - distances[1].first;

	fout << ans << endl;

	fin.close();
	fout.close();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
