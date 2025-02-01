/*
684. Redundant Connection

Medium

link to the problem:
https://leetcode.com/problems/redundant-connection/
*/
class DisjointSet
{
public: 
	vector<int> rank, parent, size;
	int cnt;
	DisjointSet(int n)
	{
		rank.resize(n+1);       // n+1 if the graph is 1 based
		parent.resize(n+1);
		for(int i=0; i<=n; i++)
			parent[i] = i;
		size.resize(n+1, 1);
		cnt = n;
	}
	int    findUPar(int node)                //findultimateparent
	{
		if (node == parent[node])
			return node;
		return parent[node] = findUPar(parent[node]);   // path compression (max : log n)
	}
	void    unionByRank(int u, int v)
	{
		int ulp_u = findUPar(u);
		int ulp_v = findUPar(v);
		if (ulp_v == ulp_u)   // already connected(same ul_parent)
			return ;
		if (rank[ulp_v] < rank[ulp_u])
			parent[ulp_v] = ulp_u;
		else if (rank[ulp_u] < rank[ulp_v])
			parent[ulp_u] = ulp_v;
		else
		{
			parent[ulp_v] = ulp_u;
			rank[ulp_u]++;
		}
		cnt--;
	}
	void    unionBySize(int u, int v)
	{
		int ulp_u = findUPar(u);
		int ulp_v = findUPar(v);
		if (ulp_u == ulp_v)
			return ;
		if (size[ulp_u] < size[ulp_v])
		{
			parent[ulp_u] = ulp_v;
			size[ulp_v]  += size[ulp_u];
		}
		else
		{
			parent[ulp_v] = ulp_u;
			size[ulp_u] += size[ulp_v];
		}
		cnt--;
	}
};

class Solution {
public:
	vector<int> findRedundantConnection(vector<vector<int>>& edges)
	{
		int n = edges.size(), cur_color = 0;
		//
		DisjointSet g = DisjointSet(n);
		//
		for (auto &v : edges)
		{
			int a = v[0], b = v[1];
			if (g.findUPar(a) == g.findUPar(b)) return v;
			g.unionBySize(a, b);
		}
		return vector<int>();
	}
};
