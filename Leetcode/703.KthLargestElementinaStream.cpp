/*
703. Kth Largest Element in a Stream

Easy

link to the problem:
https://leetcode.com/problems/kth-largest-element-in-a-stream/
*/
class KthLargest
{
private:
	priority_queue<int> prG;
	priority_queue<int, vector<int>, greater<int> > prN;

public:
	KthLargest(int k, vector<int>& nums) {
		for (int n : nums) prG.push(n);
		for (int i = 0; (i+1) < k; i++)
		{
			prN.push(prG.top());
			prG.pop();
		}
	}

	int add(int val)
	{
		prN.push(val);
		prG.push(prN.top());
		prN.pop();
		return prG.top();
	}
};
