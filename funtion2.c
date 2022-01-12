#include "monty.h"
/**
 * @brief
 *
 */
void add(stack_t **stack, unsigned int line_numb)
{
	stack_t *tmp;

	tmp = *stack;
	if (tmp == NULL || tmp->next == NULL)
	{
		printf("L%u: can't add, stack too short\n", line_numb);
		exit(EXIT_FAILURE);
	}
	tmp->next->n += tmp->n;
	pop(stack, line_numb);
}
