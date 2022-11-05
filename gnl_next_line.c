#include "get_next_line.h"

char *ft_save_gnl(int fd, char *save)
{
	char *buff;
	int flag;
	ssize_t bytes;
	int counter;
	
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	counter = 0;
	if(buff == NULL)
		return (NULL);
	flag = 1;
	while(flag > 0)
    {
		if((save != NULL && ft_strchr(save, '\n') != NULL))
			break ;
		flag = read(fd, buff, BUFFER_SIZE);
		if(flag == -1 || flag == 0)
			break ;
		buff[flag] = '\0';
		save = ft_strjoin(save, buff);
		counter = counter + 1;
    }
	free(buff);
	return (save);
}

char	*ft_prepareline(char *save)
{
	int index;
	char *line;
	int mallocsize;

	mallocsize = ft_strlen(save);
	line = (char *)malloc(sizeof(char) * (mallocsize + 1));
	if(line == NULL)
		return (NULL);
	index = 0;
	while(save[index] != '\n' && save[index] != '\0')
	{
		line[index] = save[index];
		index = index + 1;
	}
	line[index] = '\0';
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
	mallocsize_next = ft_strlen(save_in_n) + 1;
	save_notin_n = (char *)malloc(sizeof(char) * mallocsize_next);
	while(save_in_n[index] != '\0')
	{
		save_notin_n[index] = save_in_n[index];
		index = index + 1;
	}
	save_notin_n[index] = '\0';
	free(firstadd_savein_n);
	return save_notin_n;
}

char *ft_get_next_line(int fd_num)
{
	char *line;
	static char *save = "";

    save = ft_save_gnl(fd_num, save);
	line = ft_prepareline(save);
	save = ft_preparenextline(save);

	return (line);
}
