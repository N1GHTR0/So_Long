#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int i;
	int j;
	char *str;

	i = 0;
	j = 0;
	if (s1 == NULL)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[j + i] = '\0';
	free(s1);
	return (str);
}

char	*get_line(int fd)
{
	char	*gnl_l;
	char	*buff;
	int	er_check;

	gnl_l = NULL;
	buff = malloc(2 * sizeof(char));
	if (!buff)
		return (NULL);
	er_check = 1;
	while (buff[0] != '\n' && er_check != 0)
	{
		er_check = read(fd, buff, 1);
		if (er_check == -1 || er_check == 0)
		{
			free(buff);
			return (NULL);
		}
		buff[er_check] = '\0';
		gnl_l = ft_strjoin(gnl_l, buff);
	}
	free(buff);
	return (gnl_l);
}

char	*mini_gnl(int fd)
{
	char	*line;

	if (fd < 0)
		return (0);
	line = get_line(fd);
	printf("%s", line);
	return (line);
}
int main()
{
	int fd = open("map", O_RDWR);
	while (mini_gnl(fd));
}
