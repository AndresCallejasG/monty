#ifndef HOLBERTON
#define HOLBERTON
#include <stdlib.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef struct cmd_struct
{
	char *op_code;
    int value;
} cmd_data;

/* main tools - monty.c */
cmd_data *find_cmd(char *line, unsigned int line_cnt);
int exec_op(cmd_data *cmd, stack_t **stack, unsigned int line_cnt);
void free_struct();

/* tools */
int _atoi(char *s);

/* dlistint_tools */
void free_dlistint(stack_t *head);
stack_t *add_dnodeint(stack_t **head, const int n);
size_t print_dlistint(const stack_t *h);
int delete_dnodeint_at_index(stack_t **head, unsigned int index);
stack_t *get_dnodeint_at_index(stack_t *head, unsigned int index);

#endif
