/*

Death First Search - Episode 1

link to the problem:
https://www.codingame.com/training/medium/death-first-search-episode-1

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#include <map>
#include <set>
#include <queue>

int main()
{
	int n; // the total number of nodes in the level, including the gateways
	int l; // the number of links
	int e; // the number of exit gateways
	cin >> n >> l >> e; cin.ignore();

	map< int, set<int> > g;

	for (int i = 0; i < l; i++) {
		int n1; // N1 and N2 defines a link between these nodes
		int n2;
		cin >> n1 >> n2; cin.ignore();

		// n1 -> n2
		g[n1].insert(n2);
		g[n2].insert(n1);
	}

	set< int > exits;

	for (int i = 0; i < e; i++) {
		int ei; // the index of a gateway node
		cin >> ei; cin.ignore();

		exits.insert(ei);
	}

	// game loop
	while (1) {
 
		int si; // The index of the node on which the Bobnet agent is positioned this turn
		cin >> si; cin.ignore();

		queue<int> que; que.push(si);
		queue<int> par; par.push(-1);

		vector<bool> visited(n+1, false); visited[si] = true;

		bool found = false;

		while (que.size() && par.size())
		{
			int &cur_node = que.front();
			int &cur_par = par.front();

			if (exits.find(cur_node) != exits.end())
			{
				found = true;
				cout << cur_par << " " << cur_node << endl;
				break;
			}

			for (auto &node : g[cur_node])
			{
				if (visited[node]) continue ;
				visited[node] = true;
				que.push(node);
				par.push(cur_node);
			}
			
			que.pop();
			par.pop();
		}

		if (!found) cout << 0 << " " << 0 << endl;
	}
}