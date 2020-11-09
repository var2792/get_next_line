#include "get_next_line.h"

int main(void)
{
	int i;
	int fd;
	int n;
	char *s;
	i = 0;
	//fd = 0;
	fd = open("file0", O_RDWR);
	//fd = open("test9", O_RDWR);
	n = 1;
	while (n > 0)
	{
		n = get_next_line(fd, &s);
		printf("%i\t%i\t|%s|\n", i++, n, s);
		//free(s);
	}
	close(fd);
}
/*
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=1 get_next_line.c get_next_line_utils.c gnl_main.c get_next_line.h && clear && ./a.out
 
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=2 get_next_line.c get_next_line_utils.c gnl_main.c get_next_line.h && clear && ./a.out

gcc -Wall -Wextra -Werror -D BUFFER_SIZE=5 get_next_line.c get_next_line_utils.c gnl_main.c get_next_line.h && clear && ./a.out

gcc -Wall -Wextra -Werror -D BUFFER_SIZE=10 get_next_line.c get_next_line_utils.c gnl_main.c get_next_line.h && clear && ./a.out

gcc -Wall -Wextra -Werror -D BUFFER_SIZE=100 get_next_line.c get_next_line_utils.c gnl_main.c get_next_line.h && clear && ./a.out

gcc -Wall -Wextra -Werror -D BUFFER_SIZE=9999 get_next_line.c get_next_line_utils.c gnl_main.c get_next_line.h && clear && ./a.out

gcc -Wall -Wextra -Werror -D BUFFER_SIZE=10000000 get_next_line.c get_next_line_utils.c gnl_main.c get_next_line.h && clear && ./a.out
 
 
 
gcc -fsanitize=address -fno-omit-frame-pointer -D BUFFER_SIZE=1 get_next_line.c get_next_line_utils.c gnl_main.c get_next_line.h && clear && ./a.out

gcc -fsanitize=address -fno-omit-frame-pointer -D BUFFER_SIZE=2 get_next_line.c get_next_line_utils.c gnl_main.c get_next_line.h && clear && ./a.out

gcc -fsanitize=address -fno-omit-frame-pointer -D BUFFER_SIZE=10 get_next_line.c get_next_line_utils.c gnl_main.c get_next_line.h && clear && ./a.out

gcc -fsanitize=address -fno-omit-frame-pointer -D BUFFER_SIZE=200 get_next_line.c get_next_line_utils.c gnl_main.c get_next_line.h && clear && ./a.out
*/
