#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <libproc.h>

int main (int argc, char* argv[])
{
    int ret;
    int i;
    pid_t pid; 
    int errs = 0;
    char pathbuf[PROC_PIDPATHINFO_MAXSIZE];

    if ( argc < 1 ) {
      fprintf(stderr, "usage: pidpath <pid>\n");
    } else {
      for (i = 1; i < argc; i++) {
        pid = (pid_t) atoi(argv[i]);
        ret = proc_pidpath(pid, pathbuf, sizeof(pathbuf));
        if (ret <= 0) {
          fprintf(stderr, "pid %d: %s\n", pid, strerror(errno));
          errs = 1;
        }
        else {
          printf("%s\n", pathbuf);
        }
      }
    }

    return errs;
}
