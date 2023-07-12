/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotph <hotph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:07:55 by sotanaka          #+#    #+#             */
/*   Updated: 2023/07/12 14:25:49 by hotph            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GNL_H
# define FT_GNL_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

/*------include------*/
//for func
# include <errno.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

//for verify
# include <stdio.h>

/*------define------*/

/*------struct------*/

/*------prototype------*/
//ft_gnl_utils
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
char	*ft_free(char *s1, char *s2);
//ft_gnl
char	*ft_gnl(int fd);

#endif
