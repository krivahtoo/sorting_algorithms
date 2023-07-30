#include "sort.h"
#include <stdio.h>

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
