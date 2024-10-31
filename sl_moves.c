#include "so_long.h"

void	write_score(int score)
{
	char *sc;

	sc = ft_itoa(score);
	ft_putstr(sc);
	ft_putstr("\n");
	free(sc);
}

void	key_move(data_t *win, int x, int y)
{
	if (win->map[x][y] == '1' ||
			(win->map[x][y] == 'E' && win->coll_num != 0))
		return ;
	win->score = win->score + 1;
	write_score(win->score);
	if (win->map[x][y] == 'E' && win->coll_num == 0)
	{
		ft_putstr("You win!\n");
		close_everth(win);
	}
	if (win->map[x][y] == 'C')
		win->coll_num = win->coll_num - 1;
	win->map[win->player_x][win->player_y] = '0';
	win->map[x][y] = 'P';
	win->player_x = x;
	win->player_y = y;
}

int	move(int movkey, data_t *win)
{
	int x;
	int y;

	x = win->player_x;
	y = win->player_y;
	mlx_clear_window(win->mlx, win->window);
	if (movkey == 2)
		key_move(win, x, y + 1);
	if (movkey == 0)
		key_move(win, x, y - 1);
	if (movkey == 13)
		key_move(win, x - 1, y);
	if (movkey == 1)
		key_move(win, x + 1, y);
	if (movkey == 53)
		close_everth(win);
	render_map(win);
	return (movkey);
}
