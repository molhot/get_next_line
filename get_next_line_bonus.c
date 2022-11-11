/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <satushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:39:51 by satushi           #+#    #+#             */
/*   Updated: 2022/11/11 20:12:25 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char (*string_row))
{
	size_t	stringlen;

	stringlen = 0;
	if (string_row == NULL)
		return (0);
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
	while (ft_strchr((char *)save, '\n') == NULL)
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
	static char	*save[100];

	if (fd_num < 0 || BUFFER_SIZE <= 0 || 100 <= fd_num)
		return (NULL);
	save[fd_num] = ft_save_gnl(fd_num, save[fd_num]);
	if (save[fd_num] == NULL)
		return (NULL);
	line = ft_prepareline(save[fd_num]);
	save[fd_num] = ft_preparenextline(save[fd_num]);
	return (line);
}

/*
int main()
{
 	size_t	i;
 	int		fd1;
	int		fd2;
 	char *s1;
	char *s2;

	i = 0;
	fd1 = open("new.txt",O_RDONLY);
	fd2 = open("new2.txt",O_RDONLY);
	s1 = get_next_line(fd1);
	printf("line1%zu : %s\n", i, s1);
	s2 = get_next_line(fd2);
	printf("line2%zu : %s\n", i, s2);

	s1 = get_next_line(fd1);
	printf("line1%zu : %s\n", i, s1);
	s2 = get_next_line(fd2);
	printf("line2%zu : %s\n", i, s2);

	s1 = get_next_line(fd1);
	printf("line1%zu : %s\n", i, s1);
	s2 = get_next_line(fd2);
	printf("line2%zu : %s\n", i, s2);

	s1 = get_next_line(fd1);
	printf("line1%zu : %s\n", i, s1);
	s2 = get_next_line(fd2);
	printf("line2%zu : %s\n", i, s2);
}
*/