#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <climits>
#include <iomanip>
#include <numeric>
using namespace std;
#define int long long
#define double long double
#define vi vector <int>
#define vb vector <bool>
#define vs vector <string>
#define vvi vector <vi>
#define vvb vector <vb>
#define vvs vector <vs>
#define all(x) x.begin(), x.end()
#define	rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define ll long long
const int mod = 1e9+7;
const int maxn = 1e5 + 10;

ll dr[] = {1, -1, 0, 0};
ll dc[] = {0, 0, 1, -1};
ll n, m;

void xdfs(
vector< string > &g,
pair<ll, set< pair<ll, ll> > > &cur,
vector< pair<ll, set< pair<ll, ll> > > > &connect_X,
vector< vector<bool> > &vis, ll i, ll j)
{
    for (ll d = 0; d < 4; d++)
    {
        ll ni = i + dr[d];
        ll nj = j + dc[d];

        if (ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
        if (vis[ni][nj]) continue;
        if (g[ni][nj] == '.') 
        {
            cur.second.insert({ni, nj});
            continue;
        }
        if (g[ni][nj] != 'x') continue;
        cur.first += 1;
        vis[ni][nj] = true;
        xdfs(g, cur, connect_X, vis, ni, nj);
    }
}

void odfs(
vector< string > &g,
pair<ll, set< pair<ll, ll> > > &cur,
vector< pair<ll, set< pair<ll, ll> > > > &connect_O,
vector< vector<bool> > &vis, ll i, ll j)
{
    for (ll d = 0; d < 4; d++)
    {
        ll ni = i + dr[d];
        ll nj = j + dc[d];
        if (ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
        if (vis[ni][nj]) continue;
        if (g[ni][nj] == '.') 
        {
            cur.second.insert({ni, nj});
            continue;
        }
        if (g[ni][nj] != 'o') continue;
        cur.first += 1;
        vis[ni][nj] = true;
        odfs(g, cur, connect_O, vis, ni, nj);
    }
}

void	solve()
{
    cin >> n >> m;
    vector< string > g(n);
    for (string &s : g) cin >> s;

    vector< pair<ll, set< pair<ll, ll> > > > connect_X;
    vector< pair<ll, set< pair<ll, ll> > > > connect_O;

    vector< vector<bool> > vis(n, vector<bool>(m, false));

    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < m; j++)
        {
            if (vis[i][j]) continue;
            if (g[i][j] == 'x')
            {
                vis[i][j] = true;
                pair<ll, set< pair<ll, ll> > > cur 
                    = make_pair(1, set< pair<ll, ll> >());
                xdfs(g, cur, connect_X, vis, i, j);
                if (cur.second.size() > 1) continue;
                connect_X.push_back(cur);
            }
            else if (g[i][j] == 'o')
            {
                vis[i][j] = true;
                pair<ll, set< pair<ll, ll> > > cur 
                    = make_pair(1, set< pair<ll, ll> >());
                odfs(g, cur, connect_O, vis, i, j);
                if (cur.second.size() > 1) continue;
                connect_O.push_back(cur);
            }
        }
    vector< vector<ll> > u(n, vector<ll>(m, 0));
    vector< vector<ll> > e(n, vector<ll>(m, 0));
    ll ans1 = 0;
    for (auto &v : connect_X)
    {
        if (v.second.size() == 1)
        {
            u[v.second.begin()->first][v.second.begin()->second] += v.first;
            ans1 = max(ans1, u[v.second.begin()->first][v.second.begin()->second]);
        }
    }
    ll ans2 = 0;
    for (auto &v : connect_O)
    {
        if (v.second.size() == 1)
        {
            e[v.second.begin()->first][v.second.begin()->second] += v.first;
            ans2 = max(ans2, e[v.second.begin()->first][v.second.begin()->second]);
        }
    }
    cout << ans1 << " " << ans2 << endl;
}

int32_t	main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--) solve();
}
