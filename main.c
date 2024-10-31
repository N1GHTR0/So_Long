#include "so_long.h"
#include <stdio.h>

int	close_everth(data_t *win)
{
	int i;

	i = 0;
	while (win->map[i] != NULL)
	{
		free(win->map[i]);
		i++;
	}
	free(win->map);
	mlx_destroy_image(win->mlx, win->player_img);
	mlx_destroy_image(win->mlx, win->exit_img);
	mlx_destroy_image(win->mlx, win->ground_img);
	mlx_destroy_image(win->mlx, win->wall_img);
	mlx_destroy_image(win->mlx, win->coll_img);
	mlx_destroy_window(win->mlx, win->window);
	free(win);
	exit(1);
	return (1);
}

void	control_sum1(char *f_name)
{
	is_xpm_exist();
	dotber_check(f_name);
	is_file_exist(f_name);
}

void	control_sum2(char **map, char *f_name)
{
	is_possible(map, f_name);
	write(1, "1", 1);
	wall_control(map);
	write(1, "2", 1);
	pce_control(map);
	write(1, "3", 1);
	is_square(map);
	write(1, "4", 1);
	is_acceptable(map);
}


int	main(int argc, char **argv)
{
	char	**map;
	data_t	*dat;

	if (argc == 2)
	{
		control_sum1(argv[1]);
		map = get_map(argv[1]);
		control_sum2(map, argv[1]);
		dat = get_data(map, map_height(map), map_lenght(map));
		render_map(dat);
		mlx_hook(dat->window, 2, (1L << 0), move, dat);
		mlx_hook(dat->window, 17, 0L, close_everth, dat);
		mlx_loop(dat->mlx);
	}
	else
		ft_putstr("argument format is wrong");
	return (0);
}
