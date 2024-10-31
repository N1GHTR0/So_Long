#include "so_long.h"

void	pce_control(char **map)
{
	int	i;
	int	j;
	int	pl_count;
	int	ex_count;
	int	c_count;

	i = 0;
	pl_count = 0;
	ex_count = 0;
	c_count = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'P')
				pl_count++;
			if (map[i][j] == 'E')
				ex_count++;
			if (map[i][j] == 'C')
				c_count++;
			j++;
		}
		i++;
	}
	if (pl_count != 1 || ex_count != 1 || c_count == 0)
	{
		write(1, "pce count error!\n", 17);
		freemap(map);
		exit(1);
	}
}

void	is_square(char **map)
{
	int	i;
	int	cont;

	i = 1;
	cont = ft_strlen(map[0]);
	while (map[i] != NULL)
	{
		if (cont != ft_strlen(map[i]))
		{
			freemap(map);
			ft_putstr("map is not a square\n");
			exit(1);
		}
		i++;
	}
}

void	is_acceptable(char **map)
{
	int	x;
	int	y;

	x = map_height(map);
	y = map_lenght(map);
	if (!((x >= 3 && y >= 5) || (x >= 5 && y >= 3)))
	{
		freemap(map);
		ft_putstr("map isn't enouhgt big");
		exit(1);
	}
}
int	collectible_counter(char **map)
{
	int	i;
	int	j;
	int	counter;


	i = 0;
	counter = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'C')
				counter++;
			j++;
		}
		i++;
	}
	return (counter);
}
