all: main

main: main.o libmylib.so
	g++ -o main main.o -L./ -lmylib -Wl,-rpath,./

main.o: main.cpp
	g++ -c main.cpp

libmylib.so: mylib.o
	g++ -shared -o libmylib.so mylib.o

mylib.o: mylib.c
	gcc -c -fPIC mylib.c

clean:
	rm -f *.o *.so main
