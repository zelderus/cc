#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int print_hello (void)
{
	printf("Hello go..\n");
}
void p (char* str)
{
	printf("%s", str);
}

void write_demo(char* str)
{
	int fd;
	// file opts
	char* fname = "kii.txt";
	int fflags = O_CREAT | O_APPEND;
	mode_t fmode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
	// open
	fd = open(fname, fflags, fmode);
	if (fd == -1)
	{
		// err
		printf("E: file open err");
		return;
	}
	// write
	

	// close
	if (close(fd) == -1)
	{
		printf("E: file close err");
		return;
	}
}




