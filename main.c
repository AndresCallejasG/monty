#include "monty.h"

/**
 * main - monty interpreter main function
 *
 * @argc: args count;
 * @av: args;
 *
 * Return: Always 0.
 */
int main(int argc, char *av[])
{

	FILE *fd;
	stack_t *stack = NULL;
	size_t len = 0;
	char *line = NULL;
	unsigned int line_cnt = 0;

	cmd.op_code = NULL;
	cmd.value = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(av[1], "r");
	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while ((getline(&line, &len, fd) != -1))
	{
		line_cnt++;
		find_cmd(line, line_cnt);
		exec_op(&stack, line_cnt);
	}
	free(line);
	fclose(fd);
	free_dlistint(stack);
	free_struct();
	return (0);
}
/**
 * main - monty interpreter main function
 *
 * @argc: args count;
 * @av: args;
 *
 * Return: Always 0.
 */

void find_cmd(char *line, unsigned int line_cnt)
{
	char *tok;
	int num = 0;

	cmd.value = 0;
	free(cmd.op_code);
	tok = strtok(line, " \n\t");
	cmd.op_code = strdup(tok);
	if (strcmp(tok, "push") == 0)
	{
		tok = strtok(NULL, " \n\t");
		num = _atoi(tok);
		if (num == -1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_cnt);
			free_struct();
			exit(EXIT_FAILURE);
		}
		cmd.value = num;
	}
}
/**
 * main - monty interpreter main function
 *
 * @argc: args count;
 * @av: args;
 *
 * Return: Always 0.
 */
void exec_op(stack_t **stack, unsigned int line_cnt)
{
	int i = 0;
	instruction_t op_func[] = {
		{"push", _push}, {"pall", _pall}, {"pint", _pint}, {"pop", _pop}, {"swap", _swap}, {"add", _add}, {"nop", _nop}, {NULL, NULL}};

	while (op_func[i].f != NULL)
	{
		if (strcmp(op_func[i].opcode, cmd.op_code) == 0)
		{
			op_func[i].f(stack, line_cnt);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_cnt, cmd.op_code);
	free_dlistint(*stack);
	free_struct();
	exit(EXIT_FAILURE);
}
/**
 * main - monty interpreter main function
 *
 * @argc: args count;
 * @av: args;
 *
 * Return: Always 0.
 */

void free_struct()
{
	/* free cmd_struct */
	free(cmd.op_code);
}
