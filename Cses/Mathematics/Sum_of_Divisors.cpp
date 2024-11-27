/*
yrhiba.github.io (c). 2022-2024
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
#include <cassert>
#include <random>
#include <sstream>
using namespace std;
typedef long long ll;
const int mod = int(1e9 + 7);

/* solution */
void solve()
{
	ll n; cin >> n;
	vector<ll> divs;
	divs.reserve(1e6);
	for (ll i = 2; i*i <= n; i++) {
		divs.push_back(i);
		if (n/i != i) {
			divs.push_back(n/i);
		}
	}
	sort(divs.begin(), divs.end());
	if (n > 1) divs.push_back(n);
	ll ans = n % mod, lastDivs = 1;
	for (ll d : divs) {
		ll toAdd =
			(((((((d - lastDivs + mod) % mod) 
				* (((lastDivs + 1) + d) % mod)) % mod) * 500000004) % mod)
				* ((n / d) % mod));
		ans += toAdd % mod;
		ans %= mod;
		lastDivs = d;
	}
	cout << ans << '\n';
}

/* main funciton */
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	solve();
	return (0);
}
