#include "get_next_line.h"

char    *ft_strchr(const char (*s), int c)
{
    size_t     num;

	if(s == NULL)
		return (NULL);
	num = 0;
    while (s[num] != '\0')
    {
        if ((unsigned char)s[num] == (unsigned char)c)
            return ((char *)s + num);
        num = num + 1;
    }
    return (NULL);
}

size_t	ft_strlcat(char *dst, char *src, size_t final_dst_size)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (dst == NULL && final_dst_size == 0)
		return (src_len);
	dst_len = ft_strlen(dst);
	if (final_dst_size == 0)
		return (src_len);
	if (dst_len < final_dst_size)
	{
		i = 0;
		while (src[i] != '\0' && i < final_dst_size - dst_len - 1)
		{
			dst[dst_len + i] = src[i];
			i++;
		}
		dst[dst_len + i] = '\0';
		return (src_len + dst_len);
	}
	return (src_len + final_dst_size);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t cpysize)
{
	size_t	i;

	if (cpysize)
	{
		i = 0;
		while (src[i] != '\0' && i < cpysize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
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
	src_sub = src_sub - len;
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
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	dust = (char *)malloc(sizeof(char) * len);
	if (!(dust))
		return (NULL);
	dust_first = dust;
	ft_strlcpy(dust, s1, ft_strlen(s1) + 1);
	ft_strlcat(dust, (char *)s2, len);
	free((char *)s1);
	return (dust_first);
}

size_t	ft_strlen(const char (*string_row))
{
	size_t	counter;

	counter = 0;
	while (*string_row != '\0')
	{
		counter = counter + 1;
		string_row = string_row + 1;
	}
	return (counter);
}
