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
#include <cstring>
using namespace std;
# define all(x) begin(x), end(x)
# define rall(x) rbegin(x), rend(x)

/* solution */
int a[int(1e6 + 1)];

void solve()
{
    memset(a, 0, 1e6+1);
    
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t; cin >> t;
        a[t] += 1;
    }

    int ans = 1;

    for (int i = 2; i <= int(1e6); i++)
    {
        for (int j = i, cur = 0; j <= int(1e6); j+=i)
        {
            if (a[j]) {
                cur += a[j];
                if (cur >= 2) {
                    ans = i;
                    break;
                }
            }
        }
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
