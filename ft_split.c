#include "push_swap.h"

static int countwords(char *ptr, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (ptr[i])
	{
		if (ptr[i] == c && ptr[i + 1] != c)
			count++;
		i++;
	}
	return (count + 1);
}

static char *affectation(char c, int *ii, char *ptr)
{
	int k;
	char *p;
	int nn;

	k = 0;
	nn = 0;
	while (ptr[*ii + nn] != c && ptr[*ii + nn])
		nn++;
	if (!(p = (char *)malloc(sizeof(char) * (nn + 1))))
		return (NULL);
	while (nn > k)
	{
		p[k] = ptr[k + *ii];
		k++;
	}
	p[k] = '\0';
	*ii = nn + *ii;
	return (p);
}

static void free_news(char **news)
{
	int i;

	i = 0;
	while (news[i])
	{
		free(news[i]);
		i++;
	}
}

char **ft_split(char const *s, char c)
{
	int index;
	char **news;
	int i;
	char *ptr;

	if ((ptr = ft_strtrim(s, &c)) == NULL)
		return (0);
	if (!(news = (char **)malloc(sizeof(char *) * (countwords(ptr, c) + 1))))
		return (0);
	i = 0;
	index = -1;
	while (ptr[i])
	{
		while (ptr[i] == c)
			i++;
		if ((news[++index] = affectation(c, &i, ptr)) == NULL)
		{
			free_news(news);
			free(ptr);
			return (0);
		}
	}
	news[index + 1] = NULL;
	free(ptr);
	return (news);
}
