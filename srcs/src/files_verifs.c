#include "../../includes/cub3D.h"

int file_exists(char *filename)
{
	int fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		printf(B_R"   | Error : File %s does not exist \u274c \n\n"RESET, filename);
		printf(BOLD"\n\n-----------------------------------------------\n"RESET);
		return (0);
	}
	else
	{
		printf(B_G"   |File %s exists \xE2\x9C\x93 \n\n"RESET, filename);
		close(fd);
		return 1;
	}
}
