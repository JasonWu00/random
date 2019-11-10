#include <stdio.h>
#include <stdlib.h>

#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
//errno.h and string.h needed due to using wsl to bypass dev/urandom not existing on native Windows

int writeOneInteger() {
  int fd_input = open("/dev/urandom", O_RDONLY, 0);
  printf("Error message if any: %d: %s\n", errno, strerror(errno));
  return 0;
}
