#include <stdio.h>
void ft_print_stack(t_stack *stack)
{
	while (stack && stack->prev)
		stack = stack->prev;
	while (stack)
	{
		printf("%d\n",stack->value);
		stack = stack->next;
	}
}
int main(int argc, char const *argv[])
{
	printf("GG\n");
	return 0;
}
