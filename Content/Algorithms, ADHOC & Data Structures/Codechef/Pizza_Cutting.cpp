/*
Starters 104

link to the problem:
https://www.codechef.com/START104D/problems/PIZZAC
*/
#include <iostream>

using namespace std;

int main() {

	int t; cin >> t;

	for (int i =0; i < t; i++)
	{
		int n; cin >> n;

		if (n == 1 || (n > 1 && n%2 == 0))
			cout << "YES";
		else
			cout << "NO";

		cout << "\n";
	}
	return 0;
}
