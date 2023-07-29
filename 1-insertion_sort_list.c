#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * insertion_sort_list - sort a list using insertion sort algorithm
 * @list: pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *node = NULL, *temp = NULL;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    node = *list;
    node = node->next;

    while (node)
    {
        while (node->prev && node->n < node->prev->n)
        {
            temp = node;

            /* Update adjacent nodes' pointers */
            if (node->next)
                node->next->prev = temp->prev;
            node->prev->next = temp->next;

            /* Update the current node's pointers */
            node = node->prev;
            temp->prev = node->prev;
            temp->next = node;

            /* Update adjacent nodes' pointers */
            if (node->prev)
                node->prev->next = temp;
            node->prev = temp;

            if (temp->prev == NULL)
                *list = temp;

            print_list(*list);
        }
        node = node->next;
    }
}
