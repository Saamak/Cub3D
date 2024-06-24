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
	char	**data;
	int		NO;
	int		SO;
	int		WE;
	int		EA;
	int		C;
	int		F;
}				t_map;

typedef struct s_texture
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*F;
	char	*C;
	int 	rgb_f;
	int 	rgb_c;
	int		bool_rgb;
}				t_texture;

typedef struct map_core
{
	int			first_data;
	t_map		*map;
	t_texture	*texture;
}			t_core;


//Input_verifs
int		file_exists(char *filename);
int		first_checks_hub(int ac, char **av, t_core *core);
void	get_map_path(char *path, t_core *c);

//Parsing
void	read_hub(t_core *c);
void	take_map_data(t_core *c);
void	is_textures(char *line, t_core *c);
void	is_colors(char *line, t_core *c);

//Init
t_core	*init_core(t_core *core);

//print
void	print_map(char **map);
void	print_texture(t_core *c);

//utils
char	**ft_split(char *s, char c, t_map *map);
char	*ft_substr(char *s, int start, int len);
char	**splitt(char *s, char c);

//free
void	free_map(t_map *map);
void	free_parsing(t_core *c);
void	free_tab(char **tab);
void	ft_exit(t_core *c);

#endif
