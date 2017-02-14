#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int fd;
	char **line;
	int a = 0;

	fd = open(argv[1], O_RDONLY);
	line = NULL;
	while (a = get_next_line(fd, line) != 0)
	{
		get_next_line(fd, line);
		a++;
		ft_putchar('\n');
	}
	return (0);
}
