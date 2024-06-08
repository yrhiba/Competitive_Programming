/*
yrhiba.github.io (c). 2022-2024

E - Reachability in Functional Graph

link to the problem:
https://atcoder.jp/contests/abc357/tasks/abc357_e

Tarjan’s Algorithm to find Strongly Connected Components reference.
https://www.geeksforgeeks.org/tarjan-algorithm-find-strongly-connected-components/
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
#include <list>
# define ull unsigned long long
# define ll long long
#define NIL -1
ll mod = 1e9 + 7;
using namespace std;

vector<ll> sccColors;
ll cur_color = 0;

// A class that represents an directed graph
class Graph {
    int V; // No. of vertices
    list<int>* adj; // A dynamic array of adjacency lists
 
    // A Recursive DFS based function used by SCC()
    void SCCUtil(int u, int disc[], int low[],
                 stack<int>* st, bool stackMember[]);
 
public:
    Graph(int V); // Constructor
    void addEdge(int v,
                 int w); // function to add an edge to graph
    void SCC(); // prints strongly connected components
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w) { adj[v].push_back(w); }
 
// A recursive function that finds and prints strongly
// connected components using DFS traversal u --> The vertex
// to be visited next disc[] --> Stores discovery times of
// visited vertices low[] -- >> earliest visited vertex (the
// vertex with minimum
//             discovery time) that can be reached from
//             subtree rooted with current vertex
// *st -- >> To store all the connected ancestors (could be
// part
//         of SCC)
// stackMember[] --> bit/index array for faster check
// whether
//                 a node is in stack
void Graph::SCCUtil(int u, int disc[], int low[],
                    stack<int>* st, bool stackMember[])
{
    // A static variable is used for simplicity, we can
    // avoid use of static variable by passing a pointer.
    static int time = 0;
 
    // Initialize discovery time and low value
    disc[u] = low[u] = ++time;
    st->push(u);
    stackMember[u] = true;
 
    // Go through all vertices adjacent to this
    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i) {
        int v = *i; // v is current adjacent of 'u'
 
        // If v is not visited yet, then recur for it
        if (disc[v] == -1) {
            SCCUtil(v, disc, low, st, stackMember);
 
            // Check if the subtree rooted with 'v' has a
            // connection to one of the ancestors of 'u'
            // Case 1 (per above discussion on Disc and Low
            // value)
            low[u] = min(low[u], low[v]);
        }
 
        // Update low value of 'u' only of 'v' is still in
        // stack (i.e. it's a back edge, not cross edge).
        // Case 2 (per above discussion on Disc and Low
        // value)
        else if (stackMember[v] == true)
            low[u] = min(low[u], disc[v]);
    }
 
    // head node found, pop the stack and print an SCC
    int w = 0; // To store stack extracted vertices
    if (low[u] == disc[u]) {
        while (st->top() != u) {
            w = (int)st->top();
            // cout << w << " ";
			sccColors[w] = cur_color;
            stackMember[w] = false;
            st->pop();
        }
        w = (int)st->top();
		sccColors[w] = cur_color;
        // cout << w << "\n";
        stackMember[w] = false;
        st->pop();
		cur_color += 1;
    }
}
 
// The function to do DFS traversal. It uses SCCUtil()
void Graph::SCC()
{
    int* disc = new int[V];
    int* low = new int[V];
    bool* stackMember = new bool[V];
    stack<int>* st = new stack<int>();
 
    // Initialize disc and low, and stackMember arrays
    for (int i = 0; i < V; i++) {
        disc[i] = NIL;
        low[i] = NIL;
        stackMember[i] = false;
    }
 
    // Call the recursive helper function to find strongly
    // connected components in DFS tree with vertex 'i'
    for (int i = 0; i < V; i++)
        if (disc[i] == NIL)
            SCCUtil(i, disc, low, st, stackMember);
}

bool dfs(vector<vector<ll>> &g, vector<bool> &vis, ll cur, const ll &target)
{
	if (cur == target) return (true);
	vis[cur] = true;
	for (ll nxt : g[cur])
		if (!vis[nxt] && dfs(g, vis, nxt, target)) return (true);
	//
	return (false);
}

bool isPath(vector<vector<ll>> &g, ll start_node, ll target_node)
{
	vector<bool> vis(g.size(), false);
	return (dfs(g, vis, start_node, target_node));
}

vector<ll> scc(ll n, vector<vector<ll>> &g)
{
	vector<ll> sccColors(n, -1);

	for (ll i = 0, curColor = 0; i < n; i++)
	{
		if (sccColors[i] != -1) continue;

		sccColors[i] = curColor++;

		for (ll j = i+1; j < n; j++)
			if (isPath(g, i, j) && isPath(g, j, i)) sccColors[j] = sccColors[i];
	}

	return sccColors;
}

ll rec
	(
		vector<ll> &sccColorsCount,
		vector<set<ll>> &sccGraph,
		vector<ll> &dp,
		ll cur
	)
{
	if (dp[cur] != -1) return dp[cur];

	dp[cur] = 0;

	for (ll nxt : sccGraph[cur])
	{
		dp[cur] += rec(sccColorsCount, sccGraph, dp, nxt);
	}

	dp[cur] += sccColorsCount[cur];

	return dp[cur];
}

void solve()
{
	ll n; cin >> n;
	Graph testGraph(n);
	vector<vector<ll>> g(n);
	for (ll i = 0; i < n; i++)
	{
		ll t; cin >> t; t -= 1;
		g[i].push_back(t);
		testGraph.addEdge(i, t);
	}
	//
	sccColors = vector<ll>(n, -1);
	// scc(n, g);
	testGraph.SCC();
	vector<ll> sccColorsCount(n, 0);
	for (int c : sccColors) sccColorsCount[c] += 1;
	//
	vector<set<ll>> sccGraph(n);
	for (ll i = 0; i < n; i++)
		for (ll j : g[i])
			if (sccColors[i] != sccColors[j])
				sccGraph[sccColors[i]].insert(sccColors[j]);
	//
	ll ans = 0;
	vector<ll> dp(n, -1);
	for (ll i = 0; i < n; i++) rec(sccColorsCount, sccGraph, dp, i);
	//
	for (ll i = 0; i < n; i++)
		ans += dp[sccColors[i]];
	//
	cout << ans << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
