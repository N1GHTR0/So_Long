#include "so_long.h"

data_t	*get_data(char **w_map, int x, int y)
{
	data_t	*inf;

	inf = malloc(sizeof(data_t));
	inf->window_hei = map_height(w_map) * 64;
	inf->window_len = map_lenght(w_map) * 64;
	inf->coll_num = collectible_counter(w_map);
	inf->score = 0;
	inf->map = w_map;
	inf->mlx = mlx_init();
	inf->window = mlx_new_window(inf->mlx, inf->window_len, inf->window_hei, "so_long");
	inf->player_img = mlx_xpm_file_to_image(inf->mlx, "./images/player.xpm", &y, &x);
	inf->exit_img = mlx_xpm_file_to_image(inf->mlx, "./images/exit.xpm", &y, &x);
	inf->ground_img = mlx_xpm_file_to_image(inf->mlx, "./images/ground.xpm", &y, &x);
	inf->wall_img = mlx_xpm_file_to_image(inf->mlx, "./images/wall.xpm", &y, &x);
	inf->coll_img = mlx_xpm_file_to_image(inf->mlx, "./images/collectible.xpm", &y, &x);
	return(inf);
}

void	put_score(data_t *win)
{
	char	*score;

	score = ft_itoa(win->score);
	mlx_string_put(win->mlx, win->window, 20, 20, 0xFFFFFFFF, score);
	free(score);
}

void	put_img(char c, data_t *win, int i, int j)
{
	if (c == '0')
		mlx_put_image_to_window(win->mlx, win->window, win->ground_img, i, j);
	else if (c == '1')
		mlx_put_image_to_window(win->mlx, win->window, win->wall_img, i, j);
	else if (c == 'C')
		mlx_put_image_to_window(win->mlx, win->window, win->coll_img, i, j);
	else if (c == 'E')
	{
		mlx_put_image_to_window(win->mlx, win->window, win->exit_img, i, j);
		win->exit_x = j / 64;
		win->exit_y = i / 64;
	}
	else if (c == 'P')
	{
		mlx_put_image_to_window(win->mlx, win->window, win->player_img, i, j);
		win->player_x = j / 64;
		win->player_y = i / 64;
	}
}

void	render_map(data_t *win)
{
	int	i;
	int	j;
	int	x;
	int	y;

	x = 0;
	j = 0;
	while (win->map[x] != NULL)
	{
		y = 0;
		i = 0;
		while (win->map[x][y] != '\0')
		{
			put_img(win->map[x][y], win, i, j);
			put_score(win);
			y++;
			i = i + 64;
		}
		x++;
		j = j + 64;
	}
}
