/*
2. Add Two Numbers

Medium

link to the problem:
https://leetcode.com/problems/add-two-numbers

*/
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode() : val(0), next(nullptr) {}
*     ListNode(int x) : val(x), next(nullptr) {}
*     ListNode(int x, ListNode *next) : val(x), next(next) {}
* };
*/
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		ListNode	*it = NULL;
		ListNode	*ans = it;

		int x = 0, r = 0;

		while (l1 && l2)
		{
			x = (l1->val + l2->val + r) % 10;
			r = (l1->val + l2->val + r) / 10;

			if (it == NULL)
			{
				it = new ListNode(x);
				ans = it;
			}
			else
			{
				it->next = new ListNode(x);
				it = it->next;
			}

			l1 = l1->next;
			l2 = l2->next;
		}

		if (!l1) l1 = l2;

		while (l1)
		{
			x = (r + l1->val) % 10;
			r = (r + l1->val) / 10;

			if (it == NULL)
			{
				it = new ListNode(x);
				ans = it;
			}
			else
			{
				it->next = new ListNode(x);
				it = it->next;
			}

			l1 = l1->next;
		}

		while (r)
		{
			it->next = new ListNode(r%10);
			it = it->next;
			r /= 10;
		}

		return (ans);
	}
};
