# ifndef FT_GNL
#define FT_GNL

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
#endif

#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include <stdlib.h>
#include<fcntl.h>
# include <stdint.h>

char    *ft_strchr(const char (*s), int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char (*string_row));
char	*ft_strdup(const char *s1);
void	ft_bzero(void *str, size_t n);
char *get_next_line(int fd_num);
char *ft_save_gnl(int fd, char *save);
char	*ft_prepareline(char *save);
char *ft_preparenextline(char *save_in_n);

#endif



