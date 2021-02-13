#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<strings.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/mman.h>
// ./bin_del <file> <position> <del_size>
int main(int argc,char** argv)
{
	struct stat st;
	bzero(&st,sizeof(st));
	stat(argv[1],&st);
	int old_len = (int)st.st_size;
	printf("%s %ld\n",argv[1],st.st_size);
	int fd=open(argv[1],O_RDWR);
	
	int position = atoi(argv[2]);
	
	char *del_size_str = argv[3];
	int del_size = atoi(del_size_str);

	int new_len = old_len - del_size;
	printf("del_size:%d\n", del_size);
	
	void *start = mmap(NULL, old_len, PROT_READ | PROT_WRITE , MAP_SHARED, fd, 0);
	
	int end_len = old_len - position - del_size;
	char * temp_mem = calloc(end_len, sizeof(char));
	memcpy(temp_mem, start +  position + del_size, end_len);
	
	memcpy(start + position, temp_mem, end_len);
//	memcpy(start + position + strlen(insert_str), temp_mem, end_len);
	
	munmap(start, old_len);
	
	ftruncate(fd,new_len);
    bzero(&st,sizeof(st));
	stat(argv[1],&st);
	printf("%s %ld\n",argv[1],st.st_size);

	close(fd);
	return 0;
}
