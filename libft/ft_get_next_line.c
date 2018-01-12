/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caupetit <caupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 16:36:59 by caupetit          #+#    #+#             */
/*   Updated: 2014/03/27 18:21:55 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include "libft.h"

static int		ft_gnl_in_buf_end(char *end_buf, char **line)
{
	char		*tmp;

	tmp = NULL;
	while (!tmp && *end_buf)
	{
		if ((tmp = ft_strchr(end_buf, '\n')))
			*tmp = '\0';
		*line = ft_strjoin(*line, end_buf);
		if (tmp && *(tmp + 1))
			ft_memmove(end_buf, tmp + 1, ft_strlen(tmp + 1) + 1);
		else
			ft_bzero(end_buf, BUFF_SIZE);
	}
	if (tmp)
		return (1);
	return (0);
}

static void		ft_gnl_init(char *buf, char **line, char **tmp)
{
	ft_bzero(buf, BUFF_SIZE + 1);
	*line = NULL;
	*tmp = NULL;
}

int				ft_get_next_line(int const fd, char **line, int restart)
{
	ssize_t		ret;
	char		buf[BUFF_SIZE + 1];
	static char	end_buf[BUFF_SIZE + 1];
	char		*tmp;

	ft_gnl_init(buf, line, &tmp);
	if (restart)
		ft_bzero(end_buf, BUFF_SIZE + 1);
	if (*end_buf && ft_gnl_in_buf_end(end_buf, line))
		return (1);
	while (!tmp)
	{
		if ((ret = read(fd, buf, BUFF_SIZE)) < 0)
			return (ret);
		if (!ret && (*line || *end_buf != '\0'))
			return (1);
		if (!ret && !*line && !*end_buf)
			return (0);
		if ((tmp = ft_strchr(buf, '\n')))
			*tmp = '\0';
		*line = ft_strjoin(*line, buf);
		if (tmp && ret > 0 && *(tmp + 1))
			ft_strcpy(end_buf, tmp + 1);
	}
	return (1);
}
