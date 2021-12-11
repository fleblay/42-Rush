/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashtable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 10:27:19 by fle-blay          #+#    #+#             */
/*   Updated: 2021/12/11 15:29:20 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "ft_hashtable.h"

char	*get_input()
{
	char	tab[BUFFER_SIZE + 1];
	int		i;
	char	*tmp;
	char	*mainstr;

	tmp = NULL;
	i = -1;
	mainstr = ft_strdup("");
	if (! mainstr)
		return (NULL);
	while (++i < BUFFER_SIZE + 1)
		tab[i] = '\0';
	while (mainstr && read(0, tab, BUFFER_SIZE))
	{
		tmp = mainstr;
		mainstr = ft_strjoin(tmp, tab);
		free(tmp);
		i = -1;
		while (++i < BUFFER_SIZE + 1)
			tab[i] = '\0';
	}
	return (mainstr);
}

int	get_sizetab(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
		i++;
	return (i);
}

int	fxhash(char *key, int sizeht)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	if (! key)
		return (i);
	while (key[i])
	{
		result += key[i];
		i++;
	}
	return (result % sizeht);
}

t_pair	**init_ht(int sizeht)
{
	t_pair **ht;

	ht = (t_pair **)malloc(sizeht * sizeof(t_pair *));
	if (! ht)
		return (NULL);
	while (sizeht--)
		ht[sizeht] = NULL;
	return (ht);
}

t_pair	*mk_pair(char *key, char *value)
{
	t_pair *nw;

	nw = malloc(sizeof(t_pair));
	if (!nw)
		return (NULL);
	nw->key = key;
	nw->value = value;
	return (nw);
}

void	fill_ht(t_pair **ht, char **cntarr, int sizeht)
{
	int	i;
	int	j;
	int offset;

	i = 0;
	while (cntarr[i])
	{
		offset = 0;
		while (offset < sizeht)
		{
			j = fxhash(cntarr[i], sizeht);
			if (ht[(j + offset) % sizeht] == NULL)
			{
				ht[(j + offset) % sizeht] = mk_pair(cntarr[i], cntarr[i + 1]);
				i += 2;
			}
			else
				offset++;
		}
	}
}


#include <stdio.h>

int main()
{
	char *input;
	char *content;
	char **cntarr;
	t_pair **ht;
	int	i;

	input = get_input();
	printf(">%s<\n", input);
	content = ft_substr(input, 0, ft_strnstr(input, "\n\n", ft_strlen(input)) - input);
	printf("apres le substr\n");
	printf(">%s<\n", content);
	cntarr = ft_split(content, '\n');
	printf("%d\n", get_sizetab(cntarr));
	ht = init_ht(get_sizetab(cntarr) / 2);
	fill_ht(ht, cntarr, get_sizetab(cntarr) / 2);

	i = 0;
	while (i < get_sizetab(cntarr) / 2)
	{
		printf("ht[%d] : key -> %s, value -> %s\n", i, ht[i]->key, ht[i]->value);
		i++;
	}
	return (0);
}
