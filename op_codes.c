#include "monty.h"
cmd_data cmd;

void _push(stack_t **stack, unsigned int linen)
{
    add_dnodeint(stack, cmd.value);
    (void) linen;
}
void _pall(stack_t **stack, unsigned int linen)
{
    print_dlistint(*stack);
    (void) linen;
}
void _pint(stack_t **stack, unsigned int linen)
{
    stack_t *top;
    top = get_dnodeint_at_index(*stack, 0);
    if (top)
    {
        printf("%d\n", top->n);
    }
    else
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", linen);
        free_dlistint(*stack);
        free_struct();
        exit(EXIT_FAILURE);
    }
}
void _pop(stack_t **stack, unsigned int linen)
{
    (void)stack;
    (void)linen;
}
void _swap(stack_t **stack, unsigned int linen)
{
    (void)stack;
    (void)linen;
}
