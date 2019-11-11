#include <stdio.h>
#include <stdlib.h>

#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

void printArray(int array[10]) {
  int counter = 0;
  for (counter = 0; counter < 10; counter++) {
    printf("random %i: %i\n", counter+1, array[counter]);
  }
}


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

  int arrayOfInts[10];
  int fd_urandom = open("/dev/urandom", O_RDONLY, 0);
  printf("Error message for opening urandom, if any: %d: %s\n", errno, strerror(errno));
  int fd_randomIntegers = open("random_integers.txt", O_RDWR | O_CREAT, 0);
  printf("Error message for opening random integer textfile, if any: %d: %s\n", errno, strerror(errno));

  int middleMan = 0;
  int counter = 0;
  for (counter = 0; counter < 10; counter++) {
    int err = read(fd_urandom, &middleMan, sizeof(int));
    //printf("Error message if any: %d: %s\n", errno, strerror(errno));
    //printf("The random number pulled: %i\n", middleMan);
    arrayOfInts[counter] = middleMan;
  }
  printf("Printing random numbers extracted from urandom below.\n");
  printArray(arrayOfInts);

  close(fd_randomIntegers);
  fd_randomIntegers = open("random_integers.txt", O_RDWR, 0);

  int errTwo = write(fd_randomIntegers, &arrayOfInts, sizeof(arrayOfInts));
  printf("Error message for writing to random integers textfile, if any: %d, %s\n", errno, strerror(errno));
  printf("DEBUG: size of an int: %li\n", sizeof(int));

  int outputArray[10];
  int errThree = read(fd_randomIntegers, &outputArray, sizeof(outputArray));
  printf("Error message for copying to array, if any: %d, %s\n", errno, strerror(errno));
  printf("Now printing the array with the integers copied from the textfile:\n");
  printArray(outputArray);
  return 0;
}
