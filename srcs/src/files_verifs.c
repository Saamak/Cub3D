#include "../../includes/cub3D.h"

int file_exists(char *filename)
{
	int fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		printf(B_R" Error : File %s does not exist\n"RESET, filename);
		return 0;
	}
	else
	{
		close(fd);
		return 1;
	}
}
