/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotph <hotph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 10:39:07 by hotph             #+#    #+#             */
/*   Updated: 2024/09/12 10:39:12 by hotph            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../includes/get_next_line.h"

static int	ft_get_save(char **save)
{
	char	*tmp;
	char	*p_nwl;
	char	*p_nul;

	p_nwl = ft_strchr(*save, '\n');
	p_nul = ft_strchr(*save, '\0');
	tmp = *save;
	if (p_nwl < p_nul && p_nwl != NULL)
	{
		*save = malloc (sizeof(char) * (p_nul - p_nwl));
		if (*save == NULL)
			return (-1);
		*save[0] = '\0';
		ft_strlcat(*save, (p_nwl + 1), (p_nul - p_nwl));
		free(tmp);
	}
	else
	{
		free(*save);
		*save = NULL;
	}
	return (0);
}

static char	*ft_get_result(char *save)
{
	char	*result;
	char	*p_nwl;
	char	*p_nul;

	p_nwl = ft_strchr(save, '\n');
	p_nul = ft_strchr(save, '\0');
	if (p_nwl < p_nul && p_nwl != NULL)
	{
		result = malloc (sizeof(char) * (p_nwl - save + 1 + 1));
		if (result == NULL)
			return (NULL);
		result[0] = '\0';
		ft_strlcat(result, save, ((p_nwl - save + 1 + 1)));
	}
	else
		result = ft_strjoin(NULL, save);
	return (result);
}

static char	*ft_read_file(char *save, int fd, char *buf, int byte_rd)
{
	char	*tmp;

	buf = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	while (ft_strchr(save, '\n') == NULL && byte_rd != 0)
	{
		byte_rd = read(fd, buf, BUFFER_SIZE);
		if (byte_rd < 0)
		{
			ft_free(buf, save);
			return (NULL);
		}
		else if (byte_rd > 0)
		{
			buf[byte_rd] = '\0';
			tmp = save;
			save = ft_strjoin(tmp, buf);
			if (save == NULL)
				return (ft_free(tmp, buf));
			ft_free(tmp, NULL);
		}
	}
	free (buf);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save[OPEN_MAX];
	char		*buf;
	char		*result;
	int			byte_rd;

	if (fd < 0)
		return (NULL);
	buf = NULL;
	byte_rd = 1;
	save[fd] = ft_read_file(save[fd], fd, buf, byte_rd);
	if (save[fd] == NULL || *save[fd] == '\0')
		return (ft_free(save[fd], NULL));
	result = ft_get_result(save[fd]);
	if (result == NULL)
		return (ft_free(save[fd], NULL));
	if (ft_get_save(&save[fd]) == -1)
		return (ft_free(result, NULL));
	return (result);
}

// int main()
// {
// 	char *line;
// 	int fd;

// 	fd = open("tmp", O_RDONLY);
// 	printf("fd : %d\n", fd);
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		printf ("result->%s<-\n", line);
// 		if (line == NULL)
// 			break ;
// 		free(line);
// 	}

// }

// __attribute__((destructor))
// static void destructor()
// {
// 	system("leaks -q a.out");
// }