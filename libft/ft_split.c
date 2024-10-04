/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:02:16 by mafaisal          #+#    #+#             */
/*   Updated: 2023/11/16 12:49:40 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**free_content(char	**splitted)
{
	int	k;

	k = 0;
	while (splitted[k])
	{
		free(splitted[k]);
		splitted[k] = NULL;
		k++;
	}
	free(splitted);
	splitted = NULL;
	return (NULL);
}

static unsigned int	word_count(const char *s, char c)
{
	unsigned int	count;
	unsigned int	i;

	count = 0;
	i = 0;
	while (*(s + i))
	{
		if ((*(s + i) == c && *(s + i + 1) != c && *(s + i + 1) != '\0')
			|| (*(s + i) != c && i == 0))
		{
			count++;
		}
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char			**splitted;
	unsigned int	beg;
	unsigned int	end;
	unsigned int	idx;

	splitted = malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!splitted)
		return (NULL);
	beg = 0;
	idx = 0;
	while (s[beg] != '\0' && idx < word_count(s, c))
	{
		while (s[beg] == c)
			beg++;
		end = beg;
		while (s[end] != c && s[end] != '\0')
			end++;
		splitted[idx] = ft_substr(s, beg, end - beg);
		if (splitted[idx] == NULL)
			return (free_content(splitted));
		beg = end;
		idx++;
	}
	splitted[idx] = NULL;
	return (splitted);
}
