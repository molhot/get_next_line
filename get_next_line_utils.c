#include "get_next_line.h"

char    *ft_strchr(const char (*s), int c)
{
    char    src;
    char    *s_2;
    int     num;

    s_2 = (char *)s;
    num = ft_strlen(s_2);
    src = (char)c;
    if (*s == '\0' && c == '\0')
    return ((char *)s);
    if (c == '\0')
        return (s_2 + num);
    while (num != 0)
    {
        if ((unsigned char)*s_2 == (unsigned char)src)
            return (s_2);
        num = num - 1;
        s_2 = s_2 + 1;  
    }
    return (NULL);
}

static	char	*input_char(const char (*insert), char (*inserted))
{
	char	*first_address;

	while ((*insert) != '\0')
	{
		*inserted = *insert;
		insert = insert + 1;
		inserted = inserted + 1;
	}
	return (inserted);
}

char	*ft_strdup(const char *s)
{
	int		len;
	char	*src_sub;

	len = ft_strlen(s);
	src_sub = (char *)malloc(sizeof(char) * (len + 1));
	if (src_sub == NULL)
		return (NULL);
	while ((*s) != '\0')
	{
		*src_sub = *s;
		s = s + 1;
		src_sub = src_sub + 1;
	}
	*src_sub = '\0';
	return (src_sub);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*dust;
	char	*dust_first;

	if ((s1 == NULL) && (s2 == NULL))
		return (NULL);
	if (s1 == NULL)
	{
		return (ft_strdup(s2));
		printf("%s", "hello");
	}
	if (s2 == NULL)
		return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	dust = (char *)malloc(sizeof(char) * len);
	if (!(dust))
		return (NULL);
	dust_first = dust;
	dust = input_char(s1, dust);
	dust = input_char(s2, dust);
	*dust = '\0';
	return (dust_first);
}

size_t	ft_strlen(const char (*string_row))
{
	size_t	counter;

	counter = 0;
	while ((*string_row) != '\0')
	{
		counter = counter + 1;
		string_row = string_row + 1;
	}
	return (counter);
}

void	ft_bzero(void *str, size_t n)
{
	char	*str_remake;

	str_remake = (char *)str;
	while (n != 0)
	{
		*str_remake = '\0';
		str_remake = str_remake + 1;
		n = n - 1;
	}
}

/*
int main()
{
	char *test;

	test = ft_strchr("aaaaaaaa", '\n');
	printf("%s", test);
}
*/