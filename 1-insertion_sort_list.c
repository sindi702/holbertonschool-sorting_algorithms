#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

#include "sort.h"

/**
 * insertion_sort_list - implementation of the insertion sort algorithm 
 * @list: doubly linked list to be sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *tmp;

	if (list == NULL)
		return;
	tmp = (*list)->next;
	while (tmp)
	{
		while (tmp->prev != NULL && tmp->prev->n > tmp->n)
		{
			tmp->prev->next = tmp->next;
			if (tmp->next != NULL)
				tmp->next->prev = tmp->prev;
			tmp->next = tmp->prev;
			tmp->prev = tmp->next->prev;
			tmp->next->prev = tmp;
			if (tmp->prev != NULL)
				tmp->prev->next = tmp;
			else
				*list = tmp;
			print_list(*list);
		}
		tmp = tmp->next;
	}
}
