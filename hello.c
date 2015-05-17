#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>


int print_hello (void)
{
	printf("Hello go..\n");
}
void p (const char* str)
{
	printf("%s\n", str);
}

void write_demo(const char* str)
{
	int fd;
	// file opts
	char* fname = "./kii.txt";
	int fflags = O_CREAT | O_APPEND;
	mode_t fmode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
	// open
	errno = 0;
	fd = open(fname, fflags, fmode);
	if (fd == -1)
	{
		// err
		printf("E: file open err -> %s\n", strerror(errno));
		return;
	}
	printf("M: file opened with fd=%d\n", fd);
	// write
	ssize_t nr;
	errno = 0;
	nr = write(fd, str, strlen(str));
	if (nr == -1)
	{
		printf("E: file write err -> %s\n", strerror(errno));
	}

	// close
	if (close(fd) == -1)
	{
		printf("E: file close err\n");
		return;
	}
}




