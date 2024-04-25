/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:07:00 by mwu               #+#    #+#             */
/*   Updated: 2023/10/04 14:06:13 by mwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*read_file(int fd, char *keep);
char	*out_line(char *keep);
char	*left_line(char *keep);
char	*ft_strjoin_free(char *keep, char *buffer);
char	*ft_strjoin1(char *s1, char *s2);
int		ft_strlen1(char *s);
int		ft_strn1(char *s);
void	*ft_bzero1(void *s, unsigned int n);
void	*ft_calloc1(unsigned int n1, unsigned int n2);

#endif
