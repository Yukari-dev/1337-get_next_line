/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maoulad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 17:46:51 by maoulad           #+#    #+#             */
/*   Updated: 2026/10/27 16:46:23 by maoulad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <memory.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*read_and_get(int fd, char *chunk);
char	*go_to_next_chunk(char *chunk);
char	*get_line(char *chunk);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *line, char *buff);
size_t	ft_strlen(const char *s);

#endif
