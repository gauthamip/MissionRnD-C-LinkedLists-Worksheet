/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * sortLinkedList(struct node *head) {
	struct node* p1, *p2, *prev1, *prev2;
	int n = 0, k, temp;
	p1 = p2 = head;
	prev1 = prev2 = NULL;
	while (p1 != NULL)
	{
		n++;
		p1 = p1->next;
	}
	p1 = head;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			p1 = p2 = head;
			k = 0;
			while (k < j)
			{
				prev1 = p1;
				p1 = p1->next;
				k++;
			}
			prev2 = p1;
			p2 = p1->next;
			if ((p1->num)>(p2->num))
			{
				temp = p1->num;
				p1->num = p2->num;
				p2->num = temp;
			}
		}
	}
	return head;
}