/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 10:19:09 by seunam            #+#    #+#             */
/*   Updated: 2022/08/23 13:04:19 by seunam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *backup)
{
	char	*buf;
	int		cnt;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	cnt = 1;
	while (!ft_strchr(backup, '\n') && cnt != 0)
	{
		cnt = read(fd, buf, BUFFER_SIZE);
		if (cnt == -1)
		{
			free(buf);
			buf = NULL;
			return (NULL);
		}
		buf[cnt] = '\0';
		backup = ft_strjoin(backup, buf);
	}
	free(buf);
	buf = NULL;
	return (backup);
}

char	*ft_return_oneline(char *backup)
{
	int		i;
	char	*str;

	i = 0;
	if (!backup[i])
		return (NULL);
	while (backup[i] && backup[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (backup[i] && backup[i] != '\n')
	{
		str[i] = backup[i];
		i++;
	}
	if (backup[i] == '\n')
	{
		str[i] = backup[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_cut_backup(char *backup)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (backup[i] && backup[i] != '\n')
		i++;
	if (!backup[i])
	{
		free(backup);
		backup = NULL;
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(backup) - i));
	if (!str)
		return (NULL);
	i++;
	while (backup[i])
		str[j++] = backup[i++];
	str[j] = '\0';
	free(backup);
	backup = NULL;
	return (str);
}

char	*get_next_line(int fd)
{
	char		*oneline;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	backup = ft_read(fd, backup);
	if (!backup)
		return (NULL);
	oneline = ft_return_oneline(backup);
	backup = ft_cut_backup(backup);
	return (oneline);
}
