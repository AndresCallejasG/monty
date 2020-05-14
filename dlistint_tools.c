#include "monty.h"
/**
 * free_dlistint - function that free a stack_t list.
 *
 * @head: dlist head
 *
 * Return: void
 */
void free_dlistint(stack_t *head)
{
	stack_t *current, *aux;

	if (head)
	{
		current = head->next;
		while (current)
		{
			aux = current->next;
			free(current);
			current = aux;
		}
		free(head);
	}
}
/**
 * add_dnodeint - adds a new node at the beginning
 * of a stack_t list.
 *
 * @head: dlist head
 * @n: value for new node
 *
 * Return: the address of the new element
 * or NULL if it failed
 */
stack_t *add_dnodeint(stack_t **head, int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = NULL;

	if (*head)
	{
		(*head)->prev = NULL;
		(*head)->prev = new_node;
		new_node->next = *head;
	}
	*head = new_node;
	return (new_node);
}
/**
 * print_dlistint - prints all the elements of a stack_t list.
 *
 * @h: head of double linked list
 *
 * Return: the number of nodes
 */
size_t print_dlistint(stack_t *h)
{
	stack_t *current;
	size_t length = 0;

	if (h)
	{
		current = h;
		do
		{
			length++;
			fprintf(stdout, "%d\n", current->n);
			current = current->next;

		} while (current);
	}
	return (length);
}
/**
 * delete_dnodeint_at_index -  deletes the node at
 * index of a stack_t linked list.
 *
 * @head: stack_t head
 * @index: index
 *
 * Return:  1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
	stack_t *current = *head;
	stack_t *n_prev = 0, *n_next = 0;
	unsigned int count = 0;

	if (current)
	{
		if (index == 0)
		{
			if (current->next)
			{
				n_next = current->next;
				n_next->prev = NULL;
			}
			*head = n_next;
			free(current);
			return (1);
		}
	}
	while (current)
	{
		if (count == index)
		{
			n_prev = current->prev;
			if (current->next)
			{
				n_next = current->next;
				n_next->prev = n_prev;
				n_prev->next = n_next;
			}
			else
				n_prev->next = NULL;
			free(current);
			return (1);
		}
		current = current->next;
		count++;
	}
	return (-1);
}

/**
 * get_dnodeint_at_index -function that free a stack_t list.
 *
 * @head: dlinkedList head
 * @index: node index required
 *
 * Return: nth node
 * if the node does not exist, return NULL
 */
stack_t *get_dnodeint_at_index(stack_t *head, unsigned int index)
{
	stack_t *current;
	unsigned int count = 0;

	if (head)
	{
		current = head;
		while (current)
		{
			if (count == index)
			{
				return (current);
			}
			current = current->next;
			count++;
		}
	}
	return (NULL);
}