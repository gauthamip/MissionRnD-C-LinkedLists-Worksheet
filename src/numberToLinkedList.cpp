/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.

INPUTS:  A number.

OUTPUT: Create linked list from given number, each digit as a node.

ERROR CASES: 

NOTES: For negative numbers ignore negative sign.
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * numberToLinkedList(int N) {
	struct node *head,*p;
	
	head = NULL;
	p = NULL; 
	if (N < 0)
		N = 0-N;
	
	if (N == 0)
	{
		head = (struct node *)malloc(sizeof(struct node*));
		head->num = N;
		head->next = NULL;
	}
	else
	{
		while (N > 0)
		{
			if (head == NULL)
			{
				head = (struct node *)malloc(sizeof(struct node*));
				head->num = N % 10;
				N = N / 10;
				head->next = NULL;
			}
			else
			{
				p = (struct node*)malloc(sizeof(struct node*));
				p->num = N % 10;
				N = N / 10;
				p->next = head;
				head = p;
			}

		}
		return head;
	}
}