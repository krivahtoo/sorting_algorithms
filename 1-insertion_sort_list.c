#include "sort.h"
#include <stdio.h>

/**
 * sorted_insert - insert a new node into the sorted doubly linked list
 *
 * @h: sorted head
 * @n: new node to insert
 */
void sorted_insert(listint_t **h, listint_t *n)
{
	listint_t *cur;

	if (*h == NULL || (*h)->n >= n->n)
	{
		n->next = *h;
		n->prev = NULL;
		if (*h != NULL)
			(*h)->prev = n;
		*h = n;
	}
	else
	{
		cur = *h;

		while (cur->next != NULL && cur->next->n < n->n)
			cur = cur->next;

		n->next = cur->next;
		if (cur->next != NULL)
			cur->next->prev = n;
		cur->next = n;
		n->prev = cur;
	}
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 *
 * @list: linked list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *sorted_end, *cur, *tmp;

	if (*list == NULL || (*list)->next == NULL)
		/* List is empty or has only one element, so it's already sorted */
		return;

	/* Sorted end of the list */
	sorted_end = *list;

	while (sorted_end->next != NULL)
	{
		cur = sorted_end->next;

		if (cur->n >= sorted_end->n)
		{
			sorted_end = cur;
		}
		else
		{
			sorted_end->next = cur->next;
			if (cur->next != NULL)
				cur->next->prev = sorted_end;

			tmp = *list;
			while (tmp != NULL && tmp->n <= cur->n)
				tmp = tmp->next;

			cur->next = tmp;
			cur->prev = tmp->prev;
			if (tmp->prev != NULL)
				tmp->prev->next = cur;
			tmp->prev = cur;
		}
		while ((*list)->prev)
			*list = (*list)->prev;
		print_list(*list);
	}
}
