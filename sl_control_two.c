#include "so_long.h"

void	is_file_exist(char *pt)
{
	int	fd;

	fd = open(pt, O_RDWR);
	if (fd <= 0)
	{
		write(1, "file is not exist\n", 18);
		close(fd);
		exit(1);
	}
	close(fd);
}

void	find_position(int *x, int *y, char **map)
{
	*x = 0;
	*y = 0;
	while (map[*x] != NULL)
	{
		while (map[*x][*y] != '\0')
		{
			if (map[*x][*y] == 'P')
				return ;
			(*y)++;
		}
		(*x)++;
	}
}

void	freemap(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
void	is_poss(char **map, char **cont_map, int px, int py)
{
	cont_map[px][py] = 'x';
	if (map[px][py - 1] != '1' && cont_map[px][py - 1] != 'x')
		is_poss(map, cont_map, px, py - 1);
	if (map[px][py + 1] != '1' && cont_map[px][py + 1] != 'x')
		is_poss(map, cont_map, px, py + 1);
	if (map[px - 1][py] != '1' && cont_map[px - 1][py] != 'x')
		is_poss(map, cont_map, px - 1, py);
	if (map[px + 1][py] != '1' && cont_map[px + 1][py] != 'x')
		 is_poss(map, cont_map, px + 1, py);
}

void is_possible(char **map, char *file_name)
{
	char	**cont_map;
	int	px;
	int	py;

	find_position(&px, &py, map);
	cont_map = get_map(file_name);
	is_poss(map, cont_map, px, py);
	px = 0;
	py = 0;
	while (cont_map[px] != NULL)
        {
                while (cont_map[px][py] != '\0')
                {
                        if (cont_map[px][py] != '1' && cont_map[px][py] != 'x')
			{
				freemap(map);
				freemap(cont_map);
				exit(write(1, "wrong map format\n", 17));
			}
                        py++;
                }
                px++;
        }
	freemap(cont_map);
}
