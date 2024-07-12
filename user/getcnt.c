
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[]) {
    if(argc<2) {
        printf("Usage: getcnt <syscallId>\n",1,4);
        exit(0);
    }
    int syscallId = atoi(argv[1]);
    int callTimes = getcnt(syscallId);
    printf("syscall %d has been called %d times\n",syscallId,callTimes);
    exit(0);
}