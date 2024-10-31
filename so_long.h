#ifndef SO_LONG_H
# define SO_LONG_H

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
# include "./minilibx/mlx.h"

typedef struct str_s
{
	char *o_map;
	struct str_s *next;
} str_t;

typedef struct data_s
{
	char	**map;
	void	*mlx;
	void	*window;
	char	*player_img;
	char	*exit_img;
	char	*ground_img;
	char	*wall_img;
	char	*coll_img;
	int		window_hei;
	int		window_len;
	int		coll_num;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		score;

}	data_t;

int		find_digit(int x);
char	*ft_itoa(int x);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
void	wall_control(char **map);
void	is_xpm_exist(void);
void	dotber_check(char *pt);
void	is_file_exist(char *pt);
void	find_position(int *x, int *y, char **map);
void	freemap(char **map);
void	is_poss(char **map, char **cont_map, int px, int py);
void	is_possible(char **map, char *file_name);
void	pce_control(char **map);
void	is_square(char **map);
void	is_acceptable(char **map);
int		collectible_counter(char **map);
data_t	*get_data(char **w_map, int x, int y);
void	put_score(data_t *win);
void	put_img(char c, data_t *win, int i, int j);
void	render_map(data_t *win);
void	write_score(int score);
void	ket_move(data_t *win, int keymove, int x, int y);
int		move(int movkey, data_t *win);
int		get_xlen(char *file_name);
char	**get_map(char *file_name);
int		map_height(char **map);
int		map_lenght(char **map);
int		close_everth(data_t *win);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char *str, char c);
char	*get_line(int fd);

#endif
