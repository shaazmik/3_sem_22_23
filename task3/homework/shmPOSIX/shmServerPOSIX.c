// C program for Consumer process illustrating
// POSIX shared-memory API.
// monitor it using ipcs
// lsof -p 16894
// fuser some-huge-file.txt
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>

const char* name = "HESOYAM";

#define DEFAULT_SIZE 65536

#ifdef SMALL_SIZE
#define SIZE 4097
#endif

#ifdef MEDIUM_SIZE
#define SIZE 104857601
#endif

#ifdef LARGE_SIZE
#define SIZE 2147483649
#endif


int main()
{
    sleep(0,0001);

    int shm_fd = -1;
 
    void* ptr = NULL;
 

    shm_fd = shm_open(name, O_RDONLY, 0666);
 
    ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
    
    if(ptr == MAP_FAILED)
    {
        perror("mmap");
        exit(1);
    }


    shm_unlink(name);
    return 0;
}