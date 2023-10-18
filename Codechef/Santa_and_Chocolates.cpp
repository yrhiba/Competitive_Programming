/*
Starters 104

link to the problem:
https://www.codechef.com/START104D/problems/SANTACHOC
*/
#include <iostream>

using namespace std;

# define ll long long

void solve()
{
	ll n, k; cin >> n >> k;

	ll chokolate_sum = 0;
	for (ll i = 0; i < n; i++)
	{
		ll t; cin >> t;
		chokolate_sum += t;
	}

	if (chokolate_sum < n)
	{
		cout << "NO" << "\n";
		return ;
	}

	ll max_chock_for_1 = (chokolate_sum / n) + (chokolate_sum % n > 0);
	ll min_chock_for_1 = (chokolate_sum / n);

	if (abs(max_chock_for_1 - min_chock_for_1) > k)
	{
		cout << "NO" << "\n";
		return ;
	}

	cout << "YES" << "\n";
}

int main() {

	ll t; cin >> t;

	for (ll i = 0; i < t; i++)
		solve();

	return 0;
}
