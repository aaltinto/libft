/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaltinto <aaltinto@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:39:31 by aaltinto          #+#    #+#             */
/*   Updated: 2023/08/02 13:39:38 by aaltinto         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_substr(char const *s, size_t start, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *str, char *buf);
void	*free_str(char **str, int i);
char	*ft_strdup(const char *s);
#endif