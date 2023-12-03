#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#define LEN 50 



int main(int argc, char* argv[])
{

    char buff[LEN];
    int ff = mkfifo("/tmp/mFifo", __S_IFIFO | 0666);
    
    int fif = open("/tmp/mFifo", O_RDONLY);

    while (1)
    {
        int ret = read(fif, buff, LEN);
        printf("Rcvd from parent: %s", buff);
    }
    
    close(fif);
    return 0;
}