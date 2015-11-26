/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * removeEveryKthNode(struct node *head, int K)
{
	int i = 1, j = 0, n = 1;
	struct node* p, *prev;
	prev = NULL;
	p = head;
	while (p != NULL)
	{
		j++;
		p = p->next;
	}
	p = head;
	if (K == 1 || K == 0 || K < 0)
		head = NULL;
	else
	{
		for (n = 1; n <= j; n++)
		{
			if (n%K == 0)
			{
				while (i < n)
				{
					prev = p;
					p = p->next;
					i++;
				}
				if (p->next == NULL)
					prev->next = NULL;
				else
					prev->next = p->next;
			}
		}
	}
	return head;
}


