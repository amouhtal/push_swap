#include "push_swap.h"

int	handl_error(char **new_argv)
{
	int i;
	int j;

	j = 0;
	while (new_argv[j])
	{
		i = 0;
		while (i < new_argv[j][i])
		{
			if (ft_isdigit(new_argv[j][i]) == 0)
			{
				if(!(i == 0 && (new_argv[j][i] == '-' || new_argv[j][i] == '+')))
					{
			
						ft_putstr_fd("Error\n", 2);
						return (0);
					}
				}
				i++;
			}
		j++;
	}
	return (1);
}

int deplicat_nbr(int	*table, int lenght)
{
	int i;
	int	j;

	j = 1;
	i = 0;
	while (i < lenght)
	{
		if (i + 1 < lenght)
		{
			if (table[i] == table[i + 1])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}