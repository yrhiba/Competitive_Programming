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
	ll n, m, a, b; cin >> n >> m >> a >> b;
	vector< vector < ll > > g(n, vector<ll>(m, 0));

	ll subRowSize = n/a;
	ll subColSize = m/b;
	ll t = a*b;

	for (ll SubRow = 0; SubRow < subRowSize; SubRow++)
		for (ll subCol = 0; subCol < subColSize; subCol++)
		{
			for (ll i = 0, x = (subCol*b); i < a; i++, x+=b)
			{
				vector<ll> toPut(b);
				for (ll y = 0; y < b; y++) toPut[y] = (x+y)%t;

				for (ll j = 0; j < b; j++)
				{
					g[(SubRow*a)+i][(subCol*b)+j] = toPut[(j+SubRow)%b]+1;
				}
			}
		}

	for (ll i = 0; i < n; i++)
		for (ll j = 0; j < m; j++)
			cout << g[i][j] << " \n"[j+1==m];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
