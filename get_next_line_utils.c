/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:34:08 by seunam            #+#    #+#             */
/*   Updated: 2022/05/27 17:21:13 by seunam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*startbigger(void)
{
	char	*str;

	str = malloc(1);
	if (!str)
		return (NULL);
	*str = 0;
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	idx;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = 0;
	while (s[slen])
		slen ++;
	if (slen - start < len)
		len = slen - start;
	if (start > slen)
		return (startbigger());
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	idx = 0;
	while (s[idx + start] && idx < len)
	{
		str[idx] = s[start + idx];
		idx ++;
	}
	str[idx] = 0;
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	strlen;
	size_t	idx;

	if (!s1 || !s2)
		return (NULL);
	strlen = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	str = malloc(sizeof(char) * (strlen + 1));
	if (!str)
		return (NULL);
	idx = 0;
	while (*s1)
	{
		str[idx++] = *s1++;
	}
	while (*s2)
	{
		str[idx++] = *s2++;
	}
	str[idx] = 0;
	return (str);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	len;
	size_t	idx;
	char	*ss;

	ss = (char *)s;
	len = 0;
	while (s[len])
		len ++;
	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	idx = 0;
	while (ss[idx])
	{
		dup[idx] = ss[idx];
		idx ++;
	}
	dup[idx] = 0;
	return (dup);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		s ++;
	}
	if ((unsigned char)*s == (unsigned char)c)
		return ((char *)s);
	return (0);
}
