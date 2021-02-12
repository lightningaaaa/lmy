#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<strings.h>
#include<stdio.h>
#include<stdlib.h>
int main(int argc,char** argv)
{
	struct stat st;
	bzero(&st,sizeof(st));
	stat(argv[1],&st);
	printf("%s %ld\n",argv[1],st.st_size);
	int fd=open(argv[1],O_RDWR);
	int new_len = atoi(argv[2]);
	ftruncate(fd,new_len);
	bzero(&st,sizeof(st));
	stat(argv[1],&st);
	printf("%s %ld\n",argv[1],st.st_size);
	close(fd);
	return 0;
}