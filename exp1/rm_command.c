#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    int output_fd = unlink(argv[1]);
    
    if(output_fd == -1)
    {
        perror("unlink error");
        return 3;
    }
}
