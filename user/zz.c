#include "kernel/types.h"
#include "kernel/pstat.h"
#include "user/user.h"

#define CHILDREN 3

int
main(int argc, char *argv[])
{
  printf("TESTEEEEEEE!!!");
  int sec;
  int child[CHILDREN];
  struct pstat pinfo;
  int i, j;

  if (argc < 2) {
    fprintf(2, "Usage: lottery seconds\n");
    exit(1);
  }

  sec = atoi(argv[1]);
  if (sec <= 0) {
    fprintf(2, "lottery: seconsd must be a positive integer\n");
    exit(1);
  }

  for (i = 0; i < CHILDREN; i++) {
    child[i] = fork();
    if (child[i] < 0) {
      exit(1);
    }
    if (child[i] == 0) {
      settickets((i + 1) * 10);
      while (1);
    } else {
      printf("Child %d has PID %d\n", i, child[i]);
    }
  }

  printf("Sleeping for %d seconds\n", sec);
  sleep(10 * sec);

  getpinfo(&pinfo);
  for (i = 0; i < NPROC; i++) {
    for (j = 0; j < CHILDREN; j++) {
      if (pinfo.pid[i] == child[j]) {
        printf("%d: %d\n", j + 1, pinfo.ticks[i]);
        kill(child[j]);
        wait(0);
        break;
      }
    }
  }

  exit(0);
}
