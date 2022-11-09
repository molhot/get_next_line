/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:19:47 by satushi           #+#    #+#             */
/*   Updated: 2022/11/09 12:20:32 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	line = (char *)malloc(sizeof(char) * (i + (save[i] == '\n') + 1));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (save[i] != '\n' && save[i] != '\0')
	{
		line[i] = save[i];
		i = i + 1;
	}
	if (save[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_preparenextline(char *save_in_n)
{
	char	*save_notin_n;
	size_t	i;
	size_t	j;

	i = 0;
	while (save_in_n[i] != '\n' && save_in_n[i] != '\0')
		i = i + 1;
	if (save_in_n[i] == '\0')
	{
		free(save_in_n);
		return (NULL);
	}
	save_notin_n = (char *)malloc(sizeof(char) * (ft_strlen(save_in_n) - i + 1));
	if (save_notin_n == NULL)
		return (NULL);
	i = i + 1;
	j = 0;
	while (save_in_n[i + j] != '\0')
	{
		save_notin_n[j] = save_in_n[i + j];
		j = j + 1;
	}
	save_notin_n[j] = '\0';
	free(save_in_n);
	return (save_notin_n);
}

char	*get_next_line(int fd_num)
{
	char		*line;
	static char	*save[256];

	if (fd_num < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save[fd_num] = ft_save_gnl(fd_num, save[fd_num]);
	if (save == NULL)
		return (NULL);
	line = ft_prepareline(save[fd_num]);
	save[fd_num] = ft_preparenextline(save[fd_num]);
	return (line);
}

int	main()
{
	printf("1 -> %s\n", get_next_line(open("new.txt", O_RDONLY)));
	printf("2 -> %s\n", get_next_line(open("new.txt", O_RDONLY)));
	printf("3 -> %s\n", get_next_line(open("new.txt", O_RDONLY)));
	printf("4 -> %s\n", get_next_line(open("new.txt", O_RDONLY)));
}
