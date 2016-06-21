#include <fcntl.h>    
#include <unistd.h>
#include <stdio.h>

int main(){

    int fd = dup(1);

	unlink("./a.txt");

	 int fd2 = open("./a.txt",O_RDWR|O_APPEND|O_CREAT,0777);
    
	dup2(fd2,1);

	close(fd2);
	printf("write to file\n");

	//syncfs(1);
	fflush(stdout);

	dup2(fd,1);

//	close(1);
       
	//dup(fd);
	

	printf("write to terminal\n");

	close(fd);

	 return 0;
}
