#include "so_long.h"

void	wall_control(char **map)
{
	int	i;
	int	x;
	int	y;

	x = map_height(map);
	y = map_lenght(map);
	i = 0;
	while (map[0][i] != '\0')
	{
		if (map[0][i] != '1' || map[x][i] != '1')
		{
			ft_putstr("The wall structure on the map is broken!\n");
			freemap(map);
			exit(1);
		}
		i++;
	}
	i = 1;
	while (i < x)
	{
		if (map[i][0] != '1' || map[i][y] != '1')
		{
			ft_putstr("The wall structure on the map is broken!\n");
			freemap(map);
			exit(1);
		}
		i++;
	}
}

void	is_xpm_exist(void)
{
	int	fd_p;
	int	fd_e;
	int	fd_g;
	int	fd_w;
	int	fd_c;

	fd_p = open("./images/player.xpm", O_RDWR);
	fd_e = open("./images/exit.xpm", O_RDWR);
	fd_g = open("./images/ground.xpm", O_RDWR);
	fd_w = open("./images/wall.xpm", O_RDWR);
	fd_c = open("./images/collectible.xpm", O_RDWR);
	if (fd_p <= 0 || fd_e <= 0 || fd_g <= 0 || fd_w <= 0 || fd_c <= 0)
	{
		write(1, "Missing xpm file\n", 18);
		close(fd_p);
		close(fd_e);
		close(fd_g);
		close(fd_w);
		close(fd_c);
		exit(1);
	}
	close(fd_p);
	close(fd_e);
	close(fd_g);
	close(fd_w);
	close(fd_c);
}

void	dotber_check(char *pt)
{
	int	x;

	x = 0;
	while (pt[x] != '\0')
		x++;
	if (pt[x - 1] != 'r' || pt[x - 2] != 'e'
			|| pt[x - 3] != 'b' || pt[x - 4] != '.')
	{
		write(1, "wrong file extension", 21);
		exit(1);
	}
}
