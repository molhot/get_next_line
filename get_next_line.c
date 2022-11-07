#include "get_next_line.h"

char *ft_save_gnl(int fd, char *save)
{
	char *buff;
	ssize_t flag;
	
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if(buff == NULL)
		return (NULL);
	flag = 1;
	while(ft_strchr(save, '\n') == NULL)
    {
		flag = read(fd, buff, BUFFER_SIZE);
		if(flag == 0 || flag == -1)
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
	if(flag == -1)
		return (NULL);
	return (save);
}

char	*ft_prepareline(char *save)
{
	char *line;
	int i;

	i = 0;
	if(save[i] == '\0')
		return (NULL);
	while(save[i] != '\0' && save[i] != '\n')
		i = i + 1;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if(line == NULL)
		return (NULL);
	i = 0;
	while(save[i] != '\n' && save[i] != '\0')
	{
		line[i] = save[i];
		i = i + 1;
	}
	line[i] = '\0';
	return (line);
}

char *ft_preparenextline(char *save_in_n)
{
	char *save_notin_n;
	int index;
	int mallocsize_next;
	char *firstadd_savein_n;

	index = 0;
	firstadd_savein_n = save_in_n;
	while(*save_in_n != '\n' && *save_in_n != '\0')
		save_in_n = save_in_n + 1;
	if(*save_in_n == '\0')
		return NULL;
	save_in_n = save_in_n + 1;
	while(save_in_n[index] != '\n' || save_in_n[index] != '\0')
		index = index + 1;
	save_notin_n = (char *)malloc(sizeof(char) * (index + 1));
	index = 0;
	while(save_in_n[index] != '\0')
	{
		save_notin_n[index] = save_in_n[index];
		index = index + 1;
	}
	save_notin_n[index] = '\0';
	free(firstadd_savein_n);
	return save_notin_n;
}

char *get_next_line(int fd_num)
{
	char *line;
	static char *save;
	
	if (fd_num < 0 || BUFFER_SIZE <= 0)
		return (NULL);
    save = ft_save_gnl(fd_num, save);
	if (save == NULL)
		return (NULL);
	line = ft_prepareline(save);
	save = ft_preparenextline(save);
	return (line);
}
