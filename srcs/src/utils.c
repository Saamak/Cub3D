#include "../../includes/cub3D.h"

int its_map(char *line)
{
	int i;

	i = 0;
	while (line[i] != '\0' || line[i] != '\n')
	{
		while(line[i] == ' ' || line[i] == '\t')
			i++;
		if (line[i] == '1')
		{
			printf(B_Y"   | Map found \xE2\x9C\x93 \n"RESET);
			return (1);
		}
		else
			return (0);
	}
	return (0);
}


int	count_word(char *s, char c)
{
	int	c_w;
	int	tmp;

	tmp = 0;
	c_w = 0;
	while (*s != '\0')
	{
		if (tmp == 1 && *s == c)
			tmp = 0;
		if (tmp == 0 && *s != c)
		{
			tmp = 1;
			c_w++;
		}
		s++;
	}
	return (c_w);
}

char	**splitt(char *s, char c)
{
	char	**dest;
	int		i;
	int		x;

	x = 0;
	if (!s)
		return (NULL);
	dest = malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!dest)
		return (NULL);
	while (*s)
	{
		if (s[0] == c)
			s++;
		else
		{
			i = 0;
			while (s[i] != '\0' && s[i] != c)
				i++;
			dest[x++] = ft_substr(s, 0, i);
			s = s + i;
		}
	}
	dest[x] = NULL;
	return (dest);
}

int str_len_modif(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}
