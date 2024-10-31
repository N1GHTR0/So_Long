/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahyilmaz <ahyilmaz@student.42.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 20:32:53 by ahyilmaz          #+#    #+#             */
/*   Updated: 2023/07/31 20:34:28 by ahyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = (char *)malloc(1);
		s1[0] = 0;
	}
	if (!s1 || !s2)
		return (NULL);
	s3 = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s3)
		return (NULL);
	i = -1;
	while (s1[++i] != 0)
		s3[i] = s1[i];
	j = -1;
	while (s2[++j] != 0)
	{
		s3[i + j] = s2[j];
	}
	s3[i + j] = 0;
	free(s1);
	return (s3);
}

char	*ft_read_map(int fd)
{
	int			rd_bytes;
	char		map[2];
	char		*value;

	value = NULL;
	rd_bytes = 1;
	while (rd_bytes != 0)
	{
		rd_bytes = read(fd, map, 1);
		map[rd_bytes] = '\0';
		value = ft_strjoin(value, map);
	}
	return (value);
}

char **get_map(char *file_name)
{
	int		fd;
	int		i;
	char	*tmp;
	char	**map;
	
	i = 0;
	fd = open(file_name, O_RDONLY);
	tmp = ft_read_map(fd);
	map = ft_split(tmp, '\n');
	free(tmp);
	close(fd);
	return (map);
}

int	map_height(char **map)
{
	int	h;

	h = 0;
	while (map[h] != NULL)
		h++;
	return (h);
}

int	map_lenght(char **map)
{
	int	l;

	l = 0;
	while (map[0][l] != '\n')
		l++;
	return (l);
}
