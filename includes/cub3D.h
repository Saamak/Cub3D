#ifndef CUB3D_H
# define CUB3D_H
# include <math.h>
# include <stdio.h>
# include "libft.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define R   "\x1B[31m"
# define G   "\x1B[32m"
# define Y   "\x1B[33m"
# define B_R   "\x1B[1;31m"
# define B_G   "\x1B[1;32m"
# define B_Y   "\x1B[1;33m"
# define BOLD "\x1B[1m"
# define RESET "\x1B[0m"

typedef struct s_map
{
	int		error;
	int		fd;
	int		i;
	char	*map_path;
	char	**map;
}				t_map;

typedef struct s_texture
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}				t_texture;

typedef struct map_core
{
	t_map		*map;
	t_texture	*texture;
}			t_core;


//Input_verifs
int 	file_exists(char *filename);
int	first_checks_hub(int ac, char **av, t_core *core);
void	get_map_path(char *path, t_map *game);

//Parsing
void	read_map(t_core *core);

//Init
t_core	*init_core(t_core *core);

//print
void	print_map(char **map);

//utils
char	**ft_split(char *s, char c, t_map *map);
char	*ft_substr(char *s, int start, int len);

//free
void	free_map(t_map *map);

#endif
