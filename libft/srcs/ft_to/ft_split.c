/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudino <lgaudino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:34:26 by lgaudino          #+#    #+#             */
/*   Updated: 2023/02/01 12:34:26 by lgaudino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_sub_len(char const *s, char c)
{
	size_t	result;

	result = 0;
	while (*s == c && *s)
		s++;
	if (!*s)
		return (0);
	while (1)
	{
		if (!*s || *s == c)
		{
			result++;
			while (*s == c && *s)
				s++;
			if (!*s)
				break ;
		}
		else
			s++;
	}
	return (result);
}

static char	**ft_sub_strs(char const *s, size_t sub_len, char c, char **dst)
{
	char	*temp;
	size_t	start;
	size_t	end;
	size_t	i;

	i = 0;
	end = 1;
	start = 0;
	while (i < sub_len)
	{
		if ((s[end - 1] != c && s[end] == c) || !s[end])
		{
			temp = ft_substr(s, start, end - start + 1);
			if (!temp)
				return (NULL);
			dst[i] = ft_strtrim(temp, (char *)&c);
			free(temp);
			if (!dst[i++])
				return (NULL);
			start = end + 1;
		}
		end++;
	}
	dst[i] = 0;
	return (dst);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	sub_len;

	if (!s)
		return (NULL);
	sub_len = ft_sub_len(s, c);
	result = (char **)malloc(sizeof(char *) * (sub_len + 1));
	if (!result)
		return (NULL);
	return (ft_sub_strs(s, sub_len, c, result));
}
