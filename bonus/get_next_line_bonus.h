/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus_bonus.h                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchen <youchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 21:54:56 by youchen           #+#    #+#             */
/*   Updated: 2024/01/29 12:08:38 by youchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

char	*ft_strjoin(char *s1, char *buff);
char	*ft_substr(char *s, unsigned int start, size_t len);
size_t	ft_strlen(char *s1);
char	*get_next_line(int fd);
int		ft_strchr(char *s, int c);
#endif
