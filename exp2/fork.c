#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int main (int argc, char* argv[])
{
    int id, wt;
    id=fork();
    
    if(id==0)
    {
        printf("Hi, I am the child. My PID is %d.\n", getpid());
        printf("Child: my parent's PID is %d.\n",getppid());
        execl("./app", "app", argv[1], NULL);
        exit(42);
    }
    else if (id>0)
    {
        wait(&wt);
        printf("Hi, I am the parent. My PID is %d.\n", getpid());
        printf("Parent: my parent's PID is %d.\n", getppid()); //This is that bash PID.
        
        if (WIFEXITED(wt))
            printf("The child process has terminated normally and its exit status is %d\n", WEXITSTATUS(wt));
        else if (WIFSIGNALED(wt))
            printf("The child has terminated abnormally and was killed by signal %d \n.", WTERMSIG(wt));
    }
    
}
