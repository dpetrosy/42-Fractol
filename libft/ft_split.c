/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 21:58:17 by dapetros          #+#    #+#             */
/*   Updated: 2024/01/25 14:47:23 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_words_count(char const *s, const char c)
{
	size_t	words_count;
	size_t	i;

	i = 0;
	words_count = 0;
	while (s[i])
	{
		if (s[i] == c)
			++i;
		else
		{
			++words_count;
			while (s[i] != c && s[i])
				++i;
		}
	}
	return (words_count);
}

static size_t	word_len(size_t i, char const *str, const char c)
{
	size_t	size;

	size = 0;
	while (str[i] && str[i] != c)
	{
		++size;
		++i;
	}
	return (size);
}

static int	split_str(char *str, char **words, char c, t_indexes *sp_ind)
{
	while (str[sp_ind->i])
	{
		if (str[sp_ind->i] != c)
		{
			words[sp_ind->j] = (char *)malloc(word_len(sp_ind->i, str, c) + 1);
			if (!words[sp_ind->j])
				return (sp_ind->alloc_count);
			else
				++sp_ind->alloc_count;
			sp_ind->k = 0;
			while (str[sp_ind->i] && str[sp_ind->i] != c)
				words[sp_ind->j][sp_ind->k++] = str[sp_ind->i++];
			words[sp_ind->j][sp_ind->k] = '\0';
			++sp_ind->j;
		}
		else
			++sp_ind->i;
	}
	return (sp_ind->alloc_count);
}

static void	ft_free(char **words, size_t alloc_count)
{
	size_t	i;

	i = 0;
	while (i < alloc_count)
	{
		free(words[i]);
		++i;
	}
	free(words);
}

char	**ft_split(char const *s, char c)
{
	size_t		words_count;
	size_t		alloc_count;
	char		**words;
	t_indexes	split_indexes;

	if (!s)
		return (NULL);
	words_count = get_words_count(s, c);
	words = (char **)malloc(sizeof(char *) * (words_count + 1));
	if (!words)
		return (NULL);
	split_indexes.i = 0;
	split_indexes.j = 0;
	split_indexes.k = 0;
	split_indexes.alloc_count = 0;
	alloc_count = split_str((char *)s, words, c, &split_indexes);
	if (alloc_count < words_count)
	{
		ft_free(words, alloc_count);
		return (NULL);
	}
	words[words_count] = 0;
	return (words);
}
