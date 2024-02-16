/*
215. Kth Largest Element in an Array

Medium

link to the problem:
https://leetcode.com/problems/kth-largest-element-in-an-array
*/
class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		priority_queue<int, vector<int>, greater<int>> p;
		for (int i : nums)
		{
			p.push(i);
			if (p.size() > k) p.pop();
		}
		return (p.top()); 
	}
};
