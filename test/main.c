#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
	printf("ok\n");
	int fd = open("./main.c", O_RDWR);
	int fd1 = open("./main.c", O_RDWR);
	printf("fd=%d,fd1=%d\n", fd, fd1);
	return 0;
}
