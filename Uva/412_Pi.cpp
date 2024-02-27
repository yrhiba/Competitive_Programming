/*
link to the problem:
https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=353
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

ll gcd(ll a, ll b)
{
	if (b == 0) return a;
	return (gcd(b, a%b));
}

void solve(ll n)
{
	vector<ll> a(n);
	for (ll &i : a) cin >> i;
	ll v = 0;
	for (ll i = 0; i < n; i++)
		for (ll j = i+1; j < n; j++)
			v += (gcd(a[i], a[j]) == 1);
	//
	if (!v) cout << "No estimate for this data set.\n";
	else printf("%.6f\n", sqrt( (6 * (n*(n-1)*.5)) / v ));
}

int main()
{
	ll n;
	while (cin >> n)
	{
		if (!n) break;
		solve(n);
	}
}
