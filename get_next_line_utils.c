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

size_t	ft_strlen(const char *s)
{
	size_t	cnt;

	cnt = 0;
	while (*s ++)
		cnt ++;
	return (cnt);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ptr;
	unsigned int	i;
	unsigned int	j;

	if (len > ft_strlen(s))
	{
		len = ft_strlen(s);
	}
	ptr = (char *)malloc(len + 1);
	i = start;
	j = 0;
	if (ptr == NULL)
	{
		return (NULL);
	}
	while (j < len && i < ft_strlen(s))
	{
		ptr[j] = s[i];
		i++;
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
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
