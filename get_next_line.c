/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:39:51 by satushi           #+#    #+#             */
/*   Updated: 2022/11/10 09:14:33 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char (*string_row))
{
	size_t	stringlen;

	stringlen = 0;
	while (string_row[stringlen] != '\0')
		stringlen++;
	return (stringlen);
}

char	*ft_save_gnl(int fd, char *save)
{
	char	*buff;
	ssize_t	flag;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == NULL)
		return (NULL);
	flag = 1;
	while (ft_strchr(save, '\n') == NULL)
	{
		flag = read(fd, buff, BUFFER_SIZE);
		if (flag == 0 || flag == -1)
			break ;
		buff[flag] = '\0';
		save = ft_strjoin(save, buff);
		if (save == NULL)
		{
			free(buff);
			return (NULL);
		}
	}
	free(buff);
	if (flag == -1)
		return (NULL);
	return (save);
}

char	*ft_prepareline(char *save)
{
	char	*line;
	int		i;

	i = 0;
	if (save[i] == '\0')
		return (NULL);
	while (save[i] != '\0' && save[i] != '\n')
		i = i + 1;
	if (save[i] == '\n')
		i = i + 1;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (save[i] != '\n' && save[i] != '\0')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_preparenextline(char *saven)
{
	char	*save_notin_n;
	size_t	i;
	size_t	j;

	i = 0;
	while (saven[i] != '\n' && saven[i] != '\0')
		i = i + 1;
	if (saven[i] == '\0')
	{
		free(saven);
		return (NULL);
	}
	save_notin_n = (char *)malloc(sizeof(char) * (ft_strlen(saven) - i + 1));
	if (save_notin_n == NULL)
		return (NULL);
	i = i + 1;
	j = 0;
	while (saven[i + j] != '\0')
	{
		save_notin_n[j] = saven[i + j];
		j = j + 1;
	}
	save_notin_n[j] = '\0';
	free(saven);
	return (save_notin_n);
}

char	*get_next_line(int fd_num)
{
	char		*line;
	static char	*save;

	if (fd_num < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = ft_save_gnl(fd_num, save);
	if (save == NULL)
		return (NULL);
	line = ft_prepareline(save);
	save = ft_preparenextline(save);
	return (line);
}


int main()
{
 	size_t	i;
 	int		fd;
 	char *s;

	fd = open("new.txt",O_RDONLY);
	i = 0;
	while (i < 10)
	{
		s = get_next_line(fd);
		printf("line%zu : %s", i, s);
		i++;
 	}
}
