#include "../../includes/cub3D.h"

int file_exists(char *filename)
{
	int fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		printf(B_R" \n Error : File %s does not exist\n\n"RESET, filename);
		return 0;
	}
	else
	{
		printf(B_Y" [File] %s %sexists\n"RESET, filename, B_G);
		close(fd);
		return 1;
	}
}
