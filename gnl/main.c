#include <stdio.h>
#include "get_next_line_bonus.h"

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
int main (int argc,char **argv)
{
	char *line;
	argc = 1;
	int fd = open(argv[1], O_RDONLY);
	int i;
	int j;

	j = 0;
	while ((i = get_next_line(fd,&line)) == 1)
	{
		printf("%d --->> %s\n", j++, line);
		free(line);
	}
	close(fd);
	printf("%d",i);
	return (0);
}
