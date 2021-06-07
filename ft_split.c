/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhtal <amouhtal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 12:57:49 by amouhtal          #+#    #+#             */
/*   Updated: 2021/06/07 12:58:46 by amouhtal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_count_words(const char *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static char	*ft_print_tabl(const char *s, int deb, int fin)
{
	int		i;
	char	*tabl;

	i = deb;
	tabl = malloc((fin - deb + 2) * sizeof(char));
	if (tabl == NULL)
		return (NULL);
	while (i <= fin)
	{
		tabl[i - deb] = s[i];
		i++;
	}
	tabl[i - deb] = '\0';
	return (tabl);
}

static int	ft_check_allocation(char **str, int j)
{
	int		k;

	k = 0;
	if (str[j] == NULL)
	{
		while (k < j)
		{
			free(str[k]);
			k++;
		}
		free(str);
		return (0);
	}
	return (1);
}

static char	**ft_fill_table(const char *s, char c, char **str)
{
	int		i;
	int		deb;
	int		fin;
	int		j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if ((i == 0 && s[0] != c) || (s[i] != c && s[i - 1] == c))
			deb = i;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			fin = i;
			str[j] = ft_print_tabl(s, deb, fin);
			if (!ft_check_allocation(str, j))
				return (NULL);
			j++;
		}
		i++;
	}
	str[j] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;

	if (s == NULL)
		return (NULL);
	str = (char **)malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (str == NULL)
		return (NULL);
	str = ft_fill_table(s, c, str);
	return (str);
}
