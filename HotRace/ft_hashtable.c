/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashtable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 10:27:19 by fle-blay          #+#    #+#             */
/*   Updated: 2021/12/11 20:59:39 by fle-blay         ###   ########.fr       */
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

//char	*get_value(t_pair **ht, char *key, int sizeht)
//{
//	int	j;
//	int offset;
//
//	if (! key)
//		return (NULL);
//	j = fxhash(key, sizeht);
//	offset = 0;
//	while (offset < sizeht && ht[(j + offset) % sizeht]->key != key)
//		offset++;
//	if (ht[(j + offset) % sizeht]->key == key)
//		return (ht[(j + offset) % sizeht]->value);
//	else
//		return (NULL);
//}

void	get_value(t_pair **ht, int sizeht, char **cntqry)
{
	//ft_cmp to add
	int	j;
	int offset;
	int	i;

	if (! cntqry)
		return;
	i = 0;
	while (cntqry[i])
	{
		j = fxhash(cntqry[i], sizeht);
		offset = 0;
		//ft_cmp of pointers to add
		while (offset < sizeht && ht[(j + offset) % sizeht]->key != cntqry[i])
			printf("la\n") &&  offset++;
		//ft_cmp of pointers to add
		if (ht[(j + offset) % sizeht]->key == cntqry[i])
		{
			ft_putstr_fd(ht[(j + offset) % sizeht]->value, 1);
			printf("ici\n");
		}
		else
			ft_putstr_fd("not found\n", 1);
		i++;
	}
}
#include <stdio.h>

int main()
{
	char *input;
	char *content;
	char *query;
	char **cntarr;
	char **cntqry;
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
	query = ft_substr(input, ft_strnstr(input, "\n\n", ft_strlen(input)) - input, ft_strlen(input));
	cntqry = ft_split(query, '\n');
	i = 0;
	while (cntqry[i])
	{
		printf("%s\n", cntqry[i]);
		i++;
	}
	get_value(ht, get_sizetab(cntarr) / 2, cntqry);

	return (0);
}
