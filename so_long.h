
#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct s_data	t_data;
struct			s_data
{
	int		len_y;
	int		*len_x;
	char	**map_done;
};

//ft_utils
int	ft_strlen(char *str);
int	ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);

//map
int	map(int ac, char **av, t_data *data);


#endif