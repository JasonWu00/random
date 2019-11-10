all: main.o dev_urandom.o
	gcc -o testfile main.o dev_urandom.o

main.o: main.c dev_urandom.h
	gcc -c main.c

dev_urandom.o: dev_urandom.c dev_urandom.h
	gcc -c dev_urandom.c

run:
	./testfile

clean:
	rm -rf *.o
	rm -rf testfile
