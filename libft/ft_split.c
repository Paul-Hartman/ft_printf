/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phartman <phartman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:35:18 by phartman          #+#    #+#             */
/*   Updated: 2024/04/26 16:04:25 by phartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stddef.h>

static size_t	wordcount(char const *s, char c)
{
	size_t	i;
	size_t	count;
	int		flag;

	flag = 0;
	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			if (flag)
				count++;
			flag = 0;
		}
		else
			flag = 1;
		i++;
	}
	if (flag == 1)
		count++;
	return (count);
}

static void	free_all(char **arr, unsigned int count)
{
	if (arr)
	{
		while (count > 0)
		{
			count--;
			if (arr[count])
			{
				free(arr[count]);
				arr[count] = NULL;
			}
		}
		free(arr);
		arr = NULL;
	}
}

static int	word_len(char *temp, char c)
{
	size_t	i;
	size_t	len;

	len = 0;
	i = 0;
	while (temp[i] != c && temp[i])
	{
		len++;
		i++;
	}
	return (len);
}

static void	word_allocate(char const *s, char c, char **arr)
{
	unsigned int	j;
	int				flag;
	char			*temp;

	temp = (char *)s;
	flag = 0;
	j = 0;
	while (*temp)
	{
		if (*temp != c && !flag)
		{
			arr[j++] = ft_substr(temp, 0, word_len(temp, c));
			if (!arr[j - 1])
			{
				free_all(arr, j - 1);
				return ;
			}
			flag = 1;
		}
		else if (*temp == c)
			flag = 0;
		temp++;
	}
}

char	**ft_split(char const *s, char c)
{
	size_t	wc;
	char	**arr;

	if (s == NULL)
		return (NULL);
	wc = wordcount(s, c);
	arr = ft_calloc(wc + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	word_allocate(s, c, arr);
	return (arr);
}
