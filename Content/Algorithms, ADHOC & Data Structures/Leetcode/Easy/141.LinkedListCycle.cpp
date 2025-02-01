/*

141. Linked List Cycle

Easy

link to the problem:
https://leetcode.com/problems/linked-list-cycle

*/
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	bool hasCycle(ListNode *head)
	{
		if (!head) return (false);

		ListNode *s = head;
		ListNode *f = head->next;

		while (f)
		{
			if (f == s)
				return (true);
		
			s = s->next;
			f = f->next ? f->next->next : f->next;
		}

		return (false);
	}
};
