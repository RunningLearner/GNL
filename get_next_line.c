/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 10:19:09 by seunam            #+#    #+#             */
/*   Updated: 2022/05/27 18:09:50 by seunam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_line(int fd, char *buf, char *backup)
{
	int		cnt;
	char	*tmp;

	cnt = 1;
	while (cnt)
	{
		cnt = read(fd, buf, BUFFER_SIZE);
		if (cnt == -1)
			return (0);
		else if (cnt == 0)
			break ;
		buf[cnt] = '\0';
		if (!backup)
			backup = ft_strdup("");
		tmp = backup;
		backup = ft_strjoin(tmp, buf);
		if (!backup)
			return (NULL);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (backup);
}

static char	*ft_cut_line(char *line)
{
	int		i;
	char	*res;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (0);
	res = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (!res)
		return (NULL);
	if (res[0] == '\0')
	{
		free(res);
		res = NULL;
		return (NULL);
	}
	line[i + 1] = '\0';
	return (res);
}

static char	*ft_cut_return_line(char *line)
{
	int		i;
	char	*str;

	i = 0;
	if (!line[i]) 
		return (NULL);
	while (line[i] && line[i] != '\n') 
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2)); 
	if (!str)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n') 
	{
		str[i] = line[i]; 
		i++;
	}
	if (line[i] == '\n') 
	{
		str[i] = line[i]; 
		i++;
	}
	str[i] = '\0'; 
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	line = ft_read_line(fd, buf, backup);
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);
	backup = ft_cut_line(line);
	line = ft_cut_return_line(line);
	return (line);
}
