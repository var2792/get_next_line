#include "get_next_line.h"

int main(void)
{
	int n;
	int i;
	int j;
	int fd;
	char **ln = NULL;

	fd = open("file2.txt", O_RDWR);
	i = 0;
	n = 1;
	ln = malloc(sizeof(char*) * 5);
	while (n > 0)
	{
		n = get_next_line(fd, ln);
		printf("n = %i\n\n", n);
		i++;
	}
	printf("n = %i\n", n);
	j = 0;
	printf("\nall = %i\n", i);
	while (j < i)
	{
		printf("%i\t%s\n", j, ln[j]);
		j++;
	}
	close(fd);
}
