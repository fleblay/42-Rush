/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hastable.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:44:22 by fle-blay          #+#    #+#             */
/*   Updated: 2021/12/11 11:47:37 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HASHTABLE_H
# define FT_HASHTABLE_H
# include <stdio.h>
# include <errno.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif
# ifndef MAX_MULTIPLIER
#  define MAX_MULTIPLIER 32
# endif

size_t		ft_strlen(const char *s);
char		*ft_buf_append(char const *s1, char const *s2, ssize_t size2);
void		ft_putstr_fd(char *s, int fd);
char		*ft_strdup(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		**ft_split(char const *s, char c);
char		*ft_strnstr(const char *big, const char *little, size_t len);
char		*ft_realloc(char *s, size_t old, ssize_t *to_add, char **tmp);
void		print_not_found(char *str);
void		ft_putvalue_newline(char *str);
void		ft_putstr_newline(char *str);
long int	put_error(char *for_whom, long int ret);
void		fill_ht(char **ht, char **input, int sizeht, int multiplier);
int			init_ht(char ***ht, ssize_t sizeht);
int			get_sizetab(char *str);
size_t		hash2(char **key, int sizeht, int multiplier);

#endif
