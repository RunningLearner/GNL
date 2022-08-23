/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 10:19:17 by seunam            #+#    #+#             */
/*   Updated: 2022/08/23 17:43:15 by seunam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

size_t		ft_strlen(char *str);
char		*ft_strchr(char *str, char i);
char		*ft_strjoin(char *s1, char*s2);
char		*get_next_line(int fd);
char		*ft_read(int fd, char *word);
char		*ft_return_oneline(char *word);
char		*ft_cut_backup(char *word);

#endif
