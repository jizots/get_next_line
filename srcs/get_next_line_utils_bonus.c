/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotph <hotph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 10:38:49 by hotph             #+#    #+#             */
/*   Updated: 2024/09/12 10:38:56 by hotph            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../includes/get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char	cc;

	if (s == NULL)
		return (NULL);
	cc = (char) c;
	while (*s)
	{
		if (*s == cc)
			return ((char *) s);
		s += 1;
	}
	if (cc == '\0')
		return ((char *) s);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	len_total;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	len_total = ft_strlen(s1) + ft_strlen(s2);
	errno = 0;
	newstr = malloc(sizeof(char) * (len_total + 1));
	if (newstr == NULL)
		return (NULL);
	newstr[0] = '\0';
	ft_strlcat(newstr, s1, len_total + 1);
	ft_strlcat(newstr, s2, len_total + 1);
	return (newstr);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_d;
	size_t	len_s;

	len_s = ft_strlen(src);
	if (dest == NULL || src == NULL)
		return (size + len_s);
	len_d = ft_strlen(dest);
	if (size <= len_d)
		return (size + len_s);
	while (*dest)
		dest++;
	while (size - len_d - 1)
	{
		*dest++ = *src++;
		size--;
		if (*src == '\0')
			break ;
	}
	*dest = '\0';
	return (len_d + len_s);
}

size_t	ft_strlen(const char *str)
{
	size_t	count;

	if (str == NULL)
		return (0);
	count = 0;
	while (str[count])
		count++;
	return (count);
}

char	*ft_free(char *s1, char *s2)
{
	if (s1 != NULL)
		free(s1);
	if (s2 != NULL)
		free(s2);
	return (NULL);
}
