/*
OVERVIEW:  Given a single linked list of 0s 1s and 2s ,Sort the SLL such that zeroes 
will be followed by ones and then twos.


INPUTS:  SLL head pointer

OUTPUT: Sorted SLL ,Head should Finally point to an sll of sorted 0,1,2


ERROR CASES:

NOTES: Only 0,1,2, will be in sll nodes
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int data;
	struct node *next;
};

void sll_012_sort(struct node *head){
	int count0 = 0, count1 = 0, count2 = 0;
	struct node *p, *t;
	p = head;
	while (p != NULL)
	{
		if (p->data == 0)
			count0++;
		else if (p->data == 1)
			count1++;
		else
			count2++;
		p = p->next;
	}
	t = head;
	while (t != NULL)
	{
		while (count0 != 0)
		{
			t->data = 0;
			count0--;
			t = t->next;
		}
		while (count1 != 0)
		{
			t->data = 1;
			count1--;
			t = t->next;
		}
		while (count2 != 0)
		{
			t->data = 2;
			count2--;
			t = t->next;
		}

	}
	head = t;
}