#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>

int main(void) 
{
	char* str;
	int fd = open("test_a.txt", O_RDONLY);

	while ((str = get_next_line(fd)))
	{
		printf("%s", str);
		free(str);
	}		
//	while (1){}
}
