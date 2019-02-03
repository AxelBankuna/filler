/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:28:09 by abukasa           #+#    #+#             */
/*   Updated: 2018/08/16 12:26:51 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	define BUFF_SIZE 1

#include "libft.h"

static int	ft_cupfull(int const fd, char **bigcup)
{
	char	*smallcup;
	char	*tempcup;
	int		char_read;

	if (!(smallcup = (char*)malloc(sizeof(*smallcup) * (BUFF_SIZE + 1))))
		return (-1);
	char_read = read(fd, smallcup, BUFF_SIZE);
	if (char_read > 0)
	{
		smallcup[char_read] = '\0';
		tempcup = ft_strjoin(*bigcup, smallcup);
		free(*bigcup);
		*bigcup = tempcup;
	}
	free(smallcup);
	return (char_read);
}

int			get_next_line(const int fd, char **line)
{
	static char	*bucket = NULL;
	char		*nl_ptr;
	int			char_read;

	if ((!bucket && (bucket = (char*)malloc(sizeof(*bucket))) == NULL)
			|| !line || fd < 0 || BUFF_SIZE < 0)
		return (-1);
	nl_ptr = ft_strchr(bucket, '\n');
	while (nl_ptr == NULL)
	{
		if (!(char_read = ft_cupfull(fd, &bucket)) || char_read == 0)
		{
			if (ft_strlen(bucket) == 0)
				return (0);
			bucket = ft_strjoin(bucket, "\n");
		}
		if (char_read < 0)
			return (-1);
		else
			nl_ptr = ft_strchr(bucket, '\n');
	}
	*line = ft_strsub(bucket, 0, ft_strlen(bucket) - ft_strlen(nl_ptr));
	bucket = ft_strdup(nl_ptr + 1);
	return (1);
}
