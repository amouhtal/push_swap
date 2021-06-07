/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhtal <amouhtal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 14:46:11 by amouhtal          #+#    #+#             */
/*   Updated: 2021/06/07 14:46:12 by amouhtal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include    <stdio.h>
# include   <stdlib.h>
# include   <string.h>
# include   <unistd.h>
# include   <fcntl.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

typedef struct s_frame
{
	int		*sorted_table;
	int		stack_lengt;
	int		hold_first;
	int		hold_second;
	t_stack	*stack_a;
	t_stack	*stack_b;
}				t_frame;

t_stack		*ft_sa(t_stack *stack_a);
t_stack		*ft_sb(t_stack *stack_b);
t_frame		*ft_ss(t_frame *frame);
t_stack		*ft_rrb(t_stack *stack_b);
t_stack		*ft_ra(t_stack *stack_a);
t_stack		*ft_rb(t_stack *stack_b);
t_stack		*ft_rra(t_stack *stack_a);
int			ft_get_lengt(t_stack *stack);
void		ft_pb(t_frame *frame);
void		ft_pa(t_frame *frame);
int			handl_error(char **argv);
void		ft_free(t_stack *stack);
int			deplicat_nbr(t_frame *frame, int	*table, int lenght);
void		ft_putstr_fd(char *s, int fd);
void		initilise(int lenght, char **argv, t_frame *frame);
size_t		ft_strlen(const char *s);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_strdup(const char *s1);
int			sort100element(t_frame *frame);
char		**ft_split(char const *s, char c);
t_stack		*sort5element(t_frame *frame);
long long	ft_atoi(const char *str, int *check);
t_frame		*pushin_chunk(t_frame *frame, int start, int fin);
t_frame		*pushin_back(t_frame *frame);
t_stack		*sort3element(t_stack *stack);
int			ft_get_biggest(t_frame frame);
int			ft_isdigit(int c);
void		ft_print_stack(t_stack *stack);
t_stack		*new_stack_a(void);
t_stack		*get_head(t_stack *stack);
t_stack		*add_list(t_stack *stack);
t_stack		*get_stack_a(char **argv, t_stack *stack_a);
int			check_if_sorted(t_stack *stack_a);
int			ft_scan_from_top(t_frame *frame, int start, int fin);
int			ft_scan_from_bottom(t_frame *frame, int start, int fin);
int			ft_strchr(const char *s, int c);
void		ft_free_tab2d(char **tab);
#endif