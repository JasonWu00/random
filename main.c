#include <stdio.h>
#include <stdlib.h>

#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#include "dev_urandom.h"

int main() {
  umask(0);
  printf("Test\n");

  /* some testing code, now commented out
  int fd;
  fd = open("test_document.txt", O_RDWR|O_APPEND, 0);
  printf("Value of fd: %d\n", fd);
  char output[100];
  int err = read(fd, output, 54);
  printf("Error message (if there is one): %d: %s\n", errno, strerror(errno));
  printf("The string in question: \n%s\n", output);
  char insert[10] = "abcdefghi";
  //int err2 = write(fd, insert, 10);
  //printf("Second error message: %d: %s\n", errno, strerror(errno));
  char outputTwo[100];
  err = read(fd, outputTwo, 4);
  printf("Updated string: \n%s\n", outputTwo);
  */

  writeOneInteger();
}
