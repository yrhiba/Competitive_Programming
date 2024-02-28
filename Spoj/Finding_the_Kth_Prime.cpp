/*
TDKPRIME - Finding the Kth Prime

#sieve-of-eratosthenes

link to the problem:
https://www.spoj.com/problems/TDKPRIME/
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
# define ll long long
using namespace std;

bool	isprime[90000001];
int		prime[5000001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	//
	isprime[0] = isprime[1] = true;
	for (int i = 2; i*i < 90000001; i++)
	{
		if (isprime[i]) continue;
		for (int x = i*i; x < 90000001; x+=i) isprime[x] = true;
	}
	for (int j = 0, i = 0; j < 5000001; i++)
	{
		if (isprime[i]) continue;
		prime[j++] = i;
	}
	//
	int t, q; cin >> t;
	while (t--)
	{
		cin >> q;
		cout << prime[--q] << "\n";
	}
}
