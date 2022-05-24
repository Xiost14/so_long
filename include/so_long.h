
#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

# define FAIL 0
# define SUCCESS 1
# define ERROR -1
# define BUFFER_SIZE 1024
# define IMG_SIZE 48
# define GROUND "xpm/ground.xpm"
# define PLAYER "xpm/player.xpm"
# define EXIT "xpm/exit.xpm"
# define COIN "xpm/coin.xpm"
# define WALL "xpm/wall.xpm"

typedef struct s_data	t_data;
struct			s_data
{
	int		len_y;
	int		len_x;
	char	*str;

	char	**map_done;
	int		fd;
	int		line_len;
	int		line_count;
	char	*path_arg;
	int		i;
	int		j;
	int		player_y;
	int		player_x;
	int		count_p;
	int		count_e;
	int		count_c;
	int		collect;
	int		can_exit;
	int		steps_count;
	int		win_height;
	int		height;
	int		win_width;
	int		width;

	void	*mlx;
	void	*win;
	void	*wall;
	void	*exit;
	void	*coin;
	void	*player;
	void	*ground;
};
/*
//ft_utils
int	ft_strlen(char *str);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strjoin(char *left_str, char *buff);
char	*ft_strchr(char *str, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);

//map
int	map(int ac, char **av, t_data *data);

//ft_check_map
int		ft_check_map(char **map, int len_x, int len_y);

//ft_split
char	**ft_split(char const *s, char c);

//exit
void    ft_exit(t_data *data, char *str);
void    ft_putstr(char *str);
*/

//get_next_line
char	*get_next_line(int fd);

//check_arg
int	check_extention(char *arg);

//create_map
void    create_map(t_data *data, char *str_arg);

//ft_utils
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *str);
void	ft_free(char **tab);

//ft_utils_2
char	*ft_strchr(const char *s, int c);

//ft_error
void	ft_error(char *str, t_data *data);

//struct_init
void	struc_init(t_data *data);

//check_map
int	check_map(t_data *data);

//get_player
void	get_player(t_data *data);

//init_window
void	init_window(t_data *data);

//init_image
void	init_image(t_data *data);

#endif