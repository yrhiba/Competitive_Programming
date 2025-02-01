/*
link to the problem:
https://leetcode.com/problems/remove-nth-node-from-end-of-list
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
	ListNode* removeNthFromEnd(ListNode* head, int n) {

		ListNode *it;

		int size = 0;
		it = head;
		while (it)
		{
			size += 1;
			it = it->next;
		}

		n = size - n + 1;

		if (n == 1)
			return (head = head->next);

		it = head;
		int i = 1;
		while (it)
		{
			if ((i+1) == n)
			{
				it->next = it->next->next;
				break ;
			}
			it = it->next;
			i++;
		}
		return (head);
	}
};