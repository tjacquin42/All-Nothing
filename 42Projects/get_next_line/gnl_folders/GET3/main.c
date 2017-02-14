#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int fd;
	char **line;
	int a = 1;

	fd = open(argv[1], O_RDONLY);
	line = NULL;
	while (a != 0)
	{
		a = get_next_line(fd, line);
		//printf("\nLINE:%s", line);
	}
	return (0);
}
