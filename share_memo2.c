#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <sys/shm.h>
#include <sys/ipc.h>
#define LEN 50 


#define SHM_KEY 0x4321

int main(int argc, char* argv[])
{
    char *buff;

    int ret;

    int shm_id = shmget(SHM_KEY,4096, IPC_CREAT | 0666);

    if(shm_id == -1)
    {
        exit(-1);
    }
    buff = shmat(shm_id,0,0);

    printf("%s\n",buff);

    ret = shmdt(buff);
    if(ret ==0)
    {
        printf("Memory dettached\n");
    }
    return 0;
    
}