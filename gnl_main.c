#include "ft_gnl.h"

char *ft_save_gnl(int fd, char *save)
{
	char *buff;
	int flag;
	ssize_t bytes;
	int counter;
	
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	printf("this is clear!->> %s\n","insertcheck");
	counter = 0;
	if(buff == NULL)
		return (NULL);
	flag = 1;
	printf("this is clear!->> %s\n","insertcheck");
	while(flag > 0)
    {
		//printf("flasg is ->> %d\n",flag);
		if((save != NULL && ft_strchr(save, '\n') != NULL))
			break ;
		flag = read(fd, buff, BUFFER_SIZE);
		printf("flag is -> %d\n", flag);
		if(flag == -1 || flag == 0)
			break ;
		buff[flag] = '\0';
		printf("buff is -> %s\n", buff);
		save = ft_strjoin(save, buff);
		printf("save is -> %s\n", save);
		counter = counter + 1;
    }
	printf("this is clear!->> %s\n","while out");
	free(buff);
	printf("save is -> %s\n", save);
	return (save);
}

char	*ft_prepareline(char *save)
{
	int index;
	char *line;
	int mallocsize;

	mallocsize = ft_strlen(save);
	printf("malloc size is =>>>>> %d\n", mallocsize);
	line = (char *)malloc(sizeof(char) * (mallocsize + 1));
	if(line == NULL)
		return (NULL);
	index = 0;
	while(save[index] != '\n' && save[index] != '\0') //&& index != mallocsize)
	{
		line[index] = save[index];
		index = index + 1;
	}
	line[index] = '\0';
	printf("line is =>>> %s\n", line);
	return (line);
}

char *ft_preparenextline(char *save_in_n)
{
	char *save_notin_n;
	int index;
	int mallocsize_next;
	char *firstadd_savein_n;

	index = 0;
	printf("save in n is %s\n", save_in_n);
	firstadd_savein_n = save_in_n;
	while(*save_in_n != '\n' && *save_in_n != '\0')
		save_in_n = save_in_n + 1;
	if(*save_in_n == '\0')
		return NULL;
	save_in_n = save_in_n + 1;
	mallocsize_next = ft_strlen(save_in_n) + 1;
	printf("mallocsize_next is > %d\n", mallocsize_next);
	save_notin_n = (char *)malloc(sizeof(char) * mallocsize_next);
	while(save_in_n[index] != '\0')
	{
		save_notin_n[index] = save_in_n[index];
		index = index + 1;
	}
	save_notin_n[index] = '\0';
	printf("\nrestore word is > %s\n", save_notin_n);
	free(firstadd_savein_n);
	return save_notin_n;
}

char *ft_get_next_line(int fd_num)
{
	char *line;
	static char *save = "";

	printf("this is clear!>> %s\n","insertcheck");
    save = ft_save_gnl(fd_num, save);
	printf("save is clear!>> %s\n",save);
	printf("this is clear!>>>>>> %s\n","insertcheck");
	line = ft_prepareline(save);
	printf("line is clear!>>>>>>>>>>>>> %s\n","insertcheck");
	save = ft_preparenextline(save);

	return (line);
}

int main()
{
    int buff_size;
    char *line;
	int fd;

    buff_size = 3;
    fd = open("new.txt", O_RDONLY);
    line = ft_get_next_line(fd);
	printf("first line is ==>> %s\n", line);
	printf(" %s\n", "^^^^^^^^^^^^^^^^^^^^^^^");
	line = ft_get_next_line(fd);
	printf("second line is ==>> %s\n", line);
	printf(" %s\n", "^^^^^^^^^^^^^^^^^^^^^^^");
	line = ft_get_next_line(fd);
	printf("third line is ==>> %s\n", line);
	printf(" %s\n", "^^^^^^^^^^^^^^^^^^^^^^^");
	line = ft_get_next_line(fd);
	printf("forth line is ==>> %s\n", line);
	printf(" %s\n", "^^^^^^^^^^^^^^^^^^^^^^^");
	line = ft_get_next_line(fd);
	printf("fifth line is ==>> %s\n", line);
	printf(" %s\n", "^^^^^^^^^^^^^^^^^^^^^^^");
}