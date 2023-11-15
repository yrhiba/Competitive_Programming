/*

Medium Problem.

133. Clone Graph

link to the problem:
https://leetcode.com/problems/clone-graph

*/

/*
// Definition for a Node.
class Node {
public:
	int val;
	vector<Node*> neighbors;
	Node() {
		val = 0;
		neighbors = vector<Node*>();
	}
	Node(int _val) {
		val = _val;
		neighbors = vector<Node*>();
	}
	Node(int _val, vector<Node*> _neighbors) {
		val = _val;
		neighbors = _neighbors;
	}
};
*/

class Solution {

	map<int, Node*> clon_nodes;

public:

	Node* cloneGraph(Node* node) {

		if (!node)
			return (NULL);

		if (clon_nodes.find(node->val) != clon_nodes.end())
			return (clon_nodes[node->val]);

		clon_nodes[node->val] = new Node(node->val);

		for (auto n : node->neighbors)
		{
			if (clon_nodes.find(n->val) == clon_nodes.end())
				clon_nodes[n->val] = cloneGraph(n);

			(clon_nodes[node->val]->neighbors).push_back(clon_nodes[n->val]);
		}

		return (clon_nodes[node->val]);
	}
};
