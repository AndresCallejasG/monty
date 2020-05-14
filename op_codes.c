#include "monty.h"
cmd_data cmd;

void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	(void)line_number;
	node = add_dnodeint(stack, cmd.value);
	if (!node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
}
void _pall(stack_t **stack, unsigned int line_number)
{
	print_dlistint(*stack);
	(void)line_number;
}
void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	top = get_dnodeint_at_index(*stack, 0);
	if (top)
	{
		printf("%d\n", top->n);
	}
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_dlistint(*stack);
		free_struct();
		exit(EXIT_FAILURE);
	}
}
void _pop(stack_t **stack, unsigned int line_number)
{	
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	delete_dnodeint_at_index(stack, 0);
}
void _swap(stack_t **stack, unsigned int line_number)
{
	int aux;

	if (!(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	aux = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = aux;
}
