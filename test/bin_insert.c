#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<strings.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/mman.h>
// ./bin_insert <file> <position> <insert_str>
int main(int argc,char** argv)
{
	struct stat st;
	bzero(&st,sizeof(st));
	stat(argv[1],&st);
	int old_len = (int)st.st_size;
	printf("%s %ld\n",argv[1],st.st_size);
	int fd=open(argv[1],O_RDWR);
	
	int position = atoi(argv[2]);
	
	char *insert_str = argv[3];
	
	int new_len = old_len + strlen(insert_str);
	printf("insert:%s,insert_len:%d\n", insert_str, strlen(insert_str));
	ftruncate(fd,new_len);
	
	bzero(&st,sizeof(st));
	stat(argv[1],&st);
	printf("%s %ld\n",argv[1],st.st_size);
	
	void *start = mmap(NULL, new_len, PROT_READ | PROT_WRITE , MAP_SHARED, fd, 0);
	
	int end_len = old_len - position;
	char * temp_mem = calloc(end_len, sizeof(char));
	memcpy(temp_mem, start +  position, end_len);
	
	memcpy(start + position, insert_str, strlen(insert_str));
	memcpy(start + position + strlen(insert_str), temp_mem, end_len);
	
	munmap(start, new_len);
	
	close(fd);
	return 0;
}