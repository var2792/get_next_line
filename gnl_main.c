#include "get_next_line.h"

int main(void)
{
	int n;
	int i;
	int j;
	int fd;
	static char **line = NULL;

	fd = open("file1.txt", O_RDWR);
	i = 0;
	n = 1;
	line = malloc(sizeof(char*) * 10);
	while (n > 0)
	{
		n = get_next_line(fd, &line[i]);
		printf("n = %i\t", n);
		printf("line = %s\n\n", line[i]);
		//line++;
		i++;
	}
	printf("n = %i\n", n);
	j = 0;
	printf("\nall = %i\n", i);
	while (j < i)
	{
		printf("%i\t%s\n", j, line[j]);
		j++;
	}
	close(fd);
}
