#include "monty.h"
void _add(stack_t **stack, unsigned int line_number)
{
	int n_head;

	if (!(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_dlistint(*stack);
		free_struct();
		exit(EXIT_FAILURE);
	}

	n_head = (*stack)->n;
	(*stack)->next->n += n_head;
	_pop(stack, line_number);
}
void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
void _sub(stack_t **stack, unsigned int line_number)
{
	int n_head;

	if (!(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_dlistint(*stack);
		free_struct();
		exit(EXIT_FAILURE);
	}

	n_head = (*stack)->n;
	(*stack)->next->n -= n_head;
	_pop(stack, line_number);
}
