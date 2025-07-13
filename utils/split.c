/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnafiai <bnafiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 16:48:12 by bnafiai           #+#    #+#             */
/*   Updated: 2025/07/13 16:48:12 by bnafiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static char	**ft_free(char **strs, int j)
{
	int	i;

	i = 0;
	while (i <= j)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

static int	count(char const *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			words++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	return (words);
}

static char	**fil1(char **strs, char c, char const *s)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	while (s[j] != '\0')
	{
		while (s[j] == c)
			j++;
		if (s[j])
		{
			start = j;
			while (s[j] != c && s[j])
				j++;
			strs[i] = ft_substr(s, start, j - start);
			if (strs[i] == NULL)
				return (ft_free(strs, i));
			i++;
		}
	}
	strs[i] = NULL;
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		words;

	if (s == NULL)
		return (NULL);
	words = count(s, c);
	strs = (char **)malloc((words + 1) * (sizeof(char *)));
	if (strs == NULL)
		return (NULL);
	return (fil1(strs, c, s));
}