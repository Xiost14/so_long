
#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

typedef struct s_data	t_data;
struct			s_data
{
	int		len_y;
	int		len_x;
	char	**map_done;
};

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
void    ft_exit(t_data *data);

#endif