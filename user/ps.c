#include "kernel/types.h"
#include "kernel/pstat.h"
#include "user/user.h"

int
ps(void)
{
  int i;
  struct pstat pinfo;
  if(getpinfo(&pinfo) < 0){
    return -1;
  }
  printf("PID\t\tTICKETS\t\tTICKS\t\tINUSE\n");
  for(i = 0; i < NPROC; i++){
    if(pinfo.inuse[i]){
      printf("%d\t\t%d\t\t%d\t\t%d\n", pinfo.pid[i], pinfo.tickets[i], pinfo.ticks[i], pinfo.inuse[i]);
    }
  }
  return 0;
}

int
main(int argc, char *argv[])
{
  if(!ps())
    exit(1);
  exit(0);
}
