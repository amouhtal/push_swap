/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhtal <amouhtal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 14:46:44 by amouhtal          #+#    #+#             */
/*   Updated: 2021/06/07 14:46:45 by amouhtal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_stack *stack)
{
	int		i;
	int		max;
	t_stack	*tmp;

	i = 0;
	max = ft_get_lengt(stack);
	while (stack->prev)
		stack = stack->prev;
	while (i < max)
	{
		tmp = stack;
		if (stack)
			stack = stack->next;
		free(tmp);
		i++;
	}
}

void	ft_free_tab2d(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			if (tab[i])
				free(tab[i]);
			i++;
		}
		free(tab);
	}
}
