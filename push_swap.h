#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct stack
{
    int value;
    struct stack *next;
    struct stack *prev;
} t_stack;

typedef struct vars
{
    int *sorted_table;
    int stack_lengt;
    int hold_first;
    int hold_second;
    t_stack *stack_a;
    t_stack *stack_b;
} t_vars;

t_stack *ft_sa(t_stack *stack_a);
t_stack *ft_sb(t_stack *stack_b);
t_vars *ft_ss(t_vars *vars);
t_stack *ft_rrb(t_stack *stack_b);
t_stack *ft_ra(t_stack *stack_a);
t_stack *ft_rb(t_stack *stack_b);
t_stack *ft_rra(t_stack *stack_a);
int ft_get_lengt(t_stack *stack);
void ft_pb(t_vars *vars);
void ft_pa(t_vars *vars);
void	ft_putstr_fd(char *s, int fd);
int above_100element(t_vars *vars);
int sort100element(t_vars vars);
t_stack *sort5element(t_vars vars);
unsigned long long	ft_atoi(const char *str);
int	ft_isdigit(int c);
#endif