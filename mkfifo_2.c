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
    int fif = open("/tmp/mFifo", O_WRONLY);

    while (1)
    {
        char *str = fgets(buff,LEN,stdin);

        if(str == NULL)
        {
            break;
        }
        int ret = write(fif, buff, LEN);
    }
    close(fif);
    return 0;
}