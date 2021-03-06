#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include <fcntl.h>


// usage() prints a standard usage statement
void usage(char *path) {
    fprintf(stderr, "Usage: %s -n NAME\n", path);
}

int main(int argc, char *argv[])
{
	char *name;
	char hostname[1024]; 
	gethostname(hostname, 1024);
	int pid = getpid();
	int ppid = getppid();
	//Assignment should probably be using cwd, but it only requires argv[0]
	char cwd [1024];
	getcwd(cwd, sizeof(cwd));	

	if (argc != 3)
	{
		usage(argv[0]);
		exit(1);
	}
	
	// read the input parameter and exit on error
	int c;
	opterr = 0;
	while ((c = getopt(argc, argv, "n:")) != -1) 
	{
		switch (c) 
		{
			case 'n':
				name = optarg;
				break;
			default:
				usage(argv[0]);
				exit(1);
		}
	}
	
	// output on STDOUT "Welcome to Lab 1, written by USERNAME"
	printf("Welcome to Lab 1, written by %s\n", name);

	// output on STDOUT "Hostname: <hostname>"
	printf("Hostname: %s\n", hostname); 

	// output on STDOUT "PID and PPID: nnnnn/nnnnn"
	printf("PID and PPID: %i/%i\n", pid, ppid);

	// output on STDOUT "Program: <pathToThisProgram>"	
	printf("Program: %s\n", argv[0]);
	
	return 0;
}

