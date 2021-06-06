/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhtal <amouhtal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 20:13:53 by amouhtal          #+#    #+#             */
/*   Updated: 2021/06/06 19:40:51 by amouhtal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int		check(char c, char *set)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		len;

	if (s1 == NULL)
		return (0);
	str = ft_strdup(s1);
	if (str == NULL)
		return (0);
	while (check(str[0], (char *)set))
		str++;
	len = ft_strlen(str) - 1;
	while (len > 0)
	{
		if (check(str[len], (char *)set))
			str[len] = '\0';
		else
			break ;
		len--;
	}
	free(str);
	return (ft_strdup(str));
}
